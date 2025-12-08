#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print the Alpha-Hill (Palindromic Char Pyramid).
// Example Input: n = 3
// Example Output:
//   A
//  ABA
// ABCBA
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: The Breakpoint Method (Standard)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Clean separation of spaces and character logic.
    void pattern17_breakpoint(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // Spaces Logic: Standard (n - i - 1)
            for (int j = 0; j < n - i - 1; j++)
                cout << " ";

            // --- BREAKPOINT DERIVATION ---
            // 1. Total Width: The row follows odd numbers (1, 3, 5...) -> Formula: 2*i + 1
            // 2. The Turning Point:
            //    - We increment 'i' times.
            //    - We decrement 'i' times.
            //    - The Peak is the middle.
            //    - Math: (2*i + 1) / 2 simplifies to just 'i' in integer division.
            //      Example (i=2): Width 5. 5/2 = 2. We grow for 2 steps.

            int breakpoint = i;
            char ch = 'A';

            // Loop j from 1 to Total Width
            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << ch;

                // 3. CONDITION DERIVATION
                //    - If j <= breakpoint (e.g., j <= 2), we are still climbing the hill.
                //    - Else, we have passed the climbing phase and must slide down.
                if (j < breakpoint){
                    ch++;
                }else{
                    ch--;
                }
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Coordinate Logic (Your Way - Polished)
    // Analysis: Time O(N^2) | Space O(1)
    void pattern17_coordinate(int n)
    {
        for (int i = 0; i < n; i++)
        {
            char ch = 'A' - 1;

            // Peak is always at index (n-1).
            // Right Boundary = Peak + i
            // Formula: n - 1 + i
            for (int j = 0; j <= n - 1 + i; j++)
            {

                // 1. LEFT BOUNDARY CHECK (Spaces)
                // The pyramid starts 'i' steps left of Peak.
                // Start = Peak - i = (n - 1) - i
                // If j is less than Start, it's a space.
                if (j < n - 1 - i)
                {
                    cout << " ";
                }

                // 2. RISING SLOPE (Left of or at Peak)
                // If j is valid (>= Start) but <= Peak (n-1).
                else if (j <= n - 1)
                {
                    ch++;
                    cout << ch;
                }

                // 3. FALLING SLOPE (Right of Peak)
                // If j > Peak, we simply mirror the logic (decrement).
                else
                {
                    ch--;
                    cout << ch;
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
    int n = 4;

    cout << "--- Approach 1: Breakpoint (Standard) ---\n";
    sol.pattern17_breakpoint(n);

    cout << "\n--- Approach 2: Coordinate (Your Logic) ---\n";
    sol.pattern17_coordinate(n);

    return 0;
}
