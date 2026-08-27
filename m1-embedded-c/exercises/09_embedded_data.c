#include <stdint.h>
#include <stdio.h>

#define FLAG_SENSOR_OK  (1u << 0)
#define FLAG_DATA_READY (1u << 1)

typedef enum { DEVICE_OFF, DEVICE_RUNNING, DEVICE_ERROR } DeviceState;

typedef struct {
    uint8_t id;
    uint16_t voltage_mv;
    int16_t temperature;
    DeviceState state;
    uint8_t flags;
} DeviceStatus;

int main(void) {
    uint16_t test_value = 0xABCD;
    uint8_t *bytes = (uint8_t *)&test_value;

    DeviceStatus devices[3] = {
        {.id = 1,
         .voltage_mv = 3300,
         .temperature = 13,
         .state = DEVICE_OFF,
         .flags = 0},
        {.id = 2,
         .voltage_mv = 3300,
         .temperature = 25,
         .state = DEVICE_RUNNING,
         .flags = 0},
        {.id = 3,
         .voltage_mv = 3300,
         .temperature = 21,
         .state = DEVICE_ERROR,
         .flags = 0}
    };

    DeviceStatus *device = &devices[1];
    device->voltage_mv = 3250;
    device->flags |= FLAG_DATA_READY;
    device->flags |= FLAG_SENSOR_OK;

    printf("Size of DeviceStatus: %zu\n", sizeof(DeviceStatus));
    printf("Device %d: %d mV\n", device->id, device->voltage_mv);

    printf("Byte 0: %02X\n",bytes[0]);
    printf("Byte 1: %02X\n",bytes[1]);    
}
