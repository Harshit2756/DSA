/*Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.*/

#include<iostream>
using namespace std;

int main() {
	int x;
    cin >> x;
    int count=1,val;
        
    for(int i=1;i<=x;i++){
        val=((3*count)+2);
        count++;
        if(val%4==0){
            i--;
            continue;
        }
        else {
         cout << val << " ";   
        } 
        
    }
}
