/*Print the following pattern for the given N number of rows.
Pattern for N = 4
*
**
***
****
*/

#include<iostream>
using namespace std;


int main(){

    int N,row=1;
    cin >> N;
   
    while(row<=N){
        int col=1;
        while(col<=i){
            cout << "*";
            col=col+1;
        }
        row=row+1;
        cout << endl;
        }     
}