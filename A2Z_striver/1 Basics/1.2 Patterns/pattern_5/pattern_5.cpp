#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print an Inverted Right-Angled Triangle of stars.
// Example Input: n = 5
// Example Output:
// *****
// ****
// ***
// **
// *
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Dependent Nested Loops (Subtraction Logic)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern5(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // ! Logic: As 'i' increases, the limit 'n-i' decreases.
            // - Row 0: runs n times
            // - Row 1: runs n-1 times
            for (int j = 0; j < n - i; j++)
            {
                cout << "*";
            }

            // ! Optimization: Prefer '\n' over endl
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
    sol.pattern5(n);

    return 0;
}