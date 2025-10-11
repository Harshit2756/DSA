/*Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.
Note: The given input number could be large, so the corresponding binary number can exceed the integer range. So you may want to take the answer as long for CPP and Java.


Note for C++ coders: Do not use the inbuilt implementation of "pow" function. The implementation of that function is done for 'double's and it may fail when used for 'int's, 'long's, or 'long long's. Implement your own "pow" function to work for non-float data types.
*/

#include<iostream>
using namespace std;

int main() {
	int N;
    cin >>N;
    
    long int binary=0,place_val=1,current_no=0;
    while(N!=0){
        current_no=N%2;
        N=N/2;
        binary=(binary+(current_no*place_val));
        place_val*=10;
    }
	cout << binary;
}
