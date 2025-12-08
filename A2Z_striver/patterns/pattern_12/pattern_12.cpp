#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print the Number Crown (Double Triangle).
// Example Input: n = 4
// Example Output:
// 1      1
// 12    21
// 123  321
// 12344321
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: Single Inner Loop (Complex Math Logic)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Compact code, shows strong index manipulation skills.
    void pattern12_single_loop(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            // Iterate across the full width of the row
            // Width = 2 * n (e.g., if n=4, width=8, indices 0 to 7)
            for (int j = 0; j < 2 * n; j++)
            {

                // --- Logic Derivation ---
                // 1. Left Triangle:
                //    - We need numbers in the first (i+1) columns.
                //    - Indices: 0, 1, ... i
                //    - Condition: j <= i

                if (j <= i)
                {
                    k++;
                    cout << k;
                }

                // 2. Right Triangle:
                //    - This is a mirror of the left.
                //    - Total Width Indices: 0 to (2*n - 1).
                //    - If Left Triangle ends at index 'i', Right Triangle must start 'i' steps from the end.
                //    - Last Index = 2*n - 1
                //    - Start Threshold = (Last Index) - i
                //    - Condition: j >= 2*n - 1 - i
                else if (j >= 2 * n - 1 - i)
                {
                    cout << k;
                    k--; // Decrement as we move right
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Three Separate Loops (Standard/Readable)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Decoupled logic, easy to debug.
    void pattern12_standard(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // 1. Print Left Numbers (1 to i+1)
            for (int j = 1; j <= i + 1; j++)
            {
                cout << j;
            }

            // 2. Print Spaces
            // Formula: Total Width (2*n) - Left# - Right#
            // Spaces = 2*n - 2*(i+1)
            int spaces = 2 * n - 2 * (i + 1);
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }

            // 3. Print Right Numbers (i+1 down to 1)
            for (int j = i + 1; j >= 1; j--)
            {
                cout << j;
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

    cout << "--- Approach 1: Single Loop (Math Logic) ---\n";
    sol.pattern12_single_loop(n);

    cout << "\n--- Approach 2: Standard Split Loops ---\n";
    sol.pattern12_standard(n);

    return 0;
}