#include <iostream>
#include <algorithm> // for min()
using namespace std;

class PatternCheatSheet
{
public:
    // ==========================================
    // 1. NESTED LOOPS (The Grid Mental Model)
    // ==========================================
    // Concept: Outer loop = Rows (Y-axis), Inner loop = Cols (X-axis).
    // Use for: Squares, Rectangles.
    void concept_grid(int n)
    {
        // "Run for n rows"
        for (int i = 0; i < n; i++)
        {
            // "Run for n columns"
            for (int j = 0; j < n; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }

    // ==========================================
    // 2. THE TRIANGLE RELATIONSHIP (i vs j)
    // ==========================================
    // Concept: The inner loop limit depends on the outer loop index 'i'.
    // Use for: Right-angled triangles.
    void concept_triangles(int n)
    {
        for (int i = 0; i < n; i++)
        {

            // Type A: Growing Triangle (Limit increases)
            // Logic: j runs from 0 to i
            for (int j = 0; j <= i; j++)
                cout << "*";

            cout << " | "; // Separator

            // Type B: Shrinking Triangle (Limit decreases)
            // Logic: j runs from 0 to (n - 1 - i)
            // OR: Standard approach is loop < n-i
            for (int j = 0; j < n - i; j++)
                cout << "*";

            cout << endl;
        }
    }

    // ==========================================
    // 3. THE PYRAMID FORMULA (Spaces + Stars)
    // ==========================================
    // Concept: A row has 3 parts: Leading Spaces -> Stars -> Trailing Spaces
    // Use for: Centered Pyramids (Patterns 7, 8, 9).
    void concept_pyramid(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // 1. Spaces: decrease as i increases (n - i - 1)
            for (int j = 0; j < n - i - 1; j++)
                cout << " ";

            // 2. Stars: odd numbers (2*i + 1)
            for (int j = 0; j < 2 * i + 1; j++)
                cout << "*";

            // 3. Spaces (Optional): usually ignored in simple printing
            cout << endl;
        }
    }

    // ==========================================
    // 4. MIRRORING / FOLDING (The Single Loop)
    // ==========================================
    // Concept: When a pattern is symmetric (Top = Bottom), run loop for 2*n.
    // Calculate an "Effective Row" that goes Up then Down.
    // Use for: Arrow, Diamond, Butterfly (Patterns 10, 19, 20).
    void concept_symmetry(int n)
    {
        // Total rows: usually 2*n - 1 (Single Peak) or 2*n (Double Peak)
        for (int i = 0; i < 2 * n - 1; i++)
        {

            // THE FOLD LOGIC
            int row = i;
            if (i >= n)
            {
                // Map bottom indices back to top indices
                // Formula: (TotalRows - 1) - i
                row = (2 * n - 2) - i;
            }

            // Use 'row' for logic instead of 'i'
            // Example: Print stars equal to effective row + 1
            for (int j = 0; j <= row; j++)
                cout << "*";
            cout << endl;
        }
    }

    // ==========================================
    // 5. STATELESS MATH & COORDINATES
    // ==========================================
    // Concept: Calculate value based on distance from walls (i, j, n).
    // Use for: Number Spiral (Pattern 22), Hollow Box (Pattern 21).
    void concept_coordinates(int n)
    {
        int size = 2 * n - 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {

                // DISTANCE FORMULA
                // Distance to Top: i
                // Distance to Left: j
                // Distance to Bottom: (Size-1) - i
                // Distance to Right: (Size-1) - j
                int min_dist = min(min(i, j), min(size - 1 - i, size - 1 - j));

                cout << (n - min_dist) << " ";
            }
            cout << endl;
        }
    }
};