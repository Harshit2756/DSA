/*
A
B B
C C C
D D D D
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int row = 1;
    char val = 'A';

    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << val;
            col++;
        }
        cout << endl;
        val++;
        row++;
    }
    return 0;
}