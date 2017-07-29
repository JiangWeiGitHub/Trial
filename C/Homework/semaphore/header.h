#ifndef _HEADER_H_
#define _HEADER_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>

union semun
{
  int val;
  struct semid_ds *buf;
  unsigned short *arry;
};

static int sem_id = 0;

int set_semvalue();
void del_semvalue();
int semaphore_p();
int semaphore_v();

#endif