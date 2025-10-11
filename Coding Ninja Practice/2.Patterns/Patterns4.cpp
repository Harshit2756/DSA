/*
4321
4321
4321
4321
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
        int val = 4;
        while (col <= n)
        {
            cout << val;
            val--;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}