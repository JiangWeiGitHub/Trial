#include "./Shell.h"

bool Shell::sort(int* number, int length)
{
  int i, j, gap;

  for (gap = length / 2; gap > 0; gap /= 2)
  {
    for (i = 0; i < gap; i++)
    {
      for (j = i + gap; j < length; j += gap)
      {
        if (number[j] > number[j - gap])
        {  
          int temp = number[j];
          int k = j - gap;

          while (k >= 0 && number[k] < temp)  
          {
            number[k + gap] = number[k];  
            k -= gap;
          }

          number[k + gap] = temp;  
        }
      }
    }
  }

  return true;
}

// bool Shell::sort(int* number, int length)
// {
//   int left = 0;
//   if(length % 2 == 0)
//   {
//     left = 0;
//   }
//   else
//   {
//     left = 1;
//   }

//   for(int i = length / 2; i >= 1; i = i / 2)
//   {
//     // std::cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> "<<std::endl;
//     // std::cout<<"i: "<<i<<std::endl;

//     for(int j = 0; j < i + left; j++)
//     {
//       // std::cout<<"j: "<<j<<std::endl;
//       for(int k = j; k < j + i; k++)
//       {
//         // std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<std::endl;
//         // std::cout<<"k: "<<k<<std::endl;
//         // std::cout<<"j: "<<j<<std::endl;
//         if(number[k] > number[k + i])
//         {
//           // std::cout<<"number[k]: "<<number[k]<<std::endl;
//           // std::cout<<"number[k + i]: "<<number[k + i]<<std::endl;
//           // std::cout<<"k: "<<k<<std::endl;
//           // std::cout<<"k + i: "<<k + i<<std::endl;

// // std::cout<<"--------------------------------------------------"<<std::endl;

//           int tmp = number[k];
//           number[k] = number[k + i];
//           number[k + i] = tmp;
//           std::cout<<"k: "<<k<<std::endl;
//           std::cout<<"k + i: "<<k + i<<std::endl;
//           std::cout<<"number[k]: "<<number[k]<<std::endl;
//           std::cout<<"number[k + i]: "<<number[k + i]<<std::endl;
//         }
//       }
//     }

//     // std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
//   } 
// }