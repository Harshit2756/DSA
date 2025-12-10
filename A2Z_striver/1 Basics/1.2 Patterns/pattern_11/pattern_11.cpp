#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print a Binary Triangle (Alternating 1s and 0s).
// Example Input: n = 3
// Example Output:
// 1
// 0 1
// 1 0 1
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: The Toggle Method (Your approach, optimized)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Easy to trace step-by-step.
    void pattern11_toggle(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // - Step 1: Initialize start bit based on row parity
            //   Even row (0, 2) starts with 1. Odd row (1, 3) starts with 0.
            int start = (i % 2 == 0) ? 1 : 0;

            for (int j = 0; j <= i; j++)
            {
                cout << start << " ";

                // - Step 2: Flip the bit
                //   Trick: 1 - 1 = 0; 1 - 0 = 1;
                start = 1 - start;
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: The Coordinate/Parity Method (Stateless)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: No state variable management; purely mathematical.
    void pattern11_parity(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {

                // ! Logic: Check the sum of coordinates (i + j)
                // - If sum is EVEN -> Print 1
                // - If sum is ODD  -> Print 0
                if ((i + j) % 2 == 0)
                {
                    cout << "1 ";
                }
                else
                {
                    cout << "0 ";
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
    int n = 5;

    cout << "--- Approach 1: Toggle Method ---\n";
    sol.pattern11_toggle(n);

    cout << "\n--- Approach 2: Parity Method ---\n";
    sol.pattern11_parity(n);

    return 0;
}