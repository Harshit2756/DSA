/*
...*
..**
.***
****
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        int Space = 1;
        while (Space <= n - row)
        {
            cout << " ";
            Space++;
        }

        int col = 1;
        while (col <= row)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}