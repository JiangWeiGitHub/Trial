#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  char a[256] = "sadsdfsdsdf";
  char b[256] = "thertdfdglsd";

  char c[256] = {0};
  char tmp_a[256] = {0};
  char tmp_b[256] = {0};

  int fd_a, fd_b, fd_c, i, j, tmp;
  fd_a = open("./a.txt", O_WRONLY | O_CREAT | O_TRUNC);
  fd_b = open("./b.txt", O_WRONLY | O_CREAT | O_TRUNC);
  fd_c = open("./c.txt", O_WRONLY | O_CREAT | O_TRUNC);
  if(fd_a == -1 || fd_b == -1 || fd_c == -1)
  {
    perror("Open files error!");
    return -1;
  }
  write(fd_a, a, strlen(a));
  write(fd_b, b, strlen(b));

  close(fd_b);
  close(fd_a);

  for(i = 0; i < strlen(a); i++)
  {
    for(j = 0; j < (strlen(a) - i); j++ )
    {
      if(a[i] > a[i + 1])
      {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
      }
    }
  }

  return 0;
}