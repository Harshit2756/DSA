#include<iostream>
using namespace std;


int main(){
    int start, end, step;
    cin >> start >> end >> step;
  
    printTable(start, end, step);

}

void printTable(int start, int end, int step) {
    while(start<=end){
        int C=((start-32)*5)/9;
        cout << start<<" "<< C<<endl;
        
        start+=step;
    }
    
}




