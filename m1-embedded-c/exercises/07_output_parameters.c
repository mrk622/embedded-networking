#include <stdio.h>

int divide(int a, int b, int *result) {
    if (result == NULL) {
        return -2;
    } else if (b == 0) {
        return -1;
    } else {
        *result = a / b;
        return 0;
    }
}

int main(void) {
    int result;
    int erfolg = divide(5, 5, &result);
    printf("Status: %d\n", erfolg);
    printf("Ergebnis: %d\n", result);

    erfolg = divide(5, 0, &result);
    printf("Status: %d\n", erfolg);
    printf("kein Ergebnis, da Division durch 0\n");

    erfolg = divide(5, 5, NULL);
    printf("Status: %d\n", erfolg);
    printf("kein Ergebnis da NULL-Pointer\n");
}
