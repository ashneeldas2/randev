#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int * get_random() {
    int fd = open("/dev/random", O_RDONLY);
    int * nums;
    read(fd, nums, sizeof(int) * 10);
    return nums;
}

int main() {
    int * arr = get_random();
    int i = 0;
    for (; i < 10; i++) {
        printf("random %d: %d\n", i, arr[i]);
    }
}