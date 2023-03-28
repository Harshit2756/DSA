/*Print the following pattern for the given N number of rows.
Pattern for N = 4
...1
..12
.123
1234
*/#include<iostream>
using namespace std;


int main(){

    int N,row=1;
    cin >> N;

	while(row<=N){
        int col=1;
        while(col<=N-row){
            cout << " ";
            col++;
        }
        int No=1;
        while(col<=N){
            cout << No;
			No++;
            col++;
        }
        row++;
        cout << endl;
    	}  
}