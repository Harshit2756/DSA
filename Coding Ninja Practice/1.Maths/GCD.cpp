#include <iostream>
using namespace std;

// Brutforce sol
int GDC(int a, int b)
{
    int val = min(a, b);
    while (val > 0)
    {
        if (a % val == 0 && b % val == 0)
        {
            return val;
        }
        val--;
    }
}

// Euclide
//  int GCD (int a,int b){
//      while (a!=b)
//      {
//          if(a<b){
//              b = b - a;
//          }else{
//              a = a - b;
//          }
//      }
//      return a;
//  }

// Optimised Euclide
// int GCD(int a,int b){
//     if(b==0){
//         return a;
//     }else{
//         return GCD(b, a % b);
//     }
// }

int main()
{
    int a = 4, b = 6;
    cout << GDC(a, b);
    return 0;
}
