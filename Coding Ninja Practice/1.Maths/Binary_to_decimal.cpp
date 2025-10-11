/*Given a binary number as an integer N, convert it into decimal and print.*/

#include<iostream>
using namespace std;

int main() {
	int N;
    cin >> N;
    int place_val=1,current_no,dec=0;
    while(N!=0){
        current_no=N%10;
        N=N/10;
        dec+=(current_no*place_val);
        place_val*=2;
    }
	cout << dec;
}
