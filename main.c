#include <stdio.h>
#include "operations.h"

int main() {
    int a = 10, b = 5;

    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtract: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiply: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Divide: %d / %d = %d\n", a, b, divide(a, b));

    return 0;
}
