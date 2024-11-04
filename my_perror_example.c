#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *prefix) {
    fprintf(stderr, "%s: %s\n", prefix, strerror(errno));
}

int main(int argc, char *argv[]) {
    FILE *f;

    if (argc < 2) {
        printf("Usage: my_perror_show nofilename\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open a file \"%s\"... (error message: ", argv[1]);
        my_perror("Error");
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);
    fclose(f);
    return 0;
}
