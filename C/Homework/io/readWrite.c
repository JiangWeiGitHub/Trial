#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

void main(void)
{
  int fd = 0;
  fd = open("./test.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
  if(fd == -1)
  {
    perror("Open file: ");
  }

  ssize_t counter = 0;
  char buf[1024] = "Only for test!\n"; 
  counter = write(fd, buf, 1024);
  if(counter <= 0)
  {
    perror("Write file: ");
  }

  int result = 0;
  result = close(fd);
  if(result == -1)
  {
    perror("Close file: ");
  }

  fd = open("./test.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
  if(fd == -1)
  {
    perror("Open file: ");
  }

  counter = 0;
  char read_buf[1024] = {0}; 
  counter = read(fd, read_buf, 1024);
  if(counter <= 0)
  {
    perror("Read file: ");
  }

  printf("Read file: %s\n", read_buf);
}