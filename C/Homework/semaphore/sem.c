#include "./header.h"

static int sem_id = 0;

int get_sem_id()
{
  // Create Semaphore
  if(sem_id == 0)
  {
    sem_id = semget((key_t)1234, 1, IPC_CREAT | 0666);
    perror("sem_id: ");
    printf("sem_id: %d\n", sem_id);
  }

  return sem_id;
}

int set_semvalue(int sem_id)
{
  union semun sem_union;

  sem_union.val = 1;
  if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
  {
    perror("set_semvalue: ");
    return 0;   
  }

  return 1;
}

void del_semvalue(int sem_id)
{
  union semun sem_union;

  printf("sem's sem_id address: %p\n", &sem_id);

  printf("sem_id: %d\n", sem_id);

  if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
  {
    fprintf(stderr, "Failed to delete semaphore\n");
    perror("del_semvalue: ");
  }
}

int semaphore_p(int sem_id)
{
  struct sembuf sem_b;
  sem_b.sem_num = 0;
  sem_b.sem_op = -1;
  sem_b.sem_flg = SEM_UNDO;

  if(semop(sem_id, &sem_b, 1) == -1)
  {
    fprintf(stderr, "semaphore_p failed\n");
    return 0;
  }

  return 1;
}

int semaphore_v(int sem_id)
{
  struct sembuf sem_b;
  sem_b.sem_num = 0;
  sem_b.sem_op = 1;
  sem_b.sem_flg = SEM_UNDO;

  if(semop(sem_id, &sem_b, 1) == -1)
  {
    fprintf(stderr, "semaphore_v failed\n");
    return 0;
  }

  return 1;
}