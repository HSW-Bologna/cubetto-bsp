#include "peripherals/timer.h"
#include "gel/timer/timecheck.h"
#include "system.h"
#include "spi_devices.h"
#include "digout.h"

#define ON 1
#define OFF 0


static unsigned long time_on  = 0;
static unsigned long time_off = 0;
static int        repeat   = 0;
static int           is_set   = 0;
static unsigned long ts       = 0;


void digout_buzzer_bip(size_t r, unsigned long t_on, unsigned long t_off) {
    repeat     = r;
    time_on    = t_on;
    time_off   = t_off;
    is_set     = 1;
    digout_update_buzzer(ON);
    ts         = get_millis();
}


void buzzer_stop(void) {
    digout_update_buzzer(OFF);
    is_set     = 0;
    repeat     = 0;
    time_on    = 0;
    time_off   = 0;
}


void buzzer_check(void) {
    if (is_set && repeat > 0) {
        if ((is_expired(ts, get_millis(), time_on)) && (digout_get_buzzer_level()==ON)) {
            digout_update_buzzer(OFF);
            ts         = get_millis();
            repeat--;
        } else if ((is_expired(ts, get_millis(), time_off)) && (digout_get_buzzer_level()==OFF)) {
            digout_update_buzzer(ON);
            ts         = get_millis();
        }
    }

    if (is_set && repeat == 0) {
        is_set     = 0;
        ts         = 0;
        digout_update_buzzer(OFF);
    }
}
