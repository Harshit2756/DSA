#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Reverse Alpha Triangle.
// Example Input: n = 5
// Example Output:
// E
// D E
// C D E
// B C D E
// A B C D E
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: Stateless One-Liner (Your Approach)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Very compact.
    void pattern18_stateless(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // Formula: (EndChar) - i + j
                // 'A' + (n-1) is the last char (e.g., E)
                char ch = 'A' + (n - 1) - i + j;
                cout << ch << " ";
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Explicit Start Variable (Readability)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Easier to debug "Where does this row start?".
    void pattern18_explicit(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // Step 1: Determine the starting character for this row
            char startChar = 'A' + n - 1 - i;

            for (int j = 0; j <= i; j++)
            {
                cout << (char)(startChar + j) << " ";
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

    cout << "--- Approach 1: Stateless ---\n";
    sol.pattern18_stateless(n);

    cout << "\n--- Approach 2: Explicit Start ---\n";
    sol.pattern18_explicit(n);

    return 0;
}