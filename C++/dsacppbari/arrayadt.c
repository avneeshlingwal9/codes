#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swp(int*a , int*b){
    int c = *a;
    *a = *b;
    *b = c; 
}
struct Array{
    int *A; 
    
    int size;
    
    int length; 
};
void display(struct Array arr){
    int l = arr.length;
    printf("\nElements of the array are: ");
    for (int i = 0; i < l; i++){
        printf( " %d ", arr.A[i]);
    }
}
void append(struct Array *arr, int x){
    
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}
void insert(struct Array *arr , int index , int x){
    if(index>= 0 && index <= arr->length){
    for (int i = arr->length; i >= index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;}
}
int dlete(struct Array *arr , int index){
    int x = 0;
    if(index >=0 && index < arr->length){
         x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++){
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return x;
}
int linearSearch(struct Array *arr,int key){
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == key ){
            return i;
        }

    }
    return -1;
}
int linearSearchtransposition(struct Array* arr,int key){
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == key ){
            swp(&(arr->A[i]), &(arr->A[i - 1]));
            return i-1;
        }

    }
    return -1;
}
int linearSearchmoveFront(struct Array *arr,int key){
    for (int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == key ){
            swp(&(arr->A[0]), &(arr->A[i]));
            return 0;
        }

    }
    return -1;
}
int ibinarySearch(struct Array arr , int k ){
    int l = 0, h = arr.length - 1;
    while(l<=h){
        int mid = (l+h)/2 ; 
        if(arr.A[mid]== k){
            return mid; 
        }
        else if(arr.A[mid] > k){
            h = mid - 1; 
        }
        else{
            l = mid + 1; 
        }

    }
    return -1; 
}
int rbinarySearch(int arr[], int l  , int h , int k ) {
    if(l <= h){
        int mid = (l + h) / 2; 
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid] > k ){
            return rbinarySearch(arr, l, mid - 1, k);
        }
        else {
            return rbinarySearch(arr, mid + 1, h, k);
        }

    }
    return -1;
}
int get(struct Array arr , int index){
    if(index>=0 && index < arr.length){
        return arr.A[index];
    }
    return -1; 
}
void set(struct Array* arr , int index , int element){
    if(index>=0 && index < arr->length){
        arr->A[index] = element;
    }
}
int max(struct Array arr){
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max; 
}
int min(struct Array arr){
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min; 
}
int isum(struct Array arr){
    int total = 0;
    for (int i = 0; i < arr.length; i++){
        total += arr.A[i];
    }
    return total;
}
int rsum(struct Array arr, int n){
    if(n < 0){
        return 0; 
    }
    return rsum(arr, n - 1) + arr.A[n];
}
float avg(struct Array arr){
    return (float)isum(arr) / arr.length; 
}
void reverseaux(struct Array* arr){
    int *B = (int *)malloc(arr->length * sizeof(int));

    for (int i = arr->length - 1, j = 0; j < arr->length; i-- , j++){
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++){
        arr->A[i] = B[i];
    }
    free(B);
}
void reverse(struct Array* arr){
    for (int i = 0, j = arr->length - 1; i < j;i++ , j-- ){
        swp(&(arr->A[i]), &(arr->A[j]));
    }
}



