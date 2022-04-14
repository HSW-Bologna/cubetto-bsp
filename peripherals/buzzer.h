#ifndef BUZZER_H_INCLUDED
#define BUZZER_H_INCLUDED

void digout_buzzer_bip(size_t r, unsigned long t_on, unsigned long t_off);
void buzzer_stop(void);
void buzzer_check(void);

#endif