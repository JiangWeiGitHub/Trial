
#include "./header.h"

int main(int argc, char *argv[])
{
  // Public String
  char message[1024] = "Hello John!";
  int i = 0;

  // Create Semaphore
  sem_id = semget((key_t)1238, 1, IPC_EXCL | IPC_CREAT | 0666);
  printf("%d\n", sem_id);

  // First One
  if(argc > 1)
  {
    if(!set_semvalue())
    {
      fprintf(stderr, "Failed to initialize semaphore\n");
      perror("main: ");
      exit(EXIT_FAILURE);
    }

    // First One's Print String
    memset(message, 0, sizeof(message));
    memcpy(message, argv[1], strlen(argv[1]));

    sleep(2);
  }

  for(i = 0; i < 10; ++i)
  {
    // Enter Critical Region
    if(!semaphore_p())
    {
      exit(EXIT_FAILURE);
    }

    printf("%s", message);

    fflush(stdout);

    sleep(rand() % 3);

    printf("%s", message);
    fflush(stdout);

    // Leave Critical Region
    if(!semaphore_v())
    {
      exit(EXIT_FAILURE);
    }

    sleep(rand() % 2);
  }

  sleep(10);

  printf("\n%d - Finished\n", getpid());

  if(argc > 1)
  {
    sleep(3);

    del_semvalue();
  }

  exit(EXIT_SUCCESS);
}