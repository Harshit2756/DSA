#include <iostream>

using namespace std;

// Header Comment Block
// Problem: Print the Symmetric Void Pattern.
// Example Input: n = 3
// Example Output:
// ****** (Row 0: 3 stars, 0 spaces, 3 stars)
// ** ** (Row 1: 2 stars, 2 spaces, 2 stars)
// * * (Row 2: 1 star,  4 spaces, 1 star)  <-- Mirror Line
// * * (Row 3: Mirror of Row 2)
// ** ** (Row 4: Mirror of Row 1)
// ****** (Row 5: Mirror of Row 0)

class Solution
{
public:
    // ~ Approach 1: Split Loops (Standard/Readable)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Easiest to write in a hurry. Logic is separated.
    void pattern19_split(int n)
    {
        // 1. Top Half
        for (int i = 0; i < n; i++)
        {
            // Left Stars: n-i
            for (int j = 0; j < n - i; j++)
                cout << "*";
            // Spaces: 2*i
            for (int j = 0; j < 2 * i; j++)
                cout << " ";
            // Right Stars: n-i
            for (int j = 0; j < n - i; j++)
                cout << "*";
            cout << "\n";
        }

        // 2. Bottom Half
        for (int i = 0; i < n; i++)
        {
            // Left Stars: i+1
            for (int j = 0; j <= i; j++)
                cout << "*";
            // Spaces: 2*(n-i-1)
            for (int j = 0; j < 2 * (n - i - 1); j++)
                cout << " ";
            // Right Stars: i+1
            for (int j = 0; j <= i; j++)
                cout << "*";
            cout << "\n";
        }
    }

    // ~ Approach 2: Single Loop (Coordinate Mirroring)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Short code, demonstrates index mastery.
    void pattern19_single_loop(int n)
    {
        for (int i = 0; i < 2 * n; i++)
        {

            // 1. Calculate 'Effective Row'
            // Top Half (i < n): 0, 1, 2...
            // Bot Half (i >= n): 2n-1-i flips it to ..., 2, 1, 0
            int row = i;
            if (i >= n)
                row = 2 * n - 1 - i;

            for (int j = 0; j < 2 * n; j++)
            {

                // 2. The Condition
                // LEFT STARS: Print if j is within the shrinking limit (n - row)
                // RIGHT STARS: Print if j is past the expanding gap (n + row)
                if (j < n - row || j >= n + row)
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
};