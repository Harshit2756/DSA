#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Header Comment Block
// Problem: Print the Number Spiral (Pattern 22).
// Example Input: n = 4
// Example Output:
// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 1 2 3 4 ...
// Goal: O(N^2) Time.

class Solution
{
public:
    // ~ Approach 1: Math / Distance Formula (Your Code)
    // Analysis: Time O(N^2) | Space O(1)
    // Pros: Most efficient, no extra memory usage.
    void pattern22_math(int n)
    {
        int size = 2 * n - 1;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {

                // ! Logic: Value depends on min distance from any wall
                int top = i;
                int left = j;
                int bottom = (size - 1) - i; // Distance from bottom edge
                int right = (size - 1) - j;  // Distance from right edge

                // Value = n - minimum_distance
                int min_dist = min(min(top, left), min(bottom, right));
                cout << (n - min_dist) << " ";
            }
            cout << "\n";
        }
    }

    // ~ Approach 2: Matrix Layering (Simulation)
    // Analysis: Time O(N^2) | Space O(N^2)
    // Pros: Good for visualizing "Layers" or "Rings".
    void pattern22_layers(int n)
    {
        int size = 2 * n - 1;
        // Create a 2D matrix filled with 0
        vector<vector<int>> matrix(size, vector<int>(size));

        // Loop 'layer' from 0 to n-1 (0 is outer ring, n-1 is center)
        for (int layer = 0; layer < n; layer++)
        {

            // Value to fill in this layer
            int val = n - layer;

            // Fill the square boundaries for this layer
            // Start Index: layer
            // End Index: size - 1 - layer
            int start = layer;
            int end = size - 1 - layer;

            for (int i = start; i <= end; i++)
            {
                matrix[start][i] = val; // Top Row of current ring
                matrix[end][i] = val;   // Bottom Row of current ring
                matrix[i][start] = val; // Left Col of current ring
                matrix[i][end] = val;   // Right Col of current ring
            }
        }

        // Print the matrix
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << matrix[i][j] << " ";
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

    cout << "--- Approach 1: Math Formula ---\n";
    sol.pattern22_math(n);

    cout << "\n--- Approach 2: Matrix Layers ---\n";
    sol.pattern22_layers(n);

    return 0;
}