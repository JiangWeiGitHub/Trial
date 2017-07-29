
#include "./header.h"

int main(int argc, char *argv[])
{
  char message[1024] = "Hello Two!";
  int i = 0;

  int sem_id = get_sem_id();

  for(i = 0; i < 10; ++i)
  {
    // Enter Critical Region
    if(!semaphore_p(sem_id))
    {
      perror("semaphore_p: ");
      exit(EXIT_FAILURE);
    }

    printf("%s\n", message);

    fflush(stdout);

    sleep(rand() % 3);

    // Leave Critical Region
    if(!semaphore_v(sem_id))
    {
      perror("semaphore_v: ");
      exit(EXIT_FAILURE);
    }

    sleep(rand() % 2);
  }

  exit(EXIT_SUCCESS);
}