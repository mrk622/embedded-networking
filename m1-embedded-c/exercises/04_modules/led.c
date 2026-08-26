#include "led.h"

int led_state = 0;
static int update_count = 0;

static void led_update_count(void) {
    update_count++;
}
void led_on(void) {
    led_state = 1;
    led_update_count();
}
void led_off(void) {
    led_state = 0;
    led_update_count();
}
