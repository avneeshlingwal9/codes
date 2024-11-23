#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void display(vector<int> pageTable, bool hit){
    cout << "Page table status: ";
    for (int i = 0; i < pageTable.size(); i++){
        cout << pageTable[i] << " "; 
    }
    if(hit){
        cout << "Page Hit ";
    }
    else{
        cout << "Page Miss "; 
    }
    cout << endl; 
}
int pageFCFS(vector<int> pagesRequired , int frames){
    vector<int> pageTable;
    int totalPageFaults = 0;
    bool hit = true;
    for(auto i : pagesRequired){
        if(find(pageTable.begin(), pageTable.end(), i) == pageTable.end()){
            hit = false;
            if(pageTable.size() == frames){
                pageTable.erase(pageTable.begin());
            }
            pageTable.push_back(i);
            totalPageFaults++;
        }
        else{
            hit = true;
        }
        display(pageTable, hit);
    }
    return totalPageFaults;
}
int main(){
    int totalPages;
    vector<int> pagesRequired; 
    cout << "Enter the total number of pages required: " << endl;
    cin >> totalPages;
    int currentPage = 0;
    cout << "Enter the page numbers: " << endl;
    for (int i = 0; i < totalPages; i++){
        cin >> currentPage;
        pagesRequired.push_back(currentPage);
    }
    cout << "Enter the number of frames for page table: " << endl;
    cin >> currentPage;
    cout << "Total number of page faults are: " << pageFCFS(pagesRequired, currentPage);
}