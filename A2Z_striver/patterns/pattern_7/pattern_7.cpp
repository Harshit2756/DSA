#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Center-Aligned Star Pyramid.
// Example Input: n = 3
// Example Output:
//   *
//  ***
// *****
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Multiple Inner Loops
    // Analysis: Time O(N^2) | Space O(1)
    void pattern7(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // - Step 1: Print Leading Spaces
            // - Logic: As row (i) increases, spaces decrease.
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }

            // - Step 2: Print Stars
            // - Logic: Odd numbers (1, 3, 5...) -> Formula 2*i + 1
            for (int j = 0; j < 2 * i + 1; j++)
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
    sol.pattern7(n);

    return 0;
}