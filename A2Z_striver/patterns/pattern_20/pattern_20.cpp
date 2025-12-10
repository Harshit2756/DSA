#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Butterfly Pattern (Single Peak).
// Example Input: n = 3
// Example Output:
// *....* (Row 0: 1 star each side)
// **..** (Row 1: 2 stars each side)
// ****** (Row 2: 3 stars each side - PEAK)
// **..** (Row 3: Mirror of Row 1)
// *....* (Row 4: Mirror of Row 0)
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: Single Loop with Mirror Math (Your Approach)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Short code, demonstrates index mapping skills.
    void pattern20_single_loop(int n)
    {
        // Run for 2*n - 1 rows (Single Peak variant)
        for (int i = 0; i < 2 * n - 1; i++)
        {

            // --- 1. MIRROR LOGIC ---
            // We need an 'effective_row' index that goes: 0 -> 1 -> 2 -> 1 -> 0
            // Top Half (i < n): effective_row = i
            // Bottom Half (i >= n):
            //    Formula derivation:
            //    - Total Height = 2*n - 1. Last Index = 2*n - 2.
            //    - We want Last Index to map to 0.
            //    - as, Last Index - i == 0 true.
            //    - So, effective_row = (2*n - 2) - i

            int row = i;
            if (i >= n)
            {
                row = 2 * n - 2 - i;
            }

            // --- 2. INNER LOOP ---
            // Total Width is 2*n.
            // Left Stars: indices 0 to 'row' (count = row+1)
            // Right Stars: indices starting from (2*n - 1 - row) to end.

            for (int j = 0; j < 2 * n; j++)
            {

                // Condition:
                // j <= row           -> Left Triangle
                // j >= total_width(i.e the last column) - row -> Right Triangle
                // j >= 2*n - 1 - row -> Right Triangle
                if (j <= row || j >= 2 * n - 1 - row)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Split Loops (Iterative / Readable)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Easier to debug, no complex formulas.
    void pattern20_split(int n)
    {
        // Part 1: Growing Phase (0 to n-1) -- Includes the Peak row
        for (int i = 0; i < n; i++)
        {
            int stars = i + 1;
            int spaces = 2 * n - 2 * stars;

            // Left Stars
            for (int j = 0; j < stars; j++)
                cout << "*";
            // Spaces
            for (int j = 0; j < spaces; j++)
                cout << " ";
            // Right Stars
            for (int j = 0; j < stars; j++)
                cout << "*";

            cout << "\n";
        }

        // Part 2: Shrinking Phase (n-2 down to 0) -- Skips Peak row
        // Note: Loop starts from n-2 to avoid duplicating the middle row
        for (int i = n - 2; i >= 0; i--)
        {
            int stars = i + 1;
            int spaces = 2 * n - 2 * stars;

            // Left Stars
            for (int j = 0; j < stars; j++)
                cout << "*";
            // Spaces
            for (int j = 0; j < spaces; j++)
                cout << " ";
            // Right Stars
            for (int j = 0; j < stars; j++)
                cout << "*";

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

    cout << "--- Approach 1: Single Loop (Math) ---\n";
    sol.pattern20_single_loop(n);

    cout << "\n--- Approach 2: Split Loops (Iterative) ---\n";
    sol.pattern20_split(n);

    return 0;
}