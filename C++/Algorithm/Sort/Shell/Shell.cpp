#include "./Shell.h"

// bool Shell::sort(int* number, int length)
// {
//   int i, j, gap;

//   for (gap = length / 2; gap > 0; gap /= 2)
//   {
//     for (i = 0; i < gap; i++)
//     {
//       for (j = i + gap; j < length; j += gap)
//       {
//         if (number[j] > number[j - gap])
//         {  
//           int temp = number[j];
//           int k = j - gap;

//           while (k >= 0 && number[k] < temp)  
//           {
//             number[k + gap] = number[k];  
//             k -= gap;
//           }

//           number[k + gap] = temp;  
//         }
//       }
//     }
//   }

//   return true;
// }

bool Shell::sort(int* number, int length)
{

  for(int i = length / 2; i >= 1; i = i / 2)
  {
    for(int j = 0; j < i; j ++)
    {
      for(int k = j; k < length; k += i)
      {
        if(k == j)
        {
          continue;
        }

        for(int l = j; l < length; l += i)
        {
          if(number[l] > number[k])
          {
            int tmp = number[k];
            while(l < k)
            {
              number[k] = number[k - i];
              k -= i;
            }

            number[k] = tmp;

            break;
          }
        }
      }
    }
  } 
}