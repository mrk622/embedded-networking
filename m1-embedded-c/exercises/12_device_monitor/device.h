#ifndef DEVICE_H
#define DEVICE_H
#include <stddef.h>
#include <stdint.h>

#define FLAG_SENSOR_OK (1U << 0)
#define FLAG_DATA_READY (1U << 1)

typedef enum { DEVICE_OFF, DEVICE_RUNNING, DEVICE_ERROR } DeviceState;

typedef struct {
    uint8_t id;
    char name[21];
    uint16_t voltage_mv;
    int16_t temperature;
    DeviceState state;
    uint8_t flags;
} Device;

int device_update_measurements(Device *device, uint16_t voltage_mv,
                               int16_t temperature);

Device *device_find_by_id(Device *devices, size_t count, uint8_t id);

int device_set_state(Device *device, DeviceState state);

int device_set_flag(Device *device, uint8_t flag);

int device_clear_flag(Device *device, uint8_t flag);

int device_has_flag(const Device *device, uint8_t flag);

int device_print(const Device *device);

int device_init(Device *device, uint8_t id, const char *name,
                uint16_t voltage_mv, int16_t temperature, DeviceState state);

#endif
