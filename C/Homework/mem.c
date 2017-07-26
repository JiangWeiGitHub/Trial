#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
  int fd;
  char rdbuf[10] = {0};
  char *pointer = rdbuf;
  char wrbuf[10] = "1234567890";
  int i;
  fd = open("/dev/mem",O_RDWR);
  if(fd < 0)
  {
    printf("open /dev/mem failed.");
  }

  read(fd,rdbuf,10);
  if(strlen(rdbuf) <=0)
  {
    printf("Read error!\n");
  }

  for(i = 0;i < 10;i++)
  {
    printf("old mem[%d]:%c\n",i,*(pointer + i));
  }

  lseek(fd,0,0);
  write(fd,wrbuf,10);
  lseek(fd,0,0);//move f_ops to the front
  read(fd,rdbuf,10);

  for(i = 0;i < 10;i++)
  {
    printf("new mem[%d]:%c\n",i,*(pointer + i));
  }

  return 0;
}