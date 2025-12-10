#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Right-Angled Triangle of increasing numbers.
// Example Input: n = 4
// Example Output:
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Dependent Nested Loops
    // Analysis: Time O(N^2) | Space O(1)
    void pattern3(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // - Inner loop runs i+1 times (0 to i)
            for (int j = 0; j <= i; j++)
            {
                // ! Logic: Output the Column index (j) + 1
                // - Added " " for readability when n >= 10
                cout << j + 1 << " ";
            }
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
    sol.pattern3(n);

    return 0;
}