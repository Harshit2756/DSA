/*Print the following pattern for the given N number of rows.
Pattern for N = 4
4444
333
22
1
*/
#include<iostream>
using namespace std;


int main(){

	int row=1,N;
    int val=1;
	cin >> N;
    
    while(row<=N){
            
        int col=1;
        val=N-row+1;
        while(col<=val){
            cout << val;
            col++;
        }
        row++;
    	cout << endl;
        }
}