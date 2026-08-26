#include <stdio.h>
#include "network.h"

int main(void) {
    network_init();
    int status = network_get_status();
    printf("%d\n", status);
    return 0;
}
