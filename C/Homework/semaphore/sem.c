#include "./header.h"

extern int sem_id;

int set_semvalue()
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

void del_semvalue()
{
  union semun sem_union;

  if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
  {
    fprintf(stderr, "Failed to delete semaphore\n");
  }
}

int semaphore_p()
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

int semaphore_v()
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