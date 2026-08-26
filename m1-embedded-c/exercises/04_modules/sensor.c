#include "sensor.h"

int sensor_status = 0;

static int sensor_raw_read(void);

int sensor_read(void) {
    int temperature = sensor_raw_read() / 4;
    return temperature;
}

static int sensor_raw_read(void) {
    return 100;
}
