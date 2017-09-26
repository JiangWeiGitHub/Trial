#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

// struct data
// {
// 	int first;
// 	int last;
// };

// void main(void)
// {
//   struct data testData1, testData2, testData3, testData4, testData5;

// 	// 12 45 8 74 1

// 	testData1.first = 12;
// 	testData1.last = 45;

// 	testData2.first = 8;
// 	testData2.last = 74;

// 	testData3.first = 45;
// 	testData3.last = 8;

// 	testData4.first = 74;
// 	testData4.last = 1;

// 	testData5.first = 12;
// 	testData5.last = 8;

// 	int testRound = 5;

// 	struct data testData[5] = {testData1, testData2, testData3, testData4, testData5};

// 	struct data req;
// 	req.first = 12;
// 	req.last = 1;

// 	int i;
// 	int* dataPoint[MAX] = {0};
// 	for(i = 0; i < testRound; i++)
// 	{
//     if(dataPoint[testData[i].first] == NULL)
// 		{
// 			int* tmp = (int*)malloc(sizeof(int) * MAX);
// 			memset(tmp, sizeof(int) * MAX, 0);
// 			dataPoint[testData[i].first] = tmp;
// 			(dataPoint[testData[i].first])[testData[i].last] = 1;
// 		}
// 		else
// 		{
// 			(dataPoint[testData[i].first])[testData[i].last] = 1;
// 		}
// 	}

// 	if(dataPoint[req.first] != NULL)
// 	{
// 		if((dataPoint[req.first])[req.last] != 0)
// 		{
// 			printf("Yes!\n");
// 		}
// 		else
// 		{
//       printf("No!\n");
// 		}
// 	}
// 	else
// 	{
// 		printf("I do not know!\n");
// 	}
// }

struct data
{
	int first;
	int last;
};

struct link
{
	int name;
	struct link* next;
};

void main()
{
  struct data testData1, testData2, testData3, testData4, testData5;

  // 12 45 8 74 1

  testData1.first = 12;
  testData1.last = 45;

  testData2.first = 8;
  testData2.last = 74;

  testData3.first = 45;
  testData3.last = 8;

  testData4.first = 74;
  testData4.last = 1;

  testData5.first = 12;
  testData5.last = 8;

  int testRound = 5;

  struct data testData[5] = {testData1, testData2, testData3, testData4, testData5};

  struct data req;
  req.first = 12;
  req.last = 1;

  struct link list[MAX];

  int i;
  for(i = 0; i < sizeof(testData); i++)
  {
    if(list[testData[i].first].name != testData[i].first)
    {
      list[testData[i].first].name = testData[i].first; 
    }
    else
    {
      
    }
  }
}