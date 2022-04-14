#include "hardwareprofile.h"
#include "spi_devices.h"
#include "digout.h"

#define GPIO_BUZZER     MCP23X17_GPIO_12
#define GPIO_RETRO      MCP23X17_GPIO_13
#define GPIO_RELE1        MCP23X17_GPIO_14
#define GPIO_RELE2        MCP23X17_GPIO_15
#define GPIO_RELE3        MCP23X17_GPIO_16
#define GPIO_RELE5        MCP23X17_GPIO_2
#define GPIO_RELE7        MCP23X17_GPIO_4
#define GPIO_RELE8        MCP23X17_GPIO_5
#define GPIO_RELE9        MCP23X17_GPIO_6
#define GPIO_RELE10       MCP23X17_GPIO_7
#define GPIO_RELE11       MCP23X17_GPIO_8


#define SETBIT(map, bit, value) ((map & (~(1 << bit))) | (value << bit))
#define GETBIT(map, bit) ((map >> bit) & 1)

static int change_spi=1;
static uint16_t status_spi = 0;

void digout_update_retro(int val) {
    status_spi = SETBIT(status_spi, GPIO_RETRO, val);
    change_spi=1;
}

void digout_update_buzzer(int val) {
    status_spi = SETBIT(status_spi, GPIO_BUZZER, val);
    mcp23x17_set_gpio_register(exp_driver, MCP23X17_ADDR_1, status_spi);
    change_spi=0;
}

int digout_get_buzzer_level(void) {
    return GETBIT(status_spi, GPIO_BUZZER);
}

void digout_update_rele(digout_t output, int val) {
    val = val > 0;
    const size_t transform[] = {
        [DIGOUT_RELE1] = GPIO_RELE1, 
        [DIGOUT_RELE2] = GPIO_RELE2,
        [DIGOUT_RELE3] = GPIO_RELE3,
        [DIGOUT_RELE5] = GPIO_RELE5,
        [DIGOUT_RELE7] = GPIO_RELE7,
        [DIGOUT_RELE8] = GPIO_RELE8,
        [DIGOUT_RELE9] = GPIO_RELE9,
        [DIGOUT_RELE10] = GPIO_RELE10,
        [DIGOUT_RELE11] = GPIO_RELE11,
    };
    size_t i = transform[output];
    if (GETBIT(status_spi, i) != (val > 0)) {
        status_spi = SETBIT(status_spi, i, val);
        change_spi=1;
    }
    switch(output) {
        case DIGOUT_RELE4:
            DIGOUT_RELE4_LAT = val;
            break;
        case DIGOUT_RELE6:
            DIGOUT_RELE6_LAT = val;
            break;
        default:
            break;
    }

}


int digout_get(digout_t output) {
    switch(output) {
        case DIGOUT_RELE1:
            return GETBIT(status_spi, 0);
        case DIGOUT_RELE2 :
            return GETBIT(status_spi, 1);
        case DIGOUT_RELE3 :
            return GETBIT(status_spi, 2);
       case DIGOUT_RELE4 :
            return DIGOUT_RELE4_LAT;
        case DIGOUT_RELE5 :
            return GETBIT(status_spi, 4);
        case DIGOUT_RELE6 :
            return DIGOUT_RELE6_LAT;
        case DIGOUT_RELE7 :
            return GETBIT(status_spi, 6);
        case DIGOUT_RELE8 :
            return GETBIT(status_spi, 7);
        case DIGOUT_RELE9 :
            return GETBIT(status_spi, 8);
        case DIGOUT_RELE10 :
            return GETBIT(status_spi, 9);
        case DIGOUT_RELE11 :
            return GETBIT(status_spi, 10);
        default:
            break;
    }
    return 0;
}

void digout_period_check(void) {
    if (change_spi) {
        mcp23x17_set_gpio_register(exp_driver, MCP23X17_ADDR_1, status_spi);
        change_spi=0;
    }
}

uint16_t digout_get_status(void) {
    return status_spi;
}


void digout_clear_all (void) {
    status_spi=0;
    change_spi=1;
}