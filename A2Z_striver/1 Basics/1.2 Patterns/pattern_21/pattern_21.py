import sys

class Solution:
    """
    Problem: Print the Number Spiral.
    Example Input: n = 4
    Example Output:
    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 1 2 3 4 ...
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Math / Distance Formula (Standard)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Efficient, translates well to other languages.
    def pattern22_math(self, n):
        size = 2 * n - 1
        for i in range(size):
            for j in range(size):
                
                # // 1. Calculate Distances to all 4 walls
                top = i
                left = j
                bottom = (size - 1) - i
                right = (size - 1) - j
                
                # // 2. Find Minimum Distance
                # // The value is simply: n - min_dist
                min_dist = min(top, left, bottom, right)
                print(n - min_dist, end=" ")
            print()

    # // ~ Approach 2: Pythonic List Comprehension (One-Liner)
    # // Analysis: Time O(N^2) | Space O(N^2) (Creates a list in memory)
    # // Pros: Extremely concise. Shows mastery of Python syntax.
    def pattern22_pythonic(self, n):
        size = 2 * n - 1
        
        # // Nested List Comprehension
        # // Logic: n - min(i, j, size-1-i, size-1-j) for every i, j
        grid = [
            [n - min(i, j, size - 1 - i, size - 1 - j) for j in range(size)]
            for i in range(size)
        ]
        
        # // Print the grid
        for row in grid:
            print(*row) # '*' Unpacks the list (prints elements separated by space)

    # // ~ Approach 3: Matrix Layering (Simulation)
    # // Analysis: Time O(N^2) | Space O(N^2)
    # // Pros: Visualizes the "Onion Peeling" strategy.
    def pattern22_layers(self, n):
        size = 2 * n - 1
        # Create empty grid
        matrix = [[0] * size for _ in range(size)]
        
        # Loop from outer layer (0) to inner layer (n-1)
        for layer in range(n):
            val = n - layer
            start = layer
            end = size - 1 - layer
            
            # Fill the square ring
            for i in range(start, end + 1):
                matrix[start][i] = val # Top
                matrix[end][i] = val   # Bottom
                matrix[i][start] = val # Left
                matrix[i][end] = val   # Right
                
        # Print
        for row in matrix:
            print(*row)

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 4
    
    print(f"--- Approach 1: Math Formula (n={n}) ---")
    solver.pattern22_math(n)
    
    print(f"\n--- Approach 2: Pythonic One-Liner (n={n}) ---")
    solver.pattern22_pythonic(n)