// operations.c
#include "operations.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0; // 또는 에러 메시지를 출력하거나 예외 처리를 할 수 있습니다.
    }
}
