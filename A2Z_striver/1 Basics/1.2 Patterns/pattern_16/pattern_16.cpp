#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Repeated Letter Triangle.
// Example Input: n = 3
// Example Output:
// A
// B B
// C C C
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach: Row-Dependent Character Calculation
    // Analysis: Time O(N^2) | Space O(1)
    void pattern16(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // ! Logic: Character depends on ROW index 'i'
            // - Row 0 -> 'A'
            // - Row 1 -> 'B'
            char ch = 'A' + i;

            for (int j = 0; j <= i; j++)
            {
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
    int n = 4;

    cout << "Test Case (n=" << n << "):\n";
    sol.pattern16(n);

    return 0;
}