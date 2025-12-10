#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print an N x N square of asterisks.
// Example Input: n = 3
// Example Output:
// ***
// ***
// ***
// Constraints: 1 <= n <= 100
// Goal: O(N^2) Time | O(1) Space

class Solution
{
public:
    // ~ Approach 1: Nested Loops (Standard C++ Logic)
    // Analysis:
    // Time: O(N^2) - We visit every cell in the N x N grid exactly once.
    // Space: O(1) - We print directly to the stream; no data is stored.
    void pattern1(int n)
    {
        // - Outer loop: Rows (0 to n-1)
        for (int i = 0; i < n; i++)
        {

            // - Inner loop: Columns (0 to n-1)
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }

            // ! Optimization: Use "\n" instead of endl.
            // - 'endl' forces a buffer flush every time, which is slow.
            // - '\n' just writes the newline character, letting the OS handle flushing efficiently.
            cout << "\n";
        }
    }
};

// Driver Code
int main()
{
    // ! FAST I/O BLOCK (Critical for Competitive Programming/OA)
    // ---------------------------------------------------------
    // 1. ios_base::sync_with_stdio(false);
    //    - Disables synchronization between C++ streams (cin/cout) and C streams (scanf/printf).
    //    - Why? Keeping them in sync requires overhead. Turning it off makes cin/cout faster.
    //    - Rule: Do NOT mix cout and printf if you use this.

    // 2. cin.tie(NULL);
    //    - Unties 'cin' from 'cout'.
    //    - Default: cout flushes (prints) automatically before cin executes.
    //    - Why? In problems with massive input, flushing cout every time you read is a bottleneck.
    //    - Result: Output only appears when the buffer is full or manually flushed.

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ---------------------------------------------------------

    Solution sol;
    int n = 5;

    cout << "Test Case (n=" << n << "):\n";
    sol.pattern1(n);

    return 0;
}