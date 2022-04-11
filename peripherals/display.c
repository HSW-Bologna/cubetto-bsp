#include <string.h>
#include <math.h>
#include <stdio.h>

#include "system.h"
#include "hardwareprofile.h"
#include "display.h"
#include "spi_devices.h"


void display_write_byte(unsigned char data, unsigned char iscommand) {
    HAP_DISP_DATA = (HAP_DISP_DATA & ~HAP_DISP_DATA_MASK) | data;
    HAP_DISP_CD = iscommand;
    HAP_DISP_WRITE = 0;
    HAP_DISP_READ = 1;
    HAP_DISP_CE = 0;
    //delay_us(1);
    // CD set-up time 100ns
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    HAP_DISP_CE = 1;
    HAP_DISP_WRITE = 1;
    // CD hold-time 10ns
    Nop();
}

unsigned char check_status() {
    HAP_DISP_DATA_TRIS = HAP_DISP_DATA_TRIS | HAP_DISP_DATA_MASK;
    Nop();
    HAP_DISP_CD = 1;
    HAP_DISP_WRITE = 1;
    HAP_DISP_READ = 0;
    HAP_DISP_CE = 0;
    
    // delay_us(1);
    // access time 150ns
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    
    unsigned char status = HAP_DISP_DATA_IN & HAP_DISP_DATA_MASK;
    HAP_DISP_CE = 1;
    HAP_DISP_READ = 1;
    HAP_DISP_DATA_TRIS = HAP_DISP_DATA_TRIS & ~HAP_DISP_DATA_MASK;
    
    //chek sta0 and sta1
     if ((status & 0x03) == 0x03)
        return 1;
    return 0;
}

unsigned char send_2B_cmd(unsigned char D1, unsigned char D2, unsigned char cmd) {
    //TODO check order of data MSB LSB
    //TODO check timeout

    while (!check_status());
    display_write_byte(D1, 0);
    while (!check_status());
    display_write_byte(D2, 0);
    while (!check_status());
    display_write_byte(cmd, 1);
    return 1;
}

unsigned char send_1B_cmd(unsigned char data, unsigned char cmd) {
    //TODO check timeout
    while (!check_status());
    display_write_byte(data, 0);
    while (!check_status());
    display_write_byte(cmd, 1);
    return 1;
}

unsigned char send_nodata_cmd(unsigned char cmd) {
    //TODO check timeout
    while (!check_status());
    display_write_byte(cmd, 1);
    return 1;
}

void set_address_pointer(unsigned int address) {
    send_2B_cmd((unsigned char)(address & 0xFF),(unsigned char)(address >> 8),0x24);
}

//NB in alto a sinistra
void set_graphic_home_address(unsigned int address)
{
    send_2B_cmd((unsigned char)(address & 0xFF),(unsigned char)(address >> 8),0x42);
}

void set_graphic_area(unsigned char columns)
{
    send_2B_cmd(columns,0x00,0x43);
}

void set_mode(unsigned char mode)
{
    //TODO non � chiaro se ci sono i dati o no
    //send_1B_cmd(0x00,mode);
    send_nodata_cmd(mode);
}

void set_display_mode(unsigned char mode)
{
    //TODO non � chiaro se ci sono i dati o no
    //send_1B_cmd(0x00,mode);
    send_nodata_cmd(mode);
}

void vram_data_write(unsigned char data,unsigned char increment)
{
    if(increment)  
        send_1B_cmd(data,0xC0);
    else
        send_1B_cmd(data,0xC4);
}

void init_display_driver() {
    HAP_DISP_RESET = 0;
    __delay_ms(1);
    HAP_DISP_RESET = 1;
//    DISP_LIGHT = 1;
    
    //mcp23x17_set_gpio_level(exp_driver, MCP23X17_ADDR_1, GPIO_RETRO, 1);
    set_mode(OR_MODE);
    set_display_mode(TEXT_OFF_GRAPHIC_ON);
    set_graphic_home_address(0x00);
    set_graphic_area(HW_COLUMNS);
}

// row 0-127
// columns 0-29
// data is 8 pizels in a row
void display_graphic_write(unsigned char row,unsigned char col,unsigned char data)
{
    unsigned int address = (unsigned int)row * HW_COLUMNS + (unsigned int)col;
    set_address_pointer(address);
    vram_data_write(data,0);
}

