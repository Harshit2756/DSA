/*Print the following pattern for the given number of rows.
Pattern for N = 4
...1
..232
.34543
4567654

*/
    #include <iostream>
using namespace std;

int main() {
    int row=1,N,val_1=1,val_2;
    
    cin >> N;
    if( N>=0 && N<=50){
        while(row<=N){
            
            int space=1;
            while(space<=N-row){
                cout << " ";
                space++;
            }
            //Triangle part 1
            int no=1;
            val_1=row;
            while(no<=row){
                cout << val_1;
                no++;
                val_1++;
            }
            
            //Triangle part 2
            int extra=1;
            val_2=val_1-2;
            while(extra <=row-1){
                cout << val_2;
                val_2--;
                extra++;                
            }
            row++;
            cout << endl;
        }
    }
    
}
