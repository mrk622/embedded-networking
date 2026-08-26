#include <stdio.h>

int string_length(const char text[]) {
    int length = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        length++;
    }

    return length;
}

void string_to_upper(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }
}

int main(void) {
    char text[] = "Hello STM32! abc-XYZ 123";
    int length = string_length(text);
    string_to_upper(text);
    printf("Length: %d\n", length);
    printf("Text: %s\n", text);

    return 0;
}
