#include <stddef.h>
#include <stdio.h>

void copy_string(char destination[], size_t destination_size,
                 const char source[]) {
    if (destination_size > 0) {
        size_t i;
        for (i = 0; (i < (destination_size - 1)) && (source[i] != '\0');
             i++) {
            destination[i] = source[i];
        }
        destination[i] = '\0';
    }
}

int main(void) {
    const char *source = "Embedded Networking";
    char destination[10];
    copy_string(destination, 10, source);
    printf("%s\n", destination);
}
