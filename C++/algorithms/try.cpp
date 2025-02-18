#include <bits/stdc++.h>
using namespace std;

long long countPairs(long long **poin, int start, int mid, int end)
{
    long long *arr = *poin;
    long long count = 0;
    int j = mid + 1;
    for (int i = start; i <= mid; i++)
    {
        while (j <= end && arr[j] < arr[i])
        {
            j++;
        }
        count += (j - mid + 1);
    }
    return count;
}
void merge(long long **poin, int start, int mid, int end)
{
    long long *arr = *poin;
    long long *temp = new long long[end - start + 1];
    int k = 0;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int s = start; s <= end; s++)
    {
        temp[s - start] = arr[s];
    }
    delete temp;
}
long long mergeSort(long long **poin, int start, int end)
{
    long long *arr = *poin;
    if (start >= end)
    {
        return 0;
    }
    long long mid = (start + end) / 2;

    int count = 0;
    count += mergeSort(&arr, start, mid);
    count += mergeSort(&arr, mid + 1, end);
    count += countPairs(&arr, start, mid, end);
    merge(&arr, start, mid, end);
    return count;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergeSort(&arr, 0, n - 1);
}
int main(){
    long long arr[] = {1052244275,123047899,493394237,922363607,378906890,188674257,222477309,902683641,860884025,339100162};
    long long  ans = getInversions(arr, 10);
    cout << ans << endl;
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " "; 
    }
}