#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print an Inverted Number Triangle.
// Example Input: n = 5
// Example Output:
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach 1: 1-Based Indexing (Your Approach)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern6_v1(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            // ! Math check: n - i + 1
            // i=1 -> limit 5
            // i=2 -> limit 4
            for (int j = 1; j <= n - i + 1; j++)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: 0-Based Indexing (Standard Loop)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern6_v2(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // ! Math check: limit is simply n - i
            for (int j = 0; j < n - i; j++)
            {
                cout << j + 1 << " ";
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

    cout << "--- Approach 1 (1-based) ---\n";
    sol.pattern6_v1(n);

    cout << "\n--- Approach 2 (0-based) ---\n";
    sol.pattern6_v2(n);

    return 0;
}