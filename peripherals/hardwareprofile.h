#ifndef HARDWAREPROFILE_H_INCLUDED
#define HARDWAREPROFILE_H_INCLUDED


#include "system.h"


//  I/O pin definitions
#define HAP_INPUT_PIN  1
#define HAP_OUTPUT_PIN 0


//  I2C BUS
#define HAP_I2CLK      LATBbits.LATB4
#define HAP_I2CLK_TRIS TRISBbits.TRISB4

#define HAP_I2CDA_LAT  LATAbits.LATA8
#define HAP_I2CDA_PORT PORTAbits.RA8
#define HAP_I2CDA_TRIS TRISAbits.TRISA8

#define HAP_I2C_WP      LATEbits.LATE15
#define HAP_I2C_WP_TRIS TRISEbits.TRISE15


//  SPI DEVICE
#define HAP_SPI_HIGH 1
#define HAP_SPI_LOW  0


// SPI 1
#define HAP_CLK       LATFbits.LATF0     // 1 TOUCH & 2 I/O EXP 16b
#define HAP_CLK_TRIS  TRISFbits.TRISF0
#define HAP_DOUT      LATFbits.LATF1
#define HAP_DOUT_TRIS TRISFbits.TRISF1
#define HAP_DIN       PORTBbits.RB10
#define HAP_DIN_TRIS  TRISBbits.TRISB10

#define I2C_CLK HAP_CLK
#define I2C_CLK_TRIS HAP_CLK_TRIS
#define I2C_DATA_OUT HAP_DOUT
#define I2C_DATA_TRIS HAP_DOUT_TRIS
#define I2C_DATA_IN HAP_DIN
#define I2C_DATA_IN_TRIS HAP_DIN_TRIS



// IC TOUCH SCREEN
#define HAP_CS2       LATDbits.LATD6
#define HAP_CS2_TRIS  TRISDbits.TRISD6
#define HAP_BUSY      PORTBbits.RB11
#define HAP_BUSY_TRIS TRISBbits.TRISB11

// IC 2 x I/O EXPANDER 16 BIT
#define HAP_CS1      LATCbits.LATC9
#define HAP_CS1_TRIS TRISCbits.TRISC9



// # SPI 2 || 2xPT100 # 2xAD-PTC # 2xDA 0/10VDC ======================
#define SPI_2_SCK      LATAbits.LATA10
#define SPI_2_SCK_TRIS TRISAbits.TRISA10
#define SPI_2_SDO      LATBbits.LATB13
#define SPI_2_SDO_TRIS TRISBbits.TRISB13
#define SPI_2_SDI      PORTBbits.RB12
#define SPI_2_SDI_TRIS TRISBbits.TRISB12

//  IC PT100 1
#define SPI_2_CS_PT100A      LATBbits.LATB15
#define SPI_2_CS_PT100A_TRIS TRISBbits.TRISB15
//  IC PT100 2
#define SPI_2_CS_PT100B      LATEbits.LATE14
#define SPI_2_CS_PT100B_TRIS TRISEbits.TRISE14
//  IC ADC x 2 PTC
#define SPI_2_CS_AD      LATAbits.LATA7
#define SPI_2_CS_AD_TRIS TRISAbits.TRISA7
//  IC DAC x 2 0/10VDC
#define SPI_2_CS_DA      LATBbits.LATB14
#define SPI_2_CS_DA_TRIS TRISBbits.TRISB14



// # SPI 3 || X SCHEDA ESPANSIONE ====================================
#define SPI_3_SCK      LATBbits.LATB1
#define SPI_3_SCK_TRIS TRISBbits.TRISB1
#define SPI_3_SDO      LATBbits.LATB0
#define SPI_3_SDO_TRIS TRISBbits.TRISB0
#define SPI_3_SDI      PORTAbits.RA1
#define SPI_3_SDI_TRIS TRISAbits.TRISA1

#define CS_1_SLAVE      LATAbits.LATA0
#define CS_1_SLAVE_TRIS TRISAbits.TRISA0
#define CS_2_SLAVE      LATAbits.LATA11
#define CS_2_SLAVE_TRIS TRISAbits.TRISA11
#define CS_3_SLAVE      LATGbits.LATG9
#define CS_3_SLAVE_TRIS TRISGbits.TRISG9
#define CS_4_SLAVE      LATGbits.LATG6
#define CS_4_SLAVE_TRIS TRISGbits.TRISG6





