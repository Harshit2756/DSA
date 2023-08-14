/*
****
****
****
****
*/

#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int rows = 1;                           ///intialize rows start
    while (rows <= n )                      ///Condition for no.of rows
    {   
        int col=1;                          //*initialize col start
        while (col<=n)                   //*Condition for no.of cols
        {
            cout << "*";                    //~The value that is to be printed
            col++;
        }
        cout << endl;
        rows++;
    }
    

return 0;
}   