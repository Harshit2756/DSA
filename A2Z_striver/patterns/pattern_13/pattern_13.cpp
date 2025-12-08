#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print Floyd's Triangle (Continuous Numbers).
// Example Input: n = 4
// Example Output:
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: The Accumulator (Standard)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Simple, standard interview solution.
    void pattern13_accumulator(int n)
    {
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << num << " ";
                num++;
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Mathematical / Stateless (Advanced)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: O(1) random access to any cell.
    void pattern13_stateless(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // --- Math Logic Derivation ---
            // Question: What is the first number of Row 'i'?
            // Step 1: Count how many numbers exist in ALL previous rows (0 to i-1).
            //    - Row 0 has 1 number.
            //    - Row 1 has 2 numbers.
            //    - Row i-1 has 'i' numbers.
            //    - Total Previous Numbers = Sum of 1 to i = 1 + 2 + ... + i.

            // Step 2: Use the Gaussian Sum Formula for 'i' terms:
            //    - Sum = (i * (i + 1)) / 2

            // Step 3: The start of the current row is the NEXT number after that sum.
            //    - Start Value = Sum + 1

            int startVal = (i * (i + 1)) / 2 + 1;

            for (int j = 0; j <= i; j++)
            {
                // Current value is just Start + Offset (j)
                cout << (startVal + j) << " ";
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

    cout << "--- Approach 1: Accumulator ---\n";
    sol.pattern13_accumulator(n);

    cout << "\n--- Approach 2: Stateless (Math) ---\n";
    sol.pattern13_stateless(n);

    return 0;
}