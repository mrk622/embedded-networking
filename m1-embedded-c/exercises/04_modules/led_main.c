#include <stdio.h>
#include "led.h"

int main(void) {
    led_on();
    printf("%d\n", led_state);

    led_off();
    printf("%d\n", led_state);
    
    return 0;
}