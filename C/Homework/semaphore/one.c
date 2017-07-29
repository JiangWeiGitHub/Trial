
#include "./header.h"

int main(int argc, char *argv[])
{
  char message[1024] = "Hello One!";
  int i = 0;

  int sem_id = get_sem_id();

  if(!set_semvalue(sem_id))
  {
    perror("set_semvalue: ");
    exit(EXIT_FAILURE);
  }

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

  sleep(10);

  del_semvalue(sem_id);

  exit(EXIT_SUCCESS);
}