/*
...1
..212
.32123
4321234
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
        int val = row;
        while (col <= row)
        {
            cout << val;
            val--;
            col++;
        }

        col = 1;
        int val1 = row;
        while (col <= row - 1)
        {
            cout << val1;
            val1++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}