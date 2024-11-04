#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_assert(int condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "Assertion failed: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    FILE *f;

    // assert() 대신 my_assert() 사용
    my_assert(argc >= 2, "Usage: my_assert_use file_name");

    if ((f = fopen(argv[1], "r")) == NULL) {
        my_assert(0, "fopen failed");  // fopen이 실패할 경우
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);
    fclose(f);
    return 0;
}
