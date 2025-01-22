#include <iostream>
#include <string>
using namespace std ;
class student {
    private :
        string name , sub_1,sub_2,sub_3,sub_4 ;
        int sub1marks , sub2marks,sub3marks , sub4marks ;
    public : 
        student(){
            cout << "Enter your name : - "<< endl ;
            getline(cin,name);
            cout << "Enter the name of the subject : - " << endl ; 
            cin >> sub_1 ; 
            cout << "Enter the marks in" << sub_1 << " :- "<< endl ;
            cin >> sub1marks ; 
            cout << "Enter the name of the subject : - " << endl ;
            cin >> sub_2 ;
            cout << "Enter the marks in" << sub_2 << ":- "<< endl ;
            cin >> sub2marks ;
            cout << "Enter the name of the subject : - " << endl ;
            cin >> sub_3 ;
            cout << "Enter the marks in" << sub_3 << ":- "<< endl ;
            cin >> sub3marks ; 
            cout << "Enter the name of the subject : - " << endl ;
            cin >> sub_4;
            cout << "Enter the marks in" << sub_4 << ":- "<< endl ; 
            cin >> sub4marks ;           
        }
        int sum(){
            return ( sub1marks+sub2marks + sub3marks + sub4marks );
        }
        int percentage(){
            return (sum()/4);
        }
        string grade(int mrk ){
            if(mrk > 95){
                return "A+";
            }
            else if(95 >= mrk > 90 ){
                return "A";
            }
            else if(90 >= mrk > 85){
                return "B+";
            }
            else if(85>= mrk > 80 ){
                return "B";
            }
            else if (80 >= mrk > 75){
                return "C+";
            }
            else if( 75>= mrk > 70 ){
                return "C";
            }
            else if ( 70 >= mrk > 65){
                return "D+";
            }
            else if (65>= mrk >60){
                return "D";
            }
            else if ( 60 >= mrk >55){
                return "E+";
            }
            else if (55 >= mrk > 50 ){
                return "E";
            }
            else if (50 >= mrk > 45){
                return "F+";
            }
            else if (45>= mrk > 40 ){
                return "F";
            }
            else if( 40 >= mrk > 35){
                return "G";
            }
            else {
                return "fail";
            }
        }
        string stgrade(string subj)
        {
            if (subj == sub_1){
                return grade(sub1marks);
            }
            else if ( subj == sub_2){
                return grade (sub2marks);
            }
            else if ( subj == sub_3){
                return grade(sub3marks);
            }
            else if ( subj == sub_4){
                return grade(sub4marks);
            }
            else {
                return " Enter a valid subject please " ;  
            }
        }
        string tgrade(){
            return grade(sum());
        }
};



int main(){
    student s_1;
    string choice ; 
    cout << "Enter \n " 
    << "sm for total sum of marks .  \n"
    << "prct for percentage . \n "
    << "sgrade and subject name  for particular subject grade\n"
    << "overall for overall grade \n" ; 
    cout << "Enter what you want to know : - " << endl ;
    cin >> choice ; 
    if ( choice == "sm" ){
        cout << "The sum is :- " << s_1.sum() << endl ; 
    }
    else if ( choice == "prct"){
        cout << "The percentage is : - " << s_1.percentage() << endl ; 

    }
    else if ( choice == "sgrade"){
        string sbj ;
        cout << "Enter the name of the subject : - "<< endl ; 
        cin >> sbj ;
        cout << "The grade in the subject is : - " << s_1.stgrade(sbj) << endl ; 
    }
    else if ( choice =="overall"){
        cout << "The total grade is : - " << s_1.tgrade() << endl ; 
    }
    return 0 ;
}