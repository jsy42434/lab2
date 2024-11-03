#include "operations.h"

int divide(int a, int b) {
    if (b == 0) {
        return 0;  // Error handling for division by zero
    }
    return a / b;
}
