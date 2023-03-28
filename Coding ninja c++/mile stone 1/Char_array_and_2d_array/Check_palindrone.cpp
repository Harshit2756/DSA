/*For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.
Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.
Input Format:
The first line of input contains a string without any leading and trailing spaces, representing the first string 'str1'.

The second line of input contains a string without any leading and trailing spaces, representing the second string 'str2'.
Note:
All the characters in the input strings would be in lower case.
Output Format:
The only line of output prints either 'true' or 'false', denoting whether the two strings are a permutation of each other or not.

You are not required to print anything. It has already been taken care of. Just implement the function. */

#include <iostream>
#include <cstring>
using namespace std;


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}

int length(char str[]) {
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		count++;
	}
	return count;
}

bool checkPalindrome(char str[]) {
    int start=0;
    int end = length(str)-1;
    
    for(; start<=end;start++,end--){
        if (str[start]==str[end]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