void leftshift(struct Array* arr){
    for (int i = 1; i < arr->length ; i++){
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = 0; 
}
void leftrotate(struct Array* arr){
    int f = arr->A[0];
    for (int i = 1; i < arr->length ; i++){
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = f;
}

void rightshift(struct Array* arr){
    for (int i = arr->length; i >0 ; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0; 
}
void rightrotate(struct Array* arr){
    int l = arr->A[arr->length - 1];
    for (int i = arr->length; i >0 ; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = l;
}
bool isSorted(struct Array arr){
    int i = 0;
    for (i = 0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0; 
        }
    }

    return 1;
}
void insertS(struct Array* arr , int n){
    int i = arr->length - 1; 
    if(arr->length == arr->size){
        return; 
    }

    while(i >=0 && n < arr->A[i]){
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = n;
    arr->length++;
}
void swapleft(struct Array* arr ){
    int i = 0, j = arr->length - 1; 
    while(i < j ){
        while(arr->A[i] <0 ){
            i++;
        }
        while(arr->A[j]>= 0 ){
            j--; 
        }
        if(i < j ){
            swp(&arr->A[i], &arr->A[j]);
        }
    }
}
void swapright(struct Array* arr ){
    int i = 0, j = arr->length - 1; 
    while(i < j ){
        while(arr->A[i] >=0 ){
            i++;
        }
        while(arr->A[j]< 0 ){
            j--; 
        }
        if(i < j ){
            swp(&arr->A[i], &arr->A[j]);
        }
    }
}
struct Array* merge(struct Array arr1 , struct Array arr2  ){
    int i = 0, j = 0, k = 0, m = arr1.length,
    n = arr2.length;
    struct Array* c = (struct Array *)malloc(sizeof(struct Array));
    c->length = 0;
    c->size = m + n;
    
    c->A = (int *)malloc(c->size * sizeof(int));
    while(i < m && j < n){
        if(arr1.A[i] < arr2.A[j]){
            c->A[k++] = arr1.A[i++];
        }
        else{
            c->A[k++] = arr2.A[j++];
        }
    }
    for (; i < m; i++){
        c->A[k++] = arr1.A[i];
    }
    for (; j < n; j++){
        c->A[k++] = arr2.A[j];
    }
    c->length = k; 
    return c;
}
int tlinearsearch(struct Array arr , int key){
    int r = 0;
    for (int i = 0; i < arr.length; i++){
        if(arr.A[i] == key){
            return 1; 
        }
    }
    return 0;
}
struct Array* ununion(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length , i = 0 , j= 0 , k = 0 ;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    for (; i < m; i++){
        c->A[k++] = arr1.A[i];
    }
    c->length = k; 

    for (; j < n; j++){
        if(! tlinearsearch(*c,arr2.A[j]))
        {
            c->A[c->length++] = arr2.A[j];
        }

    }
    return c;
}
struct Array* uninter(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length , i = 0 ;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    for (; i < m; i++){
        if(tlinearsearch(arr2,arr1.A[i]))
        {
            c->A[c->length++] = arr1.A[i];
        }
    }

    
    return c;
}
struct Array* undiffer(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length, i = 0;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    for (; i < m; i++){
        if(!tlinearsearch(arr2,arr1.A[i]))
        {
            c->A[c->length++] = arr1.A[i];
        }
    }

    
    return c;
}
struct Array* sounion(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length, i = 0, j = 0, k = 0;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    while(i < m && j < n ){
        if(arr1.A[i] == arr2.A[j]){
            c->A[c->length++] = arr1.A[i++];
            j++;
        }

        else if(arr1.A[i] < arr2.A[j]){
            c->A[c->length++] = arr1.A[i++];
        }
        else{
            c->A[c->length++] = arr2.A[j++];
        }
    }
    while(i < m){
        c->A[c->length++] = arr1.A[i++];
    }
    while(j< n){
        c->A[c->length++] = arr2.A[j++];
    }
    return c; 
}
struct Array* sointer(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length, i = 0, j = 0, k = 0;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    while(i < m && j < n ){
        if(arr1.A[i] == arr2.A[j]){
            c->A[c->length++] = arr1.A[i++];
            j++;
        }

        else if(arr1.A[i] < arr2.A[j]){
            i++;
        }
        else{
            j++;
        }
    }
   
    return c; 
}
struct Array* sodiffer(struct Array arr1 , struct Array arr2){
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    int m = arr1.length, n = arr2.length, i = 0, j = 0, k = 0;
    c->size = m + n;
    c->length = 0;
    c->A = (int *)malloc(c->size * sizeof(int));
    while(i < m && j < n ){
        if(arr2.A[j] < arr1.A[i]){
            
            j++;
        }

        else if(arr1.A[i] ==arr2.A[j]){
            i++;
            j++;
        }
        else{
            c->A[c->length++] = arr1.A[i++];
        }
    }
    for (; i < m; i++){
        c->A[c->length++] = arr1.A[i++];
    }
    return c;

    }
void missingsrt(struct Array arr1 , int n){
    int s = n*(n+1)/2 ;
    int sum = 0;
    for (int i = 0; i < n - 1; i++){
        sum += arr1.A[i];
    }
    printf("The missing element is %d ", s - sum);
}
void missingsrtanother(struct Array arr1 , int n ){
    int diff = arr1.A[0]-0 ;
    for (int i = 1; i < n; i++){
        if(arr1.A[i] - i != diff ){
            while(diff!= arr1.A[i]-i){
                printf("The missing element is %d ", diff+i);
                diff++; 
            }
        }
    }
}
void missingunsort(struct Array arr1 , int n ,int l , int h ){
    int flag; 
    for (int i = l; i <=h ; i++){
        flag = 0;
        for (int j = 0; j < n ; j++){
            if(arr1.A[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            printf("\nThe missing element is %d ", i);
        }
        
    }
} 
void missingunsorthash(struct Array arr1 , int n , int l , int h ){
    int H[h] = {0};
    for (int i = 0; i < n; i++){
        H[arr1.A[i]]++;
    }
    for (int j = l; j <= h; j++){
        if(H[j] == 0 ){
            printf("\nThe missing element is %d ", j); 
        }
    }
}
void findandcountuplicatessorted(struct Array arr1 , int n ){
    

    
    for (int i = 0; i < n - 1; i++){
        if(arr1.A[i] == arr1.A[i+1]){
            
            int j = i + 1;
            while(arr1.A[i]==arr1.A[j]){
                j++;

            }
            printf("\nNumber of %d is %d ", arr1.A[i], j-i);
            i = j - 1;
        }
    }
}
void findduplicatessorted(struct Array arr , int n){
    int lastDuplicate = -1;
    for (int i = 0; i < n - 1; i++){
        if(arr.A[i] == arr.A[i+1] && arr.A[i] != lastDuplicate){
            printf("\n%d is duplicate ", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
}
void finduplicateandcountunsorted(struct Array arr , int n ){
    int count = 1;
    for (int i = 0; i < n - 1; i++){
        if(arr.A[i] != -1){
        for (int j = i + 1; j < n; j++){
            if(arr.A[j] == arr.A[i]){
                arr.A[j] = -1; 
                count++; 
            }
        }
        if(count >1) printf("\n%d has appeared %d times. ", arr.A[i],count );}
        count = 1;
     
     }
}
void finduplicatesandcountunsortedhashing(struct Array arr , int n , int max , int min){
    int H[max + 1] = {0};
    for (int i = 0; i < n; i ++){
        H[arr.A[i]]++;
    }
    for (int j = min; j <= max; j++){
        if(H[j] >1 ){
            printf("%d has appeared %d times.", j, H[j]);
        }
    }
}
void sumpairsorted(struct Array arr , int n , int k ){
    for (int i = 0, j = n - 1; i < j;){
        if(arr.A[i]+arr.A[j] == k){
            printf("\n%d + %d = %d ", arr.A[i],arr.A[j],k);
            i++;
            j--;
        }
        else if(arr.A[i]+arr.A[j] > k){
            j--;
        }
        else{
            i++;
        }
    }
}
void sumpairunsorted(struct Array arr , int n , int k ){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(arr.A[i]+arr.A[j]==k){
                printf("%d + %d = %d ", arr.A[i], arr.A[j], k);
            }
        }
    }
}
void sumpairunsortedhashing(struct Array arr , int n , int k, int max){
    int H[max + 1] = {0};
    for (int i = 0; i < n; i++){
        if(H[k- arr.A[i]] == 1){
            printf("%d + %d = %d ", arr.A[i], k - arr.A[i], k);
        }
        H[arr.A[i]]++;
    }
}
void maxmin(struct Array arr , int n){
    int min = arr.A[0];
    int max = arr.A[0];
    for (int i = 0; i < n; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
        else if(arr.A[i]> max){
            max = arr.A[i];
        }
    }
    printf("Max and min elements are %d and %d ", max, min);
}

int main()
{
    struct Array arr ;
    
int index , x , ch ; 
     printf("Enter the size of the array : ");
     scanf("%d", &arr.size);
     arr.length = 0;
     arr.A = (int *)malloc(sizeof(int) * arr.size);
     for (int i = 0; i < 10; i++){

         printf("Enter the elements: ");
         scanf("%d", &arr.A[i]);
         }
             /*do{
                 printf("\n\nMenu\n");
                 printf("1. Insert\n");
                 printf("2. Append\n");
                 printf("3. Delete\n");
                 printf("4. Search\n");
                 printf("5. Display\n");
                 printf("6. Exit\n");

                 printf("Enter your choice : ");
                 scanf("%d", &ch);
                 switch (ch)
                 {
                    case 1 :
                        printf("Enter index and value of the element: ");
                        scanf("%d%d", &index, &x);
                        insert(&arr, index, x);
                        break;
                    case 2:
                        printf("Enter value of the element: ");
                        scanf("%d", &x);
                        append(&arr, x);
                        break;
                    case 3 :
                        printf("Enter the index of the element you want to delete: ");
                        scanf("%d", &index);
                        printf("Deleted element is %d ", dlete(&arr,index));
                        break;
                    case 4 :
                        printf("Enter the element you want to search : ");
                        scanf("%d", &x);
                        printf("Element %d found at %d ", x,linearSearch(&arr,x) );
                        break;
                    case 5 :
                        display(arr);
                        break;
                    default :
                        printf("Bad request uhuh");
                        break;
             }} while (ch < 6);*/

         maxmin(arr, 10);
         free(arr.A);

         return 0;
}