#include <iostream>
using namespace std ; 
int main(){
    int marks[5][3] ;
    int[] total(int marks[5][3]){
        int total_marks[5];
        for ( int i =0 ; i < 5; i++){
            total_marks[i] = 0 ;
            for ( int j = 0 ; j<3 ; j++){
                total_marks[i] += marks[i][j]; 
            }
        }
        return total_marks ; 
    }
    double[] avgMarks(int marks[5][3]){

    double avg_Marks[5];
    for( int i =0 ; i < 5; i++){
            avg_Marks[i] = 0 ;
            for ( int j = 0 ; j<3 ; j++){
                avg_Marks[i] += marks[i][j]/3; 
            }}
            return avg_Marks ; 
            }
    string a ; 
    for ( int i = 0 ; i < 5 ; i++){
        for ( int j = 0 ; j < 3 ; j++){
            cout << "Enter the marks : " << endl ;
            cin >> marks[i][j];
        }}
    cout << "Enter AVERAGE for average and TOTAL for total marks : - "<< endl ;
    cin >> a ; 
}



