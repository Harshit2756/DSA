#include <iostream>
using namespace std;

// Brutforce
int LCM(int a, int b)
{
    int val = max(a, b);
    while (1)
    {
        if (val % a == 0 && val % b == 0)
        {
            return val;
        }
        val++;
    }
    return val;
}

//using formula 
// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     else
//     {
//         return gcd(b, a % b);
//     }
// }

// int lcm(int a, int b)
// {
//     return (a * b) / gcd(a, b);
// }

int main()
{

    int a = 4, b = 6;
    cout << LCM(a, b);

    return 0;
}