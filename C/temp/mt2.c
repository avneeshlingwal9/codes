#include <stdio.h>
    #include<stdlib.h>

    int g_c_d(int a, int b)
     {
        if (b == 0)
          {
            return a;
        }
    return g_c_d(b, a%b);
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
        int nums[] = {18, 54, 162, 486, 50, 250, 98, 242};
        int nums_s = sizeof(nums) / sizeof(nums[0]);
        printf("for k your values are : ");
        for (int i = 0; i < nums_s; ++i)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
        printf("k\tU(k)\n");

        for (int i = 0; i < nums_s; ++i)
         {
            int k =nums[i];
            int size = Size_calculatation(k);
            printf("%d\t%d\n", k, size);
            }
        printf("\nConjecture: ");
        printf("The size of U(2p^n) is equal to or greater than the size of U(p^n).\n");
    return 0;
    }

