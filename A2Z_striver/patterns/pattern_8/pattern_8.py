import sys

class Solution:
    """
    Problem: Print an Inverted Star Pyramid.
    Example Input: n = 3
    Example Output:
    *****
     ***
      *
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Algorithmic Standard)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern8_nested(self, n):
        for i in range(n):
            # // - Step 1: Print Leading Spaces
            # //   Logic: 0 spaces, then 1, then 2... (equal to row index)
            for j in range(i):
                print(" ", end="")

            # // - Step 2: Print Stars
            # //   Logic: Decreasing odd numbers.
            # //   i=0 -> 2*n - 1
            # //   i=1 -> 2*(n-1) - 1
            for j in range(2 * (n - i) - 1):
                print("*", end="")
            
            print()

    # // ~ Approach 2: Pythonic One-Liner
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern8_pythonic(self, n):
        for i in range(n):
            # // . Direct string math
            spaces = " " * i
            stars = "*" * (2 * (n - i) - 1)
            print(spaces + stars)

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Nested Loops (N={N}) ---")
    solver.pattern8_nested(N)