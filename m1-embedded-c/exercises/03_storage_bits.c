#include <stdint.h>
#include <stdio.h>

#define SYSTEM_ENABLED (1U << 0)
#define DATA_READY (1U << 1)
#define ERROR_FLAG (1U << 2)

enum SystemState { SYSTEM_OFF, SYSTEM_RUNNING, SYSTEM_ERROR };

void update_system(void) {
    static int call_count = 0;
    call_count++;
    printf("Call count: %d\n", call_count);
}

int main(void) {
    update_system();
    update_system();
    update_system();

    enum SystemState state = SYSTEM_OFF;
    uint8_t control = 0;
    control |= SYSTEM_ENABLED;
    state = SYSTEM_RUNNING;

    control |= DATA_READY;
    if (control & DATA_READY) {
        printf("Data ready\n");
    }

    control |= ERROR_FLAG;
    if (control & ERROR_FLAG) {
        state = SYSTEM_ERROR;
    }
    if (state == SYSTEM_ERROR) {
        printf("System error\n");
    }

    return 0;
}
