#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <malloc.h>

int
main(int argc, char *argv[])
{
    int fd;
    ssize_t numRead;
    size_t length, alignment;
    off_t offset;
    char *buf;

    length = 8;
    offset = 0;
    alignment = 4096;

    fd = open(argv[1], O_RDONLY | O_DIRECT);
    if (fd == -1)
        perror("open");

    buf = memalign(alignment * 2, length + alignment);
    if (buf == NULL)
        perror("memalign");

    buf += alignment;

    if (lseek(fd, offset, SEEK_SET) == -1)
        perror("lseek");

    numRead = read(fd, buf, length);
    if (numRead == -1)
        perror("read");
    printf("Read %ld bytes\n", (long) numRead);

    return 0;
}