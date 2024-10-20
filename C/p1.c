#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    FILE *file = fopen("ThreeParas.txt", "w");
    int consonantCount  = 0 , vowelCount = 0 ; 
    if (file == NULL) {
        printf("Failed to create the file.\n");
    }

    char paragraph[1000];
    int paragraphCount = 0;
    while (paragraphCount < 3) {
        printf("Enter paragraph:\n");
        fgets(paragraph, sizeof(paragraph), stdin);
        fputs(paragraph, file);
        paragraphCount++;
    }

    fclose(file);

    printf("Contents of the file:\n");
    file = fopen("ThreeParas.txt", "r");
    if (file != NULL) {
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c",ch);
    }}

    fclose(file);

    printf("\n\nFrequency of consonants and vowels in each paragraph:\n");
    file = fopen("ThreeParas.txt", "r");
    if (file != NULL) {
    

    char line;
    while ((line = fgetc(file)) != EOF) {
        char c = toupper(line);
        if ((c >= 'A' && c <= 'Z') && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c!= 'U'){
            consonantCount++;}
        else if ( ( c=='A' || c =='E' || c == 'I' || c == 'O' || c == 'U')){
            vowelCount++;
    
    }}
    printf("The number of consonants is %d and vowels is %d",consonantCount , vowelCount);

    return 0;
}
}