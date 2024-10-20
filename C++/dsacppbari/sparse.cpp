#include <iostream>
using namespace std; 
struct Element{
    int i;
    int j;
    int x;

};
class Sparse{
    private:
        int m;
        int n;
        int num;
        Element *e; 
    public:

    Sparse(int m , int n , int num){
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[num];
    }
    ~Sparse(){
        delete[] e; 
    }
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
    Sparse operator+(Sparse &s);
};

istream &operator>>(istream &is , Sparse &s){
    cout << "Enter the elements " << endl; 
    for (int i = 0; i < s.num; i++ ){
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}
ostream & operator<<(ostream &os , Sparse &s){
    int k = 0;
    for (int i = 0; i < s.m; i++){
        for (int j = 0; j < s.n; j++){
            if(s.e[k].i == i && s.e[k].j == j){
                cout << s.e[k++].x << " ";
            }
            else{
                cout << "0 "; 
            }
        }
        cout << endl; 
    }
    return os; 
}
int main(){
    Sparse s(5,5,5);
    cin >> s;
    cout << s;
}