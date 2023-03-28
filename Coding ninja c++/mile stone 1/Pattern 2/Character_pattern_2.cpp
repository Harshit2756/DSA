/*Print the following pattern for the given N number of rows.
Pattern for N = 4
A
BC
CDE
DEFG
*/
#include<iostream>
using namespace std;


int main(){

    int N,row=1;
    char c;
    cin >> N;
   
    while(row<=N){
        int col=1;
        c=64+row;
        while(col<=row){
            cout << c;
            col=col+1;
            c=c+1;
        }
    row=row+1;
    cout << endl;
        }    
}