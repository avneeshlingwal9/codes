#include <stdio.h>
    #include<stdlib.h>

    int g_c_d(int a, int b)
    {
      if (b == 0)
        {
          return a;
        }
     return g_c_d(b, a % b);
    }

    int Size_calculatation(int k)
    {
      int size = 0;
        for (int i = 1; i <= k; ++i)
          {
            if (g_c_d(i, k) == 1)
            {
              size++;
            }
          }
    return size;
    }


    int main()
    {
        int nums[] = {9, 27, 81, 243, 25, 125, 49, 121};
      int  nums_s=sizeof(nums) / sizeof(nums[0]);
         printf("for k your values : ");
        for (int i = 0; i < nums_s; ++i)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");

         printf("k\tU(k)\n");
         for (int i = 0; i < nums_s; ++i)
            {
               int k = nums[i];
                int size = Size_calculatation(k);
               printf("%d\t%d\n", k, size);
            }
    return 0;
    }
