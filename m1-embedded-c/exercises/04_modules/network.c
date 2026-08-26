#include "network.h"

int network_status = 0;
static int retry_count = 0;
static void network_retry(void);

void network_init(void) {
    network_retry();
    network_status = 1;
}
int network_get_status(void) {
    return network_status;
}
static void network_retry(void) {
    retry_count++;
}
