#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int get_random() {
    int fd = open("/dev/random", O_RDONLY);
    int num;
    read(fd, &num, sizeof(int));
    if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
    }
    close(fd);
    return num;
}

int main() {
    int arr[10];
    int i = 0; 
    for (; i < 10; i++) {
        arr[i] = get_random();
        printf("random %d: %d\n", i, arr[i]);
    }

    int fd = open("rand_nums", O_CREAT | O_RDWR, 0644);
    printf("\nWriting numbers to file...\n");
    write(fd, arr, sizeof(arr));
    close(fd);

    int nums[10];
    fd = open("rand_nums", O_RDONLY, 0664);
    printf("\nReading numbers from file...\n");
    read(fd, nums, sizeof(nums));

    printf("\nVerification that written values are the same:\n");
    i = 0;
    for (; i < 10; i++) {
        printf("random %d: %d\n", i, nums[i]);
    }
}