#include <stdio.h>
 #include<stdlib.h> 
 int main()
{
int num,a[100], sum=0;
printf("Name :- Anuhska Negi\n");
printf("Roll No. :- 11\n");
printf("Enter the number of element in the array you want :");
 scanf("%d",&num);
printf("Enter the elements of array :"); 
for(int i=0;i<num;i++)
{
scanf("%d",&a[i]);
}
printf("The elements of array are : ");

for(int i=0;i<num;i++)
{
printf("%d ",a[i]);
}
printf("\n");
for(int i=0;i<num;i++)
{
int min=i;
for(int j=i+1;j<num;j++)
{
if(a[min]>a[j])
{
min=j;
}
}
int temp=a[min];
 
a[min]=a[i]; a[i]=temp;
}
printf("\n After selection sort array is : "); for(int i=0;i<num;i++)
{
printf("%d ",a[i]);
}
return 0;
}

