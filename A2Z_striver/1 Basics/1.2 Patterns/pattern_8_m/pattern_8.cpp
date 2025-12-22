#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print an Inverted Star Pyramid.
// Example Input: n = 3
// Example Output:
// *****
//  ***
//   *
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Dependent Nested Loops (Inverted Logic)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern8(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // - Step 1: Print Spaces
            // - Logic: Indentation increases with row index (0, 1, 2...)
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            // - Step 2: Print Stars
            // - Logic: Odd numbers decreasing (2n-1, 2n-3...)
            for (int j = 0; j < 2 * (n - i) - 1; j++)
            {
                cout << "*";
            }

            cout << "\n";
        }
    }

    void pattern8StrictTwoLoops(int n) {
        // Outer Loop: Iterates through rows (0 to n-1)
        for (int i = 0; i < n; i++) {
            
            // 1. Calculate limits for this row
            // Spaces logic: Row 0 -> 0 spaces, Row 1 -> 1 space... (spaces = i)
            int spaces = i;
            
            // Stars logic: 2*n - (2*i + 1) OR 2*(n-i) - 1
            int stars = 2 * (n - i) - 1;
            
            // The inner loop must run for the sum of both
            int totalCols = spaces + stars;

            // Inner Loop: STRICTLY ONE LOOP for columns
            for (int j = 0; j < totalCols; j++) {
                if (j < spaces) {
                    cout << " "; // Print Space
                } else {
                    cout << "*"; // Print Star
                }
            }
            
            cout << "\n";
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int n = 5;

    cout << "Test Case (n=" << n << "):\n";
    sol.pattern8(n);

    return 0;
}