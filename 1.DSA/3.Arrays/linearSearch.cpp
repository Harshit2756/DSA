#include<iostream>
using namespace std;

bool search(int arr[], int size, int val) {
    for( int i = 0; i<size; i++ ) {
        if( arr[i] == val) {
            return 1;
        }
    }
    return 0;
}


int main() {

    int arr[10] = { 5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    cout <<" Enter the element to search for " << endl; 
    int val;
    cin >> val;
    bool found = search(arr, 10, val);
    if( found ) {
        cout <<" value is present "<< endl;
    }
    else{
        cout <<" value is absent " << endl;
    }
    return 0;
}