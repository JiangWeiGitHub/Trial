#include <stdio.h>
#include <stdlib.h>

enum NAME
{
  TOM = 0,
  JERRY = 1,
  MARK = 2,
  AVIL = 3,
  BILL = 4,
  CATE = 5,
  DAVID = 6,
  EVAN = 7,
};

void printName(int id)
{
  switch(id)
  {
    case TOM:
      printf("Tom");
      break;
    case JERRY:
      printf("Jerry");
      break;
    case MARK:
      printf("Mark");
      break;
    case AVIL:
      printf("Avil");
      break;
    case BILL:
      printf("Bill");
      break;
    case CATE:
      printf("Cate");
      break;
    case DAVID:
      printf("David");
      break;
    case EVAN:
      printf("Evan");
      break;
    default:
      _Exit(-1);
  }
}

void main(void)
{
  char nameList[8] = {0};
  // int testData[10][2] = {{0,1},{2,3},{4,5},{6,7},{2,4},{3,5},{4,6},{5,7},{2,5},{3,4}};
  // int testData[8][2] = {{0,1},{1,2},{2,3},{3,4},{3,5},{3,2},{3,1},{3,0}};
  int testData[10][2] = {{TOM,JERRY},{MARK,AVIL},{BILL,CATE},{DAVID,EVAN},{MARK,BILL},{AVIL,CATE},{BILL,DAVID},{CATE,EVAN},{MARK,CATE},{AVIL,BILL}};
  // int testData[2][2] = {{TOM,JERRY},{TOM,AVIL}};
  int i, j;

  // for(i = 0; i < 8; i++)
  // {
  //   nameList[i] = 1 << i;
  // }

  for(i = 0; i < 8; i++)
  {
    switch(testData[i][0])
    {
      case TOM:
        nameList[TOM] |= 1 << testData[i][1];
        break;
      case JERRY:
        nameList[JERRY] |= 1 << testData[i][1];
        break;
      case MARK:
        nameList[MARK] |= 1 << testData[i][1];
        break;
      case AVIL:
        nameList[AVIL] |= 1 << testData[i][1];
        break;
      case BILL:
        nameList[BILL] |= 1 << testData[i][1];
        break;
      case CATE:
        nameList[CATE] |= 1 << testData[i][1];
        break;
      case DAVID:
        nameList[DAVID] |= 1 << testData[i][1];
        break;
      case EVAN:
        nameList[EVAN] |= 1 << testData[i][1];
        break;
      default:
        _Exit(-1);
    }

    switch(testData[i][1])
    {
      case TOM:
        nameList[TOM] |= 1 << testData[i][0];
        break;
      case JERRY:
        nameList[JERRY] |= 1 << testData[i][0];
        break;
      case MARK:
        nameList[MARK] |= 1 << testData[i][0];
        break;
      case AVIL:
        nameList[AVIL] |= 1 << testData[i][0];
        break;
      case BILL:
        nameList[BILL] |= 1 << testData[i][0];
        break;
      case CATE:
        nameList[CATE] |= 1 << testData[i][0];
        break;
      case DAVID:
        nameList[DAVID] |= 1 << testData[i][0];
        break;
      case EVAN:
        nameList[EVAN] |= 1 << testData[i][0];
        break;
      default:
        _Exit(-1);
    }
  }

  for(i = 0; i < 8; i++)
  {
    for(j = i + 1; j < 8; j++)
    {
      if((nameList[i] & nameList[j]) != 0)
      {
        nameList[i] |= nameList[j];
        nameList[j] = nameList[i];

        continue;
      }
    }
  }

  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      if(j == i)
      {
        continue;
      }
      else
      {
        printf("Are ");
        printName(i);
        printf(" & ");
        printName(j);
        printf(" friends? ");
        ((nameList[i] & 1 << j) == 0) ? printf("No\n") : printf("Yes\n");
      }
    }
  }
}