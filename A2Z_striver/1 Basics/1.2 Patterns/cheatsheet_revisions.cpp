#include <iostream>
#include <algorithm> // for min()
#include <cmath>     // for abs()
using namespace std;

class PatternCheatSheet
{
public:
    // Helper to print headers for better visibility
    void printHeader(string title) {
        cout << "\n==========================================" << endl;
        cout << "  " << title << endl;
        cout << "==========================================" << endl;
    }

    // ==========================================
    // 1. NESTED LOOPS (The Grid Mental Model)
    // ==========================================
    // Concept: Outer loop = Rows (Y-axis), Inner loop = Cols (X-axis).
    // Visual: A perfect square box.
    void concept_grid(int n)
    {
        printHeader("1. THE GRID (Nested Loops)");
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "* "; // Added extra space for a square look
            }
            cout << endl;
        }
    }

    // ==========================================
    // 2. THE TRIANGLE RELATIONSHIP (i vs j)
    // ==========================================
    // Concept: The inner loop limit depends on 'i'.
    // Visual: Lower Left Triangle | Upper Left Triangle
    void concept_triangles(int n)
    {
        printHeader("2. TRIANGLES (Dependent Inner Loop)");
        
        cout << "[Type A: Growing]   [Type B: Shrinking]\n\n";

        for (int i = 0; i < n; i++)
        {
            // Type A: Growing (0 to i)
            for (int j = 0; j <= i; j++)
                cout << "*";
            
            // Spacing for better view
            for(int s=0; s < (n-i) + 5; s++) cout << " "; 

            cout << "|     "; // Separator

            // Type B: Shrinking (0 to n-i-1)
            for (int j = 0; j < n - i; j++)
                cout << "*";

            cout << endl;
        }
    }

    // ==========================================
    // 3. UPRIGHT PYRAMID (Strict 2 Loops)
    // ==========================================
    // Shape:
    //    *
    //   ***
    //  *****
    // Logic: 1 Outer Loop, 1 Inner Loop.
    // We switch from Space to Star based on a "Threshold" index.
    void UprightPyramid(int n)
    {
        printHeader("1. UPRIGHT PYRAMID (Vertical)");

        // Outer Loop: Rows (0 to n-1)
        for (int i = 0; i < n; i++)
        {
            // Calculate limits
            // 1. Where do stars START? (The Space Threshold)
            int start_stars = n - 1 - i;
            
            // 2. Where does the row END? 
            // Formula: Space_Count + Star_Count
            // Spaces = n - 1 - i
            // Stars  = 2 * i + 1
            // Total  = n + i
            int total_cols = n + i;

            // STRICT SINGLE INNER LOOP
            for (int j = 0; j < total_cols; j++)
            {
                if (j < start_stars) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }

    // ==========================================
    // 4. SIDEWAYS ARROW (Folded Logic)
    // ==========================================
    // Shape:
    //  *
    //  **
    //  ***
    //  **
    //  *
    // Logic: The row index grows, then "folds" back down.
    void SidewaysArrow(int n)
    {
        printHeader("2. SIDEWAYS ARROW (Horizontal)");

        int total_rows = 2 * n - 1;

        // Outer Loop: Runs for all rows
        for (int i = 0; i < total_rows; i++)
        {
            // FOLD LOGIC:
            // If i is small (top half), stars = i
            // If i is big (bottom half), stars = flipped i
            // Note: Using 1-based logic for easier math, or 0-based with adjustment
            
            int stars = i;
            if (i >= n) {
                stars = (2 * n - 2) - i;
            }

            // ONE INNER LOOP
            // Prints stars up to the calculated count
            for (int j = 0; j <= stars; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }

    // ==========================================
    // 5. STATELESS MATH & COORDINATES
    // ==========================================
    // Concept: Value depends on distance from nearest wall.
    // Visual: The Spiral / Concentric Square.
    void concept_coordinates(int n)
    {
        printHeader("5. COORDINATES (Distance Formula)");

        // Size of the box is always 2*n - 1
        int size = 2 * n - 1;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                // DISTANCE FORMULA
                // Calculate distance to Top(i), Left(j), Bottom, Right
                int top = i;
                int left = j;
                int bottom = (size - 1) - i;
                int right = (size - 1) - j;

                // Value is N - minimum distance to any edge
                int min_dist = min(min(top, left), min(bottom, right));
                
                cout << (n - min_dist) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    PatternCheatSheet cheat;
    int n = 5; // Change this to test different sizes

    // Run all concepts
    cheat.concept_grid(n);
    cheat.concept_triangles(n);
    cheat.UprightPyramid(n);
    cheat.SidewaysArrow(n);
    cheat.concept_coordinates(4); // Use 4 for spiral to keep it readable

    return 0;
}