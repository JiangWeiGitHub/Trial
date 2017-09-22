#include <stdio.h>
#include <string.h>

struct data
{
  int position;
  int counter;
};

void main(void)
{
  struct data save;
  save.position = -1;
  save.counter = 0;

  // char testStr[255] = "sdfs4653sdfsdf34wr31gdf13554rdfrtrt3413df31werr32f13sd";
  char testStr[255] = "435134313ew31d3fsr1wedfs43we11f3dsdf13";
  int i;
  int tmpPosition = -1;
  int tmpCounter = 0;
  for(i = 0; i < strlen(testStr); i++)
  {
    if(testStr[i] >= '0' && testStr[i] <= '9')
    {
      // if(save.position == -1)
      if(tmpPosition == -1)
      {
        // save.positon = i;
        tmpPosition = i;
        // save.counter++;
        tmpCounter++;
      }
      else
      {
        //save.counter++;
        tmpCounter++;
      }
    }
    else
    {
      if(tmpCounter > save.counter)
      {
        save.position = tmpPosition;
        save.counter = tmpCounter;
      }

      tmpPosition = -1;
      tmpCounter = 0;
    }
  }

  printf("Contents: ");
  for(i = 0; i < save.counter; i++)
  {
    printf("%c", testStr[save.position++]);
  }
  printf("!\n");
}