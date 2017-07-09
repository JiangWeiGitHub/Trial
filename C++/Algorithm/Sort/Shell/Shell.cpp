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
  // int left = 0;
  // if(length % 2 == 0)
  // {
  //   left = 0;
  // }
  // else
  // {
  //   left = 1;
  // }

  for(int i = length / 2; i >= 1; i = i / 2)
  {
    std::cout<<"i: "<<i<<std::endl;

    for(int j = 0; j < i; j ++)
    {
      std::cout<<"j: "<<j<<std::endl;

      for(int k = j; k < length; k += i)
      {
        std::cout<<"k: "<<k<<std::endl;

        int stick = j;
        while(stick < k)
        {
          if(number[stick] > number[k])
          {
            int test = k
            while(k > j)
            {
              
              k -= i;
            }
          }




          // // std::cout<<"stick: "<<stick<<std::endl;
          // int test = j;
          // while(number[stick] > number[test])
          // {
          //   int tmp = number[stick];
          //   number[stick] = number[k];
          //   number[k] = tmp;

          //   test += i;
          // }

          stick += i;
        }
      }
    }
  } 
}