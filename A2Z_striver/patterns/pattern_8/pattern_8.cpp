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