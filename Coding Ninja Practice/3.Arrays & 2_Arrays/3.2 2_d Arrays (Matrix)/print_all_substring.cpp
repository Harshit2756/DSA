/*For a given input string(str), write a function to print all the possible substrings.
Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
Print the total number of substrings possible, where every substring is printed on a single line and hence the total number of output lines will be equal to the total number of substrings.*/

#include <iostream>
#include <cstring>
using namespace std;


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}

void printSubstrings(char input[]) {
    
    
	// finding the length of the string
    int n = strlen(input);
     
    // outermost for loop
    // this is for the selection
    // of starting point
    for (int i = 0; i < n; i++) {
       
        // 2nd for loop is for selection
        // of ending point
        for (int j = i; j < n; j++) {
           
            // 3rd loop is for printing from
            // starting point to ending point
            for (int k = i; k <= j; k++) {
                cout << input[k];
            }
           
            // changing the line after printing
            // from starting point to ending point
            cout << endl;
        }
    }
}