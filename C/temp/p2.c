#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *sourceFile, *destFile;
    char source[100], dest[100];
    int n ; 
    sourceFile = fopen("sn.txt", "w");
    if (sourceFile != NULL) {
        printf("Enter the number of lines you want to put : - ");
        for ( int i= 0 ; i < n ; i++){
        printf("Enter the content and enter 0 to exit \n");
        fgets(source,100,stdin);
        fputs(source, sourceFile);    
    }
    destFile = fopen("d.txt", "w");
    if (destFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
    }
    int ch;
    int prevChar = ' ';
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (!isspace(ch)) {
            if (!isspace(prevChar))
                fputc(' ', destFile);
            fputc(ch, destFile);
        }
        prevChar = ch;
    }
    fclose(sourceFile);
    fclose(destFile);
    destFile = fopen("d.txt", "r");
    if (destFile == NULL) {
        printf("Failed to open the destination file.\n");
    }

    printf("Content of the copied file:\n");
    while ((ch = fgetc(destFile)) != EOF) {
        putchar(ch);
    }

    fclose(destFile);

    return 0;
}
