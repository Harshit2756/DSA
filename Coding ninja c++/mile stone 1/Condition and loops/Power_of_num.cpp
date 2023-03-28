/*Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.
Note : For this question, you can assume that 0 raised to the power of 0 is 1*/
#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int x,n,i=1,mult=1;
    cin >> x >>n;
    
    if((x>=0 && x<=8)&&(n>=0 && n<=9)){
    	while(i<=n){
        	mult=mult*x;
            i=i+1;
    	}
        cout << mult;
    }
}
