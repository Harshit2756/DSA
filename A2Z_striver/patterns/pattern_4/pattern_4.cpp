#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Right-Angled Triangle of repeating row numbers.
// Example Input: n = 3
// Example Output:
// 1
// 2 2
// 3 3 3
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Dependent Nested Loops
    // Analysis: Time O(N^2) | Space O(1)
    void pattern4(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // - Inner loop runs i+1 times
            for (int j = 0; j <= i; j++)
            {
                // ! Logic: Print the ROW number (i+1), not the column number
                cout << i + 1 << " ";
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
    sol.pattern4(n);

    return 0;
}