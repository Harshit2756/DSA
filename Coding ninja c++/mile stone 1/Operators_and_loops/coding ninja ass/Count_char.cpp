/*Write a program to count and print the total number of characters (lowercase english alphabets only), digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).*/

#include<iostream>
using namespace std;

int main(){

    char c;
    c=cin.get();
    
    int count_of_characters=0;
    int count_of_digits=0;
    int count_of_whitespaces=0;
    
    while (c != '$'){
        
        if(c>= 'a' && c<= 'z'){
            count_of_characters++;
        }
        else if(c>='0' && c<='9' ){
            count_of_digits++;
        }
        else if(c=='\t' || c=='\n' || c==' '){
            count_of_whitespaces++;
        }
        
        c=cin.get();
    }
    
  cout << count_of_characters << " " <<count_of_digits << " " <<count_of_whitespaces ;
}


