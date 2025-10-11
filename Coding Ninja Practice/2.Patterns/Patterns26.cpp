/*n=4
..*
.***
*****
.***
..*
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
        int space = 1;
        while (space <= (n/2)-row+1)
        {
            cout << " ";
            space++;
        }
        int space = 1;
        while (space <= (n/2)-row+1)
        {
            cout << " ";
            space++;
        }
        int space = 1;
        while (space <= n row+1)
        {
            cout << " ";
            space++;
        }
        cout << endl;
        row++;
    }
    return 0;
}