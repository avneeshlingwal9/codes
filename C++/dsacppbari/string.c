#include <stdlib.h>
#include <stdio.h>
static int available[10] = {0};
 static char res[10];
 void swp(char *a , char *b){
     char t = *a;
     *a = *b;
     *b = t;
} 
int len(char arr[]){
    int i = 0;
    for (; arr[i]!='\0'; i++){
        
    }
    return i; 
}
void upperToLowerCase(char arr[]){
    int i = 0;
    for (; arr[i] != '\0'; i++){
        arr[i] += 32;
    }
    printf("\n%s", arr);
}
void lowerToUpperCase(char arr[]){
    int i = 0;
    for (; arr[i] != '\0'; i++){
        arr[i] -= 32;
    }
    printf("\n%s", arr);
}
void toggle(char arr[]){
    int i = 0;
    for (; arr[i] != '\0'; i++){
        if(arr[i]>= 'A' && arr[i] <= 'Z'){
            arr[i] += 32;
        }
        else if(arr[i] >='a' && arr[i] <= 'z'){
            arr[i] -= 32;
        }
    }
    printf("\n%s", arr);
}
void vowelconscount(char arr[]){
    int i = 0, vcount = 0, ccount = 0;
    for (; arr[i] != '\0'; i++){
        if(arr[i] =='a' || arr[i] =='e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] =='u' ||arr[i] =='A' || arr[i] =='E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] =='U'  ){
            vcount++;
        }
        else if((arr[i]>= 'A' && arr[i]<='Z')|| (arr[i] >= 97 && arr[i] <=122 )){
            ccount++;
        }
    }
    printf("The number of consonants and vowels in the string is: %d %d ", ccount, vcount);
}
void wordcount(char arr[]){
    int i = 0, words = 1;
    for (; arr[i] != '\0'; i++){
        if(arr[i] == ' ' && arr[i-1] != ' '){
            words++; 
        }
    }
    printf("%d", words);
}
int validate(char arr[]){
    for (int i = 0; arr[i] != '\0'; i++){
        if(!(arr[i] >=65 && arr[i] <= 90 )&& !(arr[i]>= 97 && arr[i]<= 122) && !(arr[i]>=48 && arr[i]<=57)){
            return 0; 
        }
    }
    return 1;
}
char* reversehelp(char arr[]){
    int i, j;
    char *B ;
    i = len(arr)-1;
    for (j = 0; i >= 0; i--,j++){
        B[j] = arr[i];
    }
    B[j] = '\0';
    return B; 
}
void reverseself(char arr[]){
    int j = len(arr) - 1, i;
    char t;

    for (i = 0; i < j; i++,j--){
        t = arr[j];
        arr[j] = arr[i];
        arr[i] = t; 
    }

}
int palindrome(char arr[]){
    int i = 0, j = len(arr) - 1;
    for (; i <= j; i++,j--){
        if(arr[i] != arr[j]){
            return 0;
        }
    }
    return 1;
}
void compare(char arr[], char brr[]){
    int i = 0, j = 0;
    for (; arr[i] != '\0' && brr[j] != '\0'; i++,j++){
        if(arr[i]!= brr[j]){
            break;
        }
    }
    if(arr[i] == brr[j]){
        printf("Both are equal");

    }
    else if(arr[i] < brr[j]){
        printf("First one is smaller");
    }
    else{
        printf("First one is greater");
    }
}
void findduplicate(char arr[]){
    int count;
    int n = len(arr);
    for (int i = 0; i < n - 1; i++){
        count = 1;
    
        if(arr[i] != '0'){
            for (int j = i + 1; j < n; j++){
                if(arr[i] == arr[j]){
                    count++;
                    arr[j] = '0';
                }
            }
            if(count > 1){
                printf("\n%c is duplicated %d times", arr[i], count);
            }
        }
    }
}
void findduplicatehashlowercase(char arr[]){

    char H[26] = {0};
    for (int i = 0; arr[i] != '\0';i++){
        H[arr[i] - 97]++;
    }
    for (int i = 0; i < 26; i++){
        if(H[i]> 1){
            printf("\n%c has %d appearances", i + 97, H[i]);
        }
    }
}
void finduplicatesbit(char arr[]){
    int H = 0, x;
    for (int i = 0; arr[i]!= '\0'; i++){
        x = 1;
        x = x << (arr[i] - 97); 
        if((x & H) > 0){
            printf("\n%c is duplicated ", arr[i]);
        }
        else{
            H = x | H;
        }
    }
}
void checkanagram(char arr[], char brr[]){
    int i = 0, H[26] = {0};
    for (; arr[i] != '\0'; i++){
        H[arr[i] - 97] ++;
    }
    for (i = 0; brr[i] != '\0'; i++){
        H[brr[i] - 97]--;
        if(H[brr[i]-97]<0){
            printf("Not anagram definitely ");
            break;
            
            
        }
    }
    if(brr[i]=='\0'){
        printf("Anagram definitely");
    }
}
void perm(char s[], int k){
    
    if(s[k] == '\0'){
        res[k] == '\0';
        printf("\n%s", res);
        
    }
    else{
        for (int i = 0; s[i] != '\0'; i++){
            if(available[i] == 0){
                res[k] = s[i];
                available[i] = 1; 
                perm(s, ++k);
                available[i] = 0;
            }
        }

    }
}
void Perm(char arr[],int l , int h ){
    if(l==h){
        printf("\n%s", arr);
    }
    else{
    for (int i = l; i <= h; i++){
        swp(&arr[i], &arr[l]);
        Perm(arr, l + 1, h);
        swp(&arr[l], &arr[i]);
    }}

}
int main(){ 
    char arr[40] = "abc";
    char brr[40] = "saano";
    Perm(arr,0,2);
}