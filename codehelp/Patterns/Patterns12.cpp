/*
A B C D
A B C D
A B C D
A B C D
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
        char val = 'A';
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