/*Print the following pattern
Pattern for N = 4
...*
..***
.*****
*******


The dots represent spaces.*/

/*i=row no.
    j= counts the number of elements in the i th row
    k= the no of spaces to print
    s=no.of stars
    a= no of new(extra element in each rows )(as the no of elment in each row =n )
    	s	a	i
 		1 = 0 + 1  
       	3 = 1 + 2
        5 = 2 + 3
    */

#include<iostream>
using namespace std;

int main(){

   	int row=1,N;
	cin >>N;
    int a=0;
    int total_star;
    
    while(row<=N){
        int space=1;
        while(space<=(N-row)){
            cout<<" ";
            space=space+1;
        }
        
        int count=1;
        total_star=row+a;
        while(count<=total_star){
			cout <<"*";
         	count=count+1;
        } 
        a=a+1;
        
    	row=row+1;  
    	cout <<endl;
    }  
}