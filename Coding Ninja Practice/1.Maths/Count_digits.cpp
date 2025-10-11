#include <bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

// Driver code
int main(void)
{
    int n = 3450;
    cout << "Number of digits : " << countDigit(n);
    return 0;
}