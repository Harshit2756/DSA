/*Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
4444
4444
4444
*/

#include<iostream>
using namespace std;


int main(){

    int N,row=1;
    cin >> N;
    while(row<=N){
        int col=1;
        while(col<=N){
            cout << N;
            col=col+1;
        }
    	cout << endl;
        row=row+1;
        }
    }
