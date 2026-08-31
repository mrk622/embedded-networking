#include "device.h"
#include <stdio.h>

int main(void) {
    Device devices[3];

    device_init(&devices[0], 1, "Sensor A", 3300, 22, DEVICE_OFF);
    device_init(&devices[1], 2, "Sensor B", 3250, 25, DEVICE_RUNNING);
    device_init(&devices[2], 3, "Sensor C", 3100, 30, DEVICE_ERROR);

    Device *device = device_find_by_id(devices, 3, 2);
    if (device != NULL) {
        /* Device found */
        device_update_measurements(device, 3200, 27);
        device_set_flag(device, FLAG_SENSOR_OK);
        device_set_flag(device, FLAG_DATA_READY);
        device_set_state(device, DEVICE_RUNNING);
        device_print(device);

        if (device_has_flag(device, FLAG_DATA_READY) == 1) {
            printf("Data ready\n");
        }
        device_clear_flag(device, FLAG_DATA_READY);
        if (device_has_flag(device, FLAG_DATA_READY) == 0) {
            printf("Data not ready\n");
        }
    }

    return 0;
}
