/*
****
.***
..**
...*
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
        while (Space <= row - 1)
        {
            cout << " ";
            Space++;
        }

        int col = 1;
        while (col <= n - row + 1)
        {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}