#include <iostream>
using namespace std;

int length(char s[]){
    // base case
    if(s[0]=='\0'){
        return 0;
    }

    // recursive call
    int small_string_length=length(s + 1);

    // small work
    return 1 + small_string_length;
}



int main(){

    char str[100];
    cin >> str;

    int l = length(str);
    cout << l << endl;

    return 0;
}