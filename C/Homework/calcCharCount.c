#include <stdio.h>
#include <stdlib.h>

struct print
{
  char nameList[26];
  int counter;
};

struct single
{
  char name;
  int counter;
};

struct print final[26];
int nameListCounter = 0;
int counterLabel = 0;

struct single list[26];

void calcCharCount(char *s)
{
  int tmp;
  for(tmp = 0; tmp < 26; tmp++)
  {
    list[tmp].counter = 0;
  }

  while(*s != '\0')
  {
    if(*s <= 'z' && *s >= 'a')
    {
      // printf("s: %c\n", *s);
      int number = *s - 'a';
      list[number].name = *s;
      list[number].counter += 1;
      // printf("list[%d].counter: %d\n", number, list[number].counter);
    }

    s++;
  }

  int i, j;
  for(i = 0; i < 25; i++)
  {
    for(j = 0; j < 25 - i; j++)
    {
      if(list[j].counter > list[j+1].counter)
      {
        char tmpName = list[j+1].name;
        int tmpCounter = list[j+1].counter;

        list[j+1].name = list[j].name;
        list[j+1].counter = list[j].counter;

        list[j].name = tmpName;
        list[j].counter = tmpCounter;
      }
    }
  }

  // for(tmp = 0; tmp < 26; tmp++)
  // {
  //   printf("list[%d].name: %c\n", tmp, list[tmp].name);
  //   printf("list[%d].counter: %d\n", tmp, list[tmp].counter);
  // }


  for(tmp = 0; tmp < 26; tmp++)
  {
    if(list[tmp].counter > 0)
    {
      if(tmp > 0)
      {
        if(list[tmp].counter == list[tmp-1].counter)
        {
          final[counterLabel].nameList[nameListCounter++] = list[tmp].name;
        }
        else
        {
          counterLabel += 1;
          final[counterLabel].nameList[nameListCounter++] = list[tmp].name;
        }

        final[counterLabel].counter = list[tmp].counter;
      } 
    }
  }
}

void main(void)
{
  calcCharCount("She could see the open door of a departmental office. 'Hello! Excuse me. This is the department of French, isn't it?'");

  int tmp;
  for(tmp = 0; tmp < 26; tmp++)
  {
    if(final[tmp].counter <= 0)
    {
      continue;
    }

    int i;
    for(i = 0; i < 26; i++)
    {
      if(final[tmp].nameList[i] >= 'a' && final[tmp].nameList[i] <= 'z' && final[tmp].nameList[i+1] >= 'a' && final[tmp].nameList[i+1] <= 'z')
      {
        printf("%c, ", final[tmp].nameList[i]);
      }
      else if(final[tmp].nameList[i] >= 'a' && final[tmp].nameList[i] <= 'z' && final[tmp].nameList[i+1] < 'a' || final[tmp].nameList[i+1] > 'z')
      {
        printf("%c ", final[tmp].nameList[i]);
      }
    }

    printf(": %d\n", final[tmp].counter);    
  }
}