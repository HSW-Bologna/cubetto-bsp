#include "digin.h"
#include "hardwareprofile.h"
#include "spi_devices.h"
#include "gel/debounce/debounce.h"

static debounce_filter_t filter;
static uint16_t status = 0;



void digin_filter_init(void) {    
    debounce_filter_init(&filter);
}


int digin_get(digin_t digin) {
    mcp23x17_gpio_t transform[] = {       
        0,1,2,3,4,5,6,7,
    };
    
    switch(digin) {
        case DIGIN_IN1...DIGIN_IN8:
            return debounce_read(&filter, transform[digin]);
            
        case DIGIN_IN9:
            return DIGIN_IN6_PORT;
            break;
        case DIGIN_IN10:
            return DIGIN_IN7_PORT;
            break;
        
        default:
            return 0;
    }
}

int digin_take_reading(void) {
    unsigned int input=0;
    
    input = status;
    input |= DIGIN_IN6_PORT <<8;
    input |= DIGIN_IN7_PORT <<9;

    return debounce_filter(&filter, input, 5);
}


void digin_exp_take_reading(void) {
    uint16_t value = 0;
    mcp23x17_get_gpio_register(exp_driver, MCP23X17_ADDR_2, &value);
    status=value;
}

unsigned int digin_get_inputs(void) {
    return debounce_value(&filter);
}