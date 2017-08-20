// #define _GNU_SOURCE
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <errno.h>
// #include <limits.h>

// int
// main(int argc, char *argv[])
// {
//   int fd;
//   int len, slen;

//   if (argc != 2) {
//     fprintf(stderr, "Usage: date |./a.out out.log | cat\n");
//     exit(EXIT_FAILURE);
//   }

//   fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//   if (fd == -1) {
//     perror("open");
//     exit(EXIT_FAILURE);
//   }

//   do
//   {
//     len = tee(STDIN_FILENO, STDOUT_FILENO,
//                 INT_MAX, SPLICE_F_NONBLOCK);

//     if (len < 0) {
//       if (errno == EAGAIN)
//         continue;
//       perror("tee");
//       exit(EXIT_FAILURE);
//     }
//     else
//       if (len == 0)
//         break;

//     while (len > 0)
//     {
//       slen = splice(STDIN_FILENO, NULL, fd, NULL,
//                       len, SPLICE_F_MOVE);
//       if (slen < 0)
//       {
//         perror("splice");
//         break;
//       }
//       len -= slen;
//     }
//   } while (1);

//   close(fd);
//   exit(EXIT_SUCCESS);
// }

/* using splice() & tee(), copy "./1.txt"'s contents to "./2.txt" and "./3.txt" at the same time*/

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

int main(){
  int fd1 = open("./1.txt", O_RDONLY);
  int fd2 = open("./2.txt", O_RDWR| O_CREAT | O_TRUNC, 0666);
  int fd3 = open("./3.txt", O_RDWR| O_CREAT | O_TRUNC, 0666);

  int pipefd2[2];
  int pipefd3[2];

  pipe(pipefd2);
  pipe(pipefd3);

  // at least one of fd_in and fd_out must be a pipe
  splice(fd1, NULL, pipefd2[1], NULL, 10086, SPLICE_F_MORE);

  tee(pipefd2[0], pipefd3[1], 10086, SPLICE_F_NONBLOCK);

  splice(pipefd2[0], NULL, fd2, NULL, 10086, SPLICE_F_MORE);

  splice(pipefd3[0], NULL, fd3, NULL, 10086, SPLICE_F_MORE);

  close(fd1);
  close(fd2);
  close(fd3);

  close(pipefd2[0]);
  close(pipefd2[1]);
  close(pipefd3[0]);
  close(pipefd3[1]);

  return 0;
}