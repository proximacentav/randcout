
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static const char charset[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

static const int charset_size = sizeof(charset) - 1;

int main(int argc, char *argv[]) {
    int speed;
    unsigned int seed;
    useconds_t delay_us;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <speed (chars/sec)>\n", argv[0]);
        fprintf(stderr, "Example: %s 100\n", argv[0]);
        return 1;
    }

    {
        char *endptr;
        long val = strtol(argv[1], &endptr, 10);
        if (*endptr != '\0' || val <= 0) {
            fprintf(stderr, "Error: speed must be a positive integer.\n");
            return 1;
        }
        if (val > 1000000) {
            fprintf(stderr, "Error: speed must not exceed 1000000.\n");
            return 1;
        }
        speed = (int)val;
    }

    delay_us = (useconds_t)(1000000 / speed);
    if (delay_us == 0)
        delay_us = 1;

    seed = (unsigned int)time(NULL) ^ (unsigned int)getpid();
    srand(seed);

    setbuf(stdout, NULL);

    while (1) {
        int idx = rand() % charset_size;
        putchar(charset[idx]);
        usleep(delay_us);
    }

    return 0;
}
