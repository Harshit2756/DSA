#include <iostream>
using namespace std;
int main() {
    int n = 3;
    int count = 1;

    // Upper half of the pattern
    for (int row1 = 1; row <= n; row1++) {
        int num = count;
        for (int col = 1; col <= row1; col++) {
            if (col > 1) {
                cout << "*";
            }
            cout << num++;
        }
        cout << endl;
        count = num;

    }
    
    // Lower half of the pattern
    for (int row = n ; row >= 1; row--) {
        int num = count - row;
        for (int col = 1; col <= row; col++) {
            if (col > 1) {
                cout << "*";
            }
            cout << num++;
        }
        cout << endl;
        // cout << num;
        // cout << endl;

        count = num;
    }

    return 0;
}
