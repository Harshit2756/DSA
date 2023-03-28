/*Print the following pattern for the given N number of rows.
Pattern for N = 4
1
21
321
4321
*/
#include<iostream>
using namespace std;


int main(){

      int N,row=1,val=1;
    cin >> N;
   
    while(row<=N){
        int col=1;
        val=row;
        while(col<=row){
            cout << val;
            col=col+1;
            val=val-1;
        }
        row=row+1;
        cout << endl;
        }      
}