/*
1
23
345
4567*/

#include<iostream>
using namespace std;


int main(){

   	int i=1,N;
	cin >>N;
    int val=1;
    
    while(i<=N){
        int j=1;
        val=i;
        while(j<=i){
			cout <<	val;
         	j=j+1;
            val=val+1;
    	}
    	i=i+1;  
    	cout <<endl;
    }  
}