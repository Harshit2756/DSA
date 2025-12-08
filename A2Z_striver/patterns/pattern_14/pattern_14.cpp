#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Increasing Letter Triangle.
// Example Input: n = 3
// Example Output:
// A
// A B
// A B C
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: Stateful (Your Approach)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Very readable C++ logic.
    void pattern14_stateful(int n)
    {
        for (int i = 0; i < n; i++)
        {
            char ch = 'A'; // Reset to 'A' every row
            for (int j = 0; j <= i; j++)
            {
                cout << ch << " "; // Print then increment
                ch++;
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Stateless (ASCII Math)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Direct calculation, no local state variable needed.
    void pattern14_stateless(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // 'A' + 0 = 'A'
                // 'A' + 1 = 'B'
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
    int n = 4;

    cout << "--- Approach 1: Stateful ---\n";
    sol.pattern14_stateful(n);

    cout << "\n--- Approach 2: Stateless ---\n";
    sol.pattern14_stateless(n);

    return 0;
}