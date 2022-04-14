#ifndef DIGOUT_H_INCLUDED
#define DIGOUT_H_INCLUDED

#include <stdint.h>

typedef enum {
    DIGOUT_RELE1 = 0,
    DIGOUT_RELE2,
    DIGOUT_RELE3,
    DIGOUT_RELE4,
    DIGOUT_RELE5,
    DIGOUT_RELE6,
    DIGOUT_RELE7,
    DIGOUT_RELE8,
    DIGOUT_RELE9,
    DIGOUT_RELE10,
    DIGOUT_RELE11,      
    NUM_DIGOUT,
} digout_t;

void digout_update_retro(int val);
void digout_update_buzzer(int val);
int digout_get_buzzer_level(void);
void digout_update_rele(digout_t output, int val);
int digout_get(digout_t output);
void digout_period_check(void);
uint16_t digout_get_status(void);
void digout_clear_all (void);

#endif