//  DISPLAY pin ----------------------------------------- //
#define HAP_DISP_DATA0      LATCbits.LATC0
#define HAP_DISP_DATA0_TRIS TRISCbits.TRISC0
#define HAP_DISP_DATA1      LATCbits.LATC1
#define HAP_DISP_DATA1_TRIS TRISCbits.TRISC1
#define HAP_DISP_DATA2      LATCbits.LATC2
#define HAP_DISP_DATA2_TRIS TRISCbits.TRISC2
#define HAP_DISP_DATA3      LATCbits.LATC3
#define HAP_DISP_DATA3_TRIS TRISCbits.TRISC3
#define HAP_DISP_DATA4      LATCbits.LATC4
#define HAP_DISP_DATA4_TRIS TRISCbits.TRISC4
#define HAP_DISP_DATA5      LATCbits.LATC5
#define HAP_DISP_DATA5_TRIS TRISCbits.TRISC5
#define HAP_DISP_DATA6      LATCbits.LATC6
#define HAP_DISP_DATA6_TRIS TRISCbits.TRISC6
#define HAP_DISP_DATA7      LATCbits.LATC7
#define HAP_DISP_DATA7_TRIS TRISCbits.TRISC7

#define HAP_DISP_DATA_MASK 0x00FF
#define HAP_DISP_DATA_TRIS TRISC
#define HAP_DISP_DATA_IN   PORTC
#define HAP_DISP_DATA      LATC

#define HAP_DISP_CE         LATEbits.LATE13
#define HAP_DISP_CE_TRIS    TRISEbits.TRISE13
#define HAP_DISP_RESET      LATEbits.LATE12
#define HAP_DISP_RESET_TRIS TRISEbits.TRISE12
#define HAP_DISP_WRITE      LATCbits.LATC13
#define HAP_DISP_WRITE_TRIS TRISCbits.TRISC13
#define HAP_DISP_READ       LATCbits.LATC10
#define HAP_DISP_READ_TRIS  TRISCbits.TRISC10
#define HAP_DISP_CD         LATCbits.LATC11
#define HAP_DISP_CD_TRIS    TRISCbits.TRISC11



//  GENERIC INPUTS ------------------------------------------------ //
#define IN_11      !PORTBbits.RB8
#define IN_11_TRIS TRISBbits.TRISB8
#define IN_07      !PORTBbits.RB9
#define IN_07_TRIS TRISBbits.TRISB9
#define IN_06      !PORTDbits.RD5
#define IN_06_TRIS TRISDbits.TRISD5



//  GENERIC OUTPUTS ----------------------------------------------- //
#define OUT_01      LATCbits.LATC12
#define OUT_01_TRIS TRISCbits.TRISC12

#define OUT_06      LATCbits.LATC15
#define OUT_06_TRIS TRISCbits.TRISC15

#define OUT_12      LATAbits.LATA9     // PWM 1
#define OUT_12_TRIS TRISAbits.TRISA9
#define OUT_13      LATAbits.LATA4     // PWM 2
#define OUT_13_TRIS TRISAbits.TRISA4

#define OUT_PWM_1 OUT_12
#define OUT_PWM_2 OUT_13


#define INT0_PIN      PORTBbits.RB7
#define INT0_PIN_TRIS TRISBbits.TRISB7     // INT0 usato per CP PW-OFF

#define HAP_RX_TRIS  TRISBbits.TRISB5
#define HAP_TX_TRIS  TRISBbits.TRISB6
#define HAP_DIR_TRIS TRISDbits.TRISD8
#define HAP_DIR      LATDbits.LATD8


#define HAP_RUN      LATCbits.LATC8     // DIR
#define HAP_RUN_TRIS TRISCbits.TRISC8

#define DIGOUT_RELE4_LAT LATCbits.LATC12
#define DIGOUT_RELE4_TRIS TRISCbits.TRISC12
#define DIGOUT_RELE6_LAT LATCbits.LATC15
#define DIGOUT_RELE6_TRIS TRISCbits.TRISC15
#define DIGIN_IN6_PORT  PORTBbits.RB9
#define DIGIN_IN6_TRIS  TRISBbits.TRISB9
#define DIGIN_IN7_PORT  PORTBbits.RB8
#define DIGIN_IN7_TRIS  TRISBbits.TRISB8



#endif /* HARDWAREPROFILE_H */
