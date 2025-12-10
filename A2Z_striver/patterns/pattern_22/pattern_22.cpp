#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Right-Angled Triangle of Numbers.
// Example Input: n = 5
// Example Output:
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach: Standard Loop
    // Analysis: Time O(N^2) | Space O(1)
    void pattern21(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
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

    cout << "--- Right-Angled Triangle Pattern ---\n";
    sol.pattern21(n);

    return 0;
}