#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Solid Diamond (2N rows).
// Example Input: n = 3
// Example Output:
//   *
//  ***
// *****
// *****
//  ***
//   *
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach 1: Stacked Pyramids (Your Solution)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Very readable, easy to debug.
    void pattern9_stacked(int n)
    {
        // 1. Top Half
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
                cout << " ";
            for (int j = 0; j < 2 * i + 1; j++)
                cout << "*";
            cout << "\n";
        }
        // 2. Bottom Half
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < 2 * (n - i) - 1; j++)
                cout << "*";
            cout << "\n";
        }
    }

    // ~ Approach 2: Single Loop (Index Mirroring)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Follows DRY (Don't Repeat Yourself) principle.
    // Cons: Logic is slightly more complex to derive on the spot.
    void pattern9_single_loop(int n)
    {
        // - We run one loop for the total 2*n rows
        for (int i = 0; i < 2 * n; i++)
        {

            // ! Key Logic: "The Mirror"
            // - If we are in the top half (i < n), use 'i' as is.
            // - If we are in the bottom half (i >= n), flip 'i' to count backwards.
            //   Formula: (2*n - i - 1) converts row indices [n, 2n-1] -> [n-1, 0]
            int row = i;
            if (i >= n)
            {
                row = 2 * n - i - 1;
            }

            // 2. Single Inner Loop
            // Limit: We need to print spaces + stars.
            // Spaces count: n - row - 1
            // Stars count:  2 * row + 1
            // Total columns needed: (n - row - 1) + (2 * row + 1) = n + row
            for (int j = 0; j < n + row + 1; j++)
            { // +1 to cover the last star? No, < n+row covers indices 0 to n+row-1.
                // Wait, let's re-verify the math:
                // Row 0 (n=3): Needs 2 spaces, 1 star. Total 3 chars. Indices 0, 1, 2. Limit should be 'n + row'.

                // 3. Conditional Logic
                // Spaces are on the left side, count is (n - row - 1).
                // So if index j < count, it's a space.
                if (j < n - row - 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
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

    cout << "--- Approach 1: Stacked ---\n";
    sol.pattern9_stacked(n);

    cout << "\n--- Approach 2: Single Loop (Mirrored) ---\n";
    sol.pattern9_single_loop(n);

    return 0;
}