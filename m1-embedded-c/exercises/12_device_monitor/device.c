#include "device.h"
#include <stddef.h>
#include <stdio.h>

static const char *device_state_to_string(DeviceState state) {
    switch (state) {
    case DEVICE_OFF:
        return "OFF";
    case DEVICE_RUNNING:
        return "RUNNING";
    case DEVICE_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

int device_update_measurements(Device *device, uint16_t voltage_mv,
                               int16_t temperature) {
    if (device == NULL) {
        return -1;
    }
    device->temperature = temperature;
    device->voltage_mv = voltage_mv;
    return 0;
}

int device_set_state(Device *device, DeviceState state) {
    if (device == NULL) {
        return -1;
    }
    device->state = state;
    return 0;
}

int device_set_flag(Device *device, uint8_t flag) {
    if (device == NULL) {
        return -1;
    }
    device->flags |= flag;
    return 0;
}

int device_clear_flag(Device *device, uint8_t flag) {
    if (device == NULL) {
        return -1;
    }
    device->flags &= ~flag;
    return 0;
}

int device_has_flag(const Device *device, uint8_t flag) {
    if (device == NULL) {
        return -1;
    } else if (device->flags & flag) {
        return 1;
    }
    return 0;
}

Device *device_find_by_id(Device *devices, size_t count, uint8_t id) {
    if (devices == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < count; i++) {
        if (devices[i].id == id) {
            return &devices[i];
        }
    }
    return NULL;
}

int device_init(Device *device, uint8_t id, const char *name,
                uint16_t voltage_mv, int16_t temperature, DeviceState state) {
    if ((device == NULL) || (name == NULL)) {
        return -1;
    }
    size_t i;
    for (i = 0; (i < (sizeof(device->name) - 1)) && (name[i] != '\0'); i++) {
        device->name[i] = name[i];
    }
    device->name[i] = '\0';
    device->id = id;
    device->voltage_mv = voltage_mv;
    device->temperature = temperature;
    device->state = state;
    device->flags = 0;
    return 0;
}

int device_print(const Device *device) {
    if (device == NULL) {
        return -1;
    }

    printf("Device %d (%s)\n", device->id, device->name);
    printf("Voltage: %d mV\n", device->voltage_mv);
    printf("Temperature: %d C\n", device->temperature);
    printf("State: %s\n", device_state_to_string(device->state));
    printf("Flags: 0x%02x\n", device->flags);

    return 0;
}
