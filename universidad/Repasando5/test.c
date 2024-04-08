#include <stdio.h>
#include <stdlib.h>

void increment();

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        increment();
    }

    return 0;
}

void increment() {
    static int value = 0;

    value += 5;
    printf("Value = %d\n", value);
}