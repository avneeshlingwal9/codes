#include <stdio.h>
#include <string.h>
int main(){
    FILE *fpointer ;
    char data[200] , b; 
    int c = 0 , v = 0 ; 
    fpointer = fopen("ThreeParas.txt","w");
    if ( fpointer != NULL){
        for( int i = 0 ; i < 3 ; i++){
            printf("Enter the contents of the paragraph.\n");
            fgets(data , sizeof(data),stdin);
            fputs(data,fpointer);
            fputs("/n",fpointer);
        }
    }
    fclose(fpointer);
    fpointer = fopen("ThreeParas.txt","r");
    while ( fgets(data , 200 , fpointer) != NULL){
        while(fgetc(fpointer)!= '){
            if ( b == 'a' or b =='e' or b =='i' or b =='u' or b =='u'){
                v+=1 ; 
            }
            else {
                c+=1 ; 
            }

        }
    fclose(fpointer);

    }
    printf("Vowels %d and Constonants %d" , v , c );


    return 0 ; 
    }