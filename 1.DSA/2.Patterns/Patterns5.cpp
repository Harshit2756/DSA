/*
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int row = 1;
    int val = 1;

    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            cout << val;
            val++;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}