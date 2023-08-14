/*
A A A A
B B B B
C C C C
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

        while (col <= n)
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