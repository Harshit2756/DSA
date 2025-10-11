/*Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
    F(n) = F(n-1) + F(n-2), 
    Where, F(1) = F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.*/

#include<iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
        
    if(N==1 || N==2){
        cout << 1 << endl;
    }
    else{ 
        int  a1=1,a2=1,a3;
        for(int count=3;count<=N;count++){
        a3=a1+a2;
        a1=a2;
        a2=a3;
        
        if(count==N){
            cout << a3 <<endl;
        }
    	}
    }
    
}