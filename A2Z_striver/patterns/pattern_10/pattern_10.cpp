#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Half Diamond Pattern (Single Peak).
// Example Input: n = 3
// Example Output:
// *
// **
// ***
// **
// *
// Goal: O(N) Rows | O(N^2) Time

class Solution
{
public:
    // ~ Approach 1: Split Loops (Your Approach)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Readable, easier to reason about bounds.
    void pattern10_split(int n)
    {
        // 1. Growing Phase (1 to n)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }

        // 2. Shrinking Phase (n-1 down to 1)
        // Note: Logic (n-i-1) correctly handles the decrease
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Single Loop (Mathematical)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Concise, demonstrates index manipulation skills.
    void pattern10_single_loop(int n)
    {
        // ! Run for 2*n - 1 rows
        for (int i = 1; i <= 2 * n - 1; i++)
        {

            // ! Logic:
            // If i <= n: stars = i
            // If i > n: stars = 2*n - i
            int stars = i;
            if (i > n)
            {
                stars = 2 * n - i;
            }

            for (int j = 0; j < stars; j++)
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
    int n = 3;

    cout << "--- Approach 1: Split Loops ---\n";
    sol.pattern10_split(n);

    cout << "\n--- Approach 2: Single Loop ---\n";
    sol.pattern10_single_loop(n);

    return 0;
}