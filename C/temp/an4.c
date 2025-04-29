#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) { while (low <= high) {
int mid = low + (high - low) / 2;

if (arr[mid] == key) { return mid;
} else if (arr[mid] < key) { low = mid + 1;
} else {
high = mid - 1;
}
}

return -1;
}

int main() {
int n,key,arr[100];
printf("Name: - Anushka Negi\n");
printf("Roll No.: - 11\n");
printf("Enter the number of element in the array you want :"); scanf("%d",&n);
printf("Enter the elements of array : \n"); for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("The elements of array are : "); for(int i=0;i<n;i++)
 
{
printf("%d ",arr[i]);
}
printf("\n");

printf("Enter the element for search : "); scanf("%d",&key);
int result = binarySearch(arr, 0, n - 1, key); if (result != -1) {
printf("Element found at index %d\n", result);
} else {
printf("Element not found in the array\n");
}

return 0;
}


