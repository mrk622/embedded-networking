#include <stdint.h>
#include <stdio.h>

int add_u32(uint32_t a, uint32_t b, uint32_t *result) {
    if (result == NULL) {
        return -2;
    } else if (a > UINT32_MAX - b) {
        return -1;
    } else {
        *result = a + b;
        return 0;
    }
}

int main(void) {
    uint32_t result;
    int erfolg = add_u32(UINT32_MAX, 1, &result);
    if (erfolg == 0) {
        printf("Ergebnis: %u\n", result);
    } else {
        printf("Fehler: %d\n", erfolg);
    }
}
