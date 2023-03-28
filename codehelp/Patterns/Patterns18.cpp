/*
D
C C
B B B
A A A A
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int row = 1;
    char val = 'A' + n - 1;

    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << val;
            col++;
        }
        cout << endl;
        val--;
        row++;
    }
    return 0;
}