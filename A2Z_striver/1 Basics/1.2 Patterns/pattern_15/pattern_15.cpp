#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Inverted Increasing Letter Triangle.
// Example Input: n = 5
// Example Output:
// A B C D E
// A B C D
// A B C
// A B
// A
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach: Stateless (ASCII Math)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern15(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // - Logic: Loop runs (n-i) times
            // - Row 0: n times
            // - Row 1: n-1 times
            for (int j = 0; j < n - i; j++)
            {

                // - Calculate char based on COLUMN (j)
                // - j resets to 0 every row, so every row starts with 'A'
                char ch = 'A' + j;
                cout << ch << " ";
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
    sol.pattern15(n);

    return 0;
}