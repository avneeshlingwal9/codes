#include <stdio.h>
    #include<stdlib.h>

    int g_c_d(int a, int b)
     {
       while (b != 0)
        {
           int temp = b;
            b = a % b;
             a = temp;
        }
    return a;
    }

    int inverse(int a, int n)
     {
          int m0 = n, m1 = a;
           int x0 = 0, x1 = 1;
            while (m1 != 0)
                {
                    int q = m0 / m1;
                    int temp = m0 % m1;
                    m0 = m1;
                    m1 = temp;
                    temp = x0;
                    x0 = x1 - q * x0;
                    x1 = temp;
                }
    return x1 < 0 ? x1 + n : x1;
    }

    void print(int n)
     {
        int unit[100];
        int u_count=0;
        for (int x = 1; x < n; ++x)
            {
                if (g_c_d(x, n) == 1)
                {
                    unit[u_count++] = x;
                }
            }
        printf("U(%d)\nelements: ", n);
        for (int i = 0; i < u_count; ++i)
            printf("%d ", unit[i]);
      printf("\n");
       int inverses[100];
        for (int i = 0; i < u_count; ++i)
            {
              inverses[i] = inverse(unit[i], n);
            }
             printf("Inverses : ", n);
              for (int i = 0; i < u_count; ++i)
              {
                 printf("%d ", inverses[i]);
              }
             printf("\n\n");
    }

    int main()
     {
        int nums[] = {12, 15, 30, 36, 63};
        int size  = sizeof(nums) / sizeof(nums[0]);
         printf("for U(n) your nums are : ");
        for (int i = 0; i < size ; ++i)
          {
            printf("%d ",nums[i]);
          }
          printf("\n");

          for (int i = 0; i < size ; ++i)
          {
             print(nums[i]);
          }
    return 0;
    }

