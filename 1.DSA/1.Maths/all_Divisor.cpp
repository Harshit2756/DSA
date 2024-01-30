#include <iostream>
using namespace std;

// brutforce
// void pritnDivisor(int n)
// {
//     for (int i = 1; i < = n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i;
//         }
//     }
// }

// better
// void pritnDivisor(int n)
// {
//     for (int i = 1; i*i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i;
//             if (i!=n/i)
//             {
//                 cout << n / i;
//             }

//         }
//     }
// }

// optimal
void pritnDivisor(int n)
{
    int i;
    for ( i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i;
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << n / i;
        }
    }
}

int main()
{

    int n = 6;
    pritnDivisor(n);
    return 0;
}