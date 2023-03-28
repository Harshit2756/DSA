/*Print the following pattern for the given number of rows.
Pattern for N = 5
E
DE
CDE
BCDE
ABCDE
*/

#include<iostream>
using namespace std;


int main() {
    
    int N,row=1;
    char c;
    cin >> N;
    while(row<=N){
        int col=1;
        c=65-row+N;
        while(col<=row){
            cout << c;
            col=col+1;
            c=c+1;
        }
	row=row+1;
    cout << endl;
        }    
}