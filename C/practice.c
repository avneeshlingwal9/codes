#include <stdio.h>
#include<string.h>
char* reverse(char a[]);
int main(){
    
    char s[]= "aasdf";
    char*l = reverse(s);

    printf("The original string is %s and reversed is %s", s,l);
    return 0 ;
}
char* reverse (char s[]){
    int j = strlen(s)-1 , i = 0 ;
    char b[j],c;
    for(int i = 0, j = strlen(s)-1 ; i < strlen(s);i++,j--){
        c = s[i];
        b[j]=c;

    }
    return *b ;

}
