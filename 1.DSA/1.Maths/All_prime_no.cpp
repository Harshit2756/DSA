/*Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.*/
#include <iostream>
using namespace std;

int main(){

    int N;
    
    cin >> N;
            
    for(int No=2;No<=N;No++){
        bool divide=true;
        for(int d=2;d<No;d++){
        	if(No%d==0){
            	divide=false;
            	break;
        	}
    	}
        
        if(divide){
            cout << No <<endl;
        }
    }
      
    
  
}


