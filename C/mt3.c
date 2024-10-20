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

    int generator(int num, int n)
     {
        for (int i = 1; i < n; i++)
         {
            if (g_c_d(num, n) != 1)
                return 0;
            if ((num = (num * num) % n) == 1)
                return 0;
        }
    return 1;
    }

    void Generate_list(int n)
     {
        printf("Generators of are U(%d):\n", n);
        for (int i = 2; i < n; i++)
          {
            if (generator(i, n))
            printf("%d ", i);
           }
     printf("\n");
    }

    void Subgroups(int n)
     {
        printf("Subgroups of U(%d):\n", n);
        for (int i = 1; i <= n; i++)
          {
            if (g_c_d(i, n) == 1)
             {
                printf("  {%d", i);
                int num = i;
                while ((num = (num * i) % n) != 1)
                 {
                    printf(", %d", num);
                }
                    printf("} \n");
             }
          }
     printf("\n");
    }

    int main()
     {
        int nums[] = {8, 9, 18, 20, 25, 30, 50, 60};
        int nums_s = sizeof(nums) / sizeof(nums[0]);

        printf("your values are : ");
        for(int i=0;i<nums_s;i++)
        {
            printf("%d ",nums[i]);
        }
        printf("\n");
        for (int i = 0; i < nums_s; i++)
          {
            int n = nums[i];
            printf("\n IF n = %d:\n", n);
             if (generator(2, n))
              {
                printf("U(%d) is cyclic.\n", n);
                Generate_list(n);
                Subgroups(n);
              }
            else
                printf("U(%d) is not cyclic.\n", n);
          }
     return 0;
    }
