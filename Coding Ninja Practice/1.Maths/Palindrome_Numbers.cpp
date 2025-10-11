#include <iostream>
using namespace std;


bool isPalindrome(int n){

    int num = n;
    int reverse_num = 0;
    
    while(n!=0){
        int val = n % 10;
        reverse_num = reverse_num*10 + val ;
        n /= 10;
    }

    return num == reverse_num ;
}

int main(){

    int n=78987;
    cout << boolalpha;
    cout << isPalindrome(n);
    return 0;
}

