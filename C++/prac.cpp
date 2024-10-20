#include <iostream>
#include <fstream>
using namespace std ;
int countVowels();
int main(){
    string l ;
    string vowels = "AEIOUaeiou";
    int count = 0 ;
    ofstream k ; 
    k.open("n.txt");
    while(k){
        cout << "Enter the lines of the file :- " << endl ;
        getline(cin,l);

        if ( l == "-1"){
            break;
        }
        k << l << endl ;
    }
    k.close();
    cout << countVowels() << endl ;


}
int countVowels(){
        ifstream m ; 
        m.open("n.txt");
        int count = 0 ;
        string l ;
        string vowels = "aeiou";

    while(getline(m,l)){
        for ( int i = 0 ; i < l.length();  i++){
            if (l[i]==vowels[0]){
                count+=1 ;
            }
            else if ( l[i]==vowels[1]){
                count+=1;
            }
            else if (l[i]==vowels[2]){
                count+=1;
            }
            else if( l[i]==vowels[3]){
                count +=1;
            }
            else if( l[i]== vowels[4]){
                count+=1;
            }
            else if ( l[i]==vowels[5]){
                count+=1;
            }
            else if (l[i]==vowels[6]){
                count+=1;
            }
            else if( l[i]==vowels[7]){
                count +=1;
            }
            else if( l[i]== vowels[8]){
                count+=1;
            }
            else if ( l[i]== vowels[9]){
                count+=1 ; 
            }


        }}
        return count ;
    
    }