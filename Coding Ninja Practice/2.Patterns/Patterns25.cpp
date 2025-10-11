/*
12344321
123**321
12****21
1******1
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
        int col = 1;
        int val = 1;
        while (col <= n-row+1)
        {
            cout << val;
            val++;
            col++;
        }

        int star = 1;
        while (star <= 2 * row - 2)
        {
            cout << "*";
            star++;
        }

        int col1 = 1;
        int val1 = n - row + 1;
        while (col1 <= n - row + 1)
        {
            cout << val1;
            val1--;
            col1++;
        }
        cout << endl;
        row++;
    }
    return 0;
}