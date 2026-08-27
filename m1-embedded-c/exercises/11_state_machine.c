#include <stdio.h>

typedef enum { STATE_OFF, STATE_RUNNING, STATE_ERROR } SystemState;

typedef enum { EVENT_START, EVENT_STOP, EVENT_FAULT, EVENT_RESET } SystemEvent;

SystemState handle_event(SystemState state, SystemEvent event) {
    switch (state) {
    case STATE_OFF:
        if (event == EVENT_START) {
            state = STATE_RUNNING;
        }
        break;

    case STATE_RUNNING:
        if (event == EVENT_STOP) {
            state = STATE_OFF;
        } else if (event == EVENT_FAULT) {
            state = STATE_ERROR;
        }
        break;

    case STATE_ERROR:
        if (event == EVENT_RESET) {
            state = STATE_OFF;
        }
        break;

    default:
        break;
    }

    return state;
}

int main(void) {
    SystemState state = STATE_OFF;

    state = handle_event(state, EVENT_START);
    printf("State after START: %d\n", state);

    state = handle_event(state, EVENT_FAULT);
    printf("State after FAULT: %d\n", state);

    state = handle_event(state, EVENT_RESET);
    printf("State after RESET: %d\n", state);

    return 0;
}
