#include <stdio.h>
#include<stdlib.h> 
int main()
{
int num,a[100], sum=0;
printf("Name : - Anushka Negi\n");
printf("Roll No:- 11\n");
printf("enter the number of element in the array you want :"); 
scanf("%d",&num);
printf(" enter the elements of array : \n"); 
for(int i=0;i<num;i++)
{
scanf("%d",&a[i]);
}
printf("the elements of array are : ");

for(int i=0;i<num;i++)
{
printf("%d ",a[i]);
}
printf("\n");
for(int i=0;i<num;i++)
{
for(int j=0;j<num-i-1;j++)
{
if(a[j]>a[j+1])
{
int temp=a[j]; a[j]=a[j+1]; a[j+1]=temp;
}
}
 
}
printf("\n after bubble sort array is : "); for(int i=0;i<num;i++)
{
printf("%d ",a[i]);
}
return 0;
}
