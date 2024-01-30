#include <iostream>
using namespace std;
// Iterrative
int factorial(int n)
{
    int fact = 1;
    if (n == 0)
    {
        return fact;
    }
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Recurson
// int factorial(int n){
    
//     if(n==0){
//         return 1;
//     }

//     return n* factorial(n - 1);
// }

int main(){

    int n=5;
    cout << factorial(n);

    return 0;
}