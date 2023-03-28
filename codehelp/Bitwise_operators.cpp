#include <iostream>
using namespace std;

int main()
{
    int a = 19; // 19 =10011
    int b = 28; // 28 =11000
    int c = 0;

    c = a & b; // 16 =10000
    cout << "a&b =" << c << endl;

    c = a | b; // 31 =11111
    cout << "a|b =" << c << endl;

    c = a ^ b; // 15 =01111
    cout << "a^b =" << c << endl;

    c = ~a; // ­‐20 =01100
    cout << "~a=" << c << endl;

    c = a << 2; // 76 =1001100
    cout << "a << 2 =" << c << endl;

    c = a >> 2; // 4 =00100
    cout << "a >> 2 =" << c << endl;
    
    int i = 5;
    cout << (++i) << endl; // i=6
    cout << (i++) << endl; // i=6
    cout << (i--) << endl; // i=7
    cout << (--i) << endl; // i=5

    return 0;
}

