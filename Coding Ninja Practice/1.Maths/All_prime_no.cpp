#include <iostream>
using namespace std;

// Brutforce
bool check_Prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x = 10;
    int *p = &x;
    // p =;
    cout << &x << endl; // 0x61ff08
    cout << *p << endl; // 10
    cout << p << endl;  // 0x61ff08
    return 0;
}
