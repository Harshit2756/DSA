/*Print the following pattern
Pattern for N = 4
...1
..23
.345
4567


The dots represent spaces.*/

#include<iostream>
using namespace std;

int main(){
    //i=row no.
    //j= Number of numbers to print
    //k= the no of spaces to print
    
   	int row=1,N;
	cin >>N;
    int val=1;
    
    
    while(row<=N){
        int space=1;
        while(space<=(N-row)){
            cout<<" ";
            space=space+1;
        }
        
        val=row;
        int element=1;
        while(element<=row){
			cout <<	val;
         	element=element+1;
            val=val+1;
    	}
    	row=row+1;  
    	cout <<endl;
    }  
}