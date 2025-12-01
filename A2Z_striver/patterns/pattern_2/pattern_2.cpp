#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Right-Angled Triangle of stars.
// Example Input: n = 4
// Example Output:
// *
// **
// ***
// ****
// Constraints: 1 <= n <= 100
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Dependent Nested Loops
    // Analysis:
    // Time: O(N^2) - Specifically N(N+1)/2 operations.
    // Space: O(1).
    void print_increasing_triangle(int n)
    {
        // - Outer Loop: Rows
        for (int i = 0; i < n; i++)
        {

            // - Inner Loop: Columns
            // ! Key Logic: j runs from 0 to i.
            // - When i=0, loop runs 1 time.
            // - When i=1, loop runs 2 times.
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }

            // ! Performance: Use '\n'
            cout << "\n";
        }
    }
};

int main()
{
    // ! Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int n = 5;

    cout << "Test Case (n=" << n << "):\n";
    sol.print_increasing_triangle(n);

    return 0;
}