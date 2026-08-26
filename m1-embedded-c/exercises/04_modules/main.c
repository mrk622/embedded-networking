#include "sensor.h"
#include <stdio.h>

int main(void) {
    int temperature = sensor_read();
    printf("%d\n", temperature);

    sensor_status = 1;
    printf("%d\n", sensor_status);
    
    return 0;
}
