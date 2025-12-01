import sys


class Solution:
    """
    Problem: Print a Center-Aligned Star Pyramid.
    Example Input: n = 3
    Example Output:
      *
     ***
    *****
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Algorithmic Standard)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern7_nested(self, n):
        for i in range(n):
            # // - Step 1: Print Leading Spaces
            # //   Formula: n - i - 1
            for j in range(n - i - 1):
                print(" ", end="")

            # // - Step 2: Print Stars
            # //   Formula: 2*i + 1 (Odd numbers: 1, 3, 5...)
            for j in range(2 * i + 1):
                print("*", end="")
            
            # // - Step 3 (Optional): Trailing Spaces
            # //   Some OAs require symmetry. If so, copy the first loop here.
            
            print()

    # // ~ Approach 2: Pythonic One-Liner
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern7_pythonic(self, n):
        for i in range(n):
            # // . Calculate spaces and stars using string math
            spaces = " " * (n - i - 1)
            stars = "*" * (2 * i + 1)
            print(spaces + stars)

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Nested Loops (N={N}) ---")
    solver.pattern7_nested(N)
    
    print(f"\n--- Approach 2: Pythonic One-Liner (N={N}) ---")
    solver.pattern7_pythonic(N)