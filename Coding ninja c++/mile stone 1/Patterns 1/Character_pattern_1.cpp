/*Print the following pattern for the given N number of rows.
Pattern for N = 3
 A
 BB
 CCC
 */

#include<iostream>
using namespace std;


int main(){
    
    int N,row=1;
    char c='A';
    cin >> N;
    
    while(row<=N){
        int col=1;
        while(col<=row){
            cout << c;
            col=col+1;
        }
        row=row+1;
        c=c+1;
        cout << endl;
        }    
}