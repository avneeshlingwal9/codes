#include <iostream>
#include <vector>
#include <map>

using namespace std ;

int main(){
    vector <int> g ;
    int n ;
    cout << "Enter the elements of the vector : " << endl ; 
    for(int i = 0 ; i < 5; i++){
        cin >> n ;
        g.push_back(n); // Inserting the element
        
    }
    g.pop_back(); // Deleting the element.
    for(auto i  = g.rbegin(); i < g.rend(); ++i ){ 
        cout << *i << " " ;
    }

}