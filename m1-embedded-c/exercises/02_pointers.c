#include <stdio.h>

void set_value(int *ptr) { *ptr = 100; }

struct Sensor {
    int temperature;
    int humidity;
};

int main() {
    int temperatur = 25;
    int *ptr = &temperatur;

    printf("%d\n", temperatur);
    printf("%p\n", (void *)&temperatur);
    printf("%p\n", (void *)ptr);
    printf("%d\n", *ptr);

    *ptr = 30;
    printf("%d\n", temperatur);
    printf("%d\n", *ptr);

    printf("%p\n", (void *)&ptr);

    int value = 42;
    printf("%d\n", value);
    set_value(&value);
    printf("%d\n", value);

    int values[3] = {10, 20, 30};
    printf("%p, %p, %p\n", (void *)&values[0], (void *)&values[1],
           (void *)&values[2]);
    printf("%p, %p, %p\n", (void *)values, (void *)(values + 1),
           (void *)(values + 2));

    for (int i = 0; i < 3; i++) {
        printf("%d, %d\n", values[i], *(values + i));
    }

    struct Sensor sensor;
    sensor.temperature = 25;
    sensor.humidity = 60;

    struct Sensor *ptr_sensor = &sensor;
    ptr_sensor->temperature = 30;

    printf("%d\n", sensor.temperature);
    printf("%d\n", ptr_sensor->temperature);

    return 0;
}