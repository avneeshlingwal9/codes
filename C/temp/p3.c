#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *f ,*d ; 
    int n ; 
    printf("Enter the number of lines you want : - " );
    scanf("%d",&n);
    char s[300],g[300];
    f = fopen("k.txt","w");
    for ( int i =0 ; i < n+1; i++){
        fgets(s,300,stdin);
        fputs(s,f);
    }
    fclose(f);
    f = fopen("k.txt","r");
    d = fopen("d.txt","w");
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        if (!isspace(ch)) {
            fputc(ch, d);
        }
    }
    fclose(f);
    fclose(d);
    d = fopen("d.txt","r");
    printf("Contents of the copied file are : - ");
    while((ch = fgetc(d))!= EOF){
        printf("%c",ch);
    }
    return 0 ; 
}