#include "hardwareprofile.h"
#include "spi_devices.h"


#define GPIO_RETRO      MCP23X17_GPIO_13


void digout_update_retro(int val) {
    mcp23x17_set_gpio_level(exp_driver, MCP23X17_ADDR_1, GPIO_RETRO, val);
}