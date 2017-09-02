#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  char a[256] = "qwerasdfzxcv";
  char b[256] = "tyuiopghjklbnm";
  char c[256] = {0};

  int fd_a, fd_b, fd_c, i, j, tmp;
  fd_a = open("./a.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  fd_b = open("./b.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  fd_c = open("./c.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  if(fd_a == -1 || fd_b == -1 || fd_c == -1)
  {
    perror("Open files error!");
    return -1;
  }
  write(fd_a, a, strlen(a));
  write(fd_b, b, strlen(b));

  close(fd_b);
  close(fd_a);

  for(i = 0; i < (strlen(a) - 1); i++)
  {
    for(j = 0; j < (strlen(a) - 1); j++ )
    {
      if(a[j] > a[j + 1])
      {
        tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }

  for(i = 0; i < (strlen(b) - 1); i++)
  {
    for(j = 0; j < (strlen(b) - 1); j++ )
    {
      if(b[j] > b[j + 1])
      {
        tmp = b[j];
        b[j] = b[j + 1];
        b[j + 1] = tmp;
      }
    }
  }

  int counter = 0;
  int a_flag = 0;
  int b_flag = 0;

  for(i = a_flag; i < strlen(a); i++)
  {
    for(j = b_flag; j < strlen(b); j++)
    {
      if(b[j] > a[i])
      {
        c[counter++] = a[i];
        a_flag++;
        break;
      }
      else
      {
        c[counter++] = b[j];
        b_flag++;
      }
    }
  }
  
  if(a_flag < strlen(a))
  {
    for(i = a_flag; i < strlen(a); i++)
    {
      c[counter++] = a[i];
    }
  }

  if(b_flag < strlen(b))
  {
    for(j = b_flag; j < strlen(b); j++)
    {
      c[counter++] = b[j];
    }
  }

  printf("%s, %s, %s\n", a, b, c);

  return 0;
}