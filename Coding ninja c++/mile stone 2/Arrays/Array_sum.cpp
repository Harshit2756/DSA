/*Given an array of length N, you need to find and print the sum of all elements of the array.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n ;
    
    int arr[1000000];
    for(int j=0;j<=n;j++){
        cin >> arr[j];
    }
    
    int sum=0;
    for(int i=0;i<=n;i++){
        sum+=arr[i];
    }
    cout << sum;
}