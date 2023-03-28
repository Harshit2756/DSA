/*Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5
..*
.***
*****
.***
..*

*/
#include<iostream>
using namespace std;


int main() {
    
    int row=1,N,extra=0;
    cin >> N;
    
    int N_1=(N+1)/2;
    
    
    while(row<=N_1){
        
        int space =1;
        while(space<=(N_1-row)){
            cout << " ";
            space++;
        }
        
        int star=1;
        int total_stars=row +extra;
        while(star<=total_stars){
            cout << "*";
            star++;
        }
        extra++;
        row++;
        cout << endl;
    }
    
    int Row=1;
    int N_2=(N-1)/2;
    
    while(Row<=N_2){
        
        int space=1;
        while(space<=Row){
            cout << " ";
            space++;
        }
        
        int star=1;
        while(star<=(N-2*Row)){
            cout << "*";
            star++;
        }
        Row++;
        cout << endl;
    }    
}