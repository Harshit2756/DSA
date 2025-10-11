/*
...1
..121
.12321
1234321
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
        col = 1;
        int val = 1;
        while (col <= row)
        {
            cout << val;
            val++;
            col++;
        }
        col = 1;
        int val1 = row - 1;
        while (col <= row - 1)
        {
            cout << val1;
            val1--;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}