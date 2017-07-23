#include <stdio.h>

#define MAXLEN 50
int data[MAXLEN];

// int *calcFact(int n)
// {
//   int i,j,k,r;
//   int digit=1;
//   for(i=1;i<MAXLEN+1;i++)
//   {
//     data[i]=0;
//   }

//   data[0]=1;
//   data[1]=1;

//   for(i=1;i<n+1;i++)
//   {
//     for(j=1;j<digit+1;j++)
//     {
//       data[j]*=i;
//     }

//     for(j=1;j<digit+1;j++)
//     {
//       if(data[j]>10)
//       {
//         for(r=1;r<digit+1;r++)
//         {
//           if(data[digit]>10)
//           {
//             digit++;
//           }
//           data[r+1]+=data[r]/10;
//           data[r]=data[r]%10;
//         } 
//       } 
//     }

//     printf("%d!=",i);

//     for(k=digit;k>0;k--)
//     {
//       printf("%d",data[k]);
//     }

//     printf("\n");
//   }

//   return data;
// }


// 286 * 11 * 12 * 13


//       11
//    * 286 -> 2  8  6
// --------
//       66
//      88
//     22
// --------
//     3146

//       12
//   * 3146 -> 3  1  4  6
// --------
//       72
//      48
//     12
//    36
// --------
//    37752


//       13
//  * 37752 -> 3  7  7  5  2
// --------
//       26
//      65
//     91
//    91
//   39
// --------
//   490776


void calcFact(int number)
{
  int a,b,c,d;
  int tmpSum = 0;
  int curDigit = 1;
  int tmpForward = 1;
  data[1] = data[0] = 1;


  for(a = 1; a <= number; a++)
  {
    for(b = 1; b <= curDigit; b++)
    {
      data[b] *= a;
      data[b] *= (b - 1) * 10;

      // tmpSum += data[b];
    }

    for(b = 1; b < curDigit; b++)
    {
      tmpSum = data[c] + data[d];

      // tmpSum += data[b];
    }

    // if(tmpSum >= 10 * (curDigit + 1))
    // {
    //   curDigit += 1;
    // }
  }
}

int main(void)
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  calcFact(n);

  return 0;
}



