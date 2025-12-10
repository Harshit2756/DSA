import sys

class Solution:
    """
    Problem: Print a Solid Diamond (2N rows).
    Example Input: n = 3
    Example Output:
      *
     ***
    *****
    *****
     ***
      *
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Stacked Pyramids (Standard/Readable)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern9_stacked(self, n):
        # 1. Top Half (Upright)
        for i in range(n):
            # Spaces
            for _ in range(n - i - 1):
                print(" ", end="")
            # Stars
            for _ in range(2 * i + 1):
                print("*", end="")
            print()

        # 2. Bottom Half (Inverted)
        for i in range(n):
            # Spaces
            for _ in range(i):
                print(" ", end="")
            # Stars
            for _ in range(2 * (n - i) - 1):
                print("*", end="")
            print()

    # // ~ Approach 2: Single Loop (Index Mirroring)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern9_single_loop(self, n):
        # Loop runs 2*n times (0 to 2n-1)
        for i in range(2 * n):
            
            # ! Key Logic: "The Mirror"
            # If i >= n, we flip the index to count backwards
            effective_row = i
            if i >= n:
                effective_row = 2 * n - i - 1
            
            # Print Spaces: n - effective_row - 1
            for _ in range(n - effective_row - 1):
                print(" ", end="")
            
            # Print Stars: 2 * effective_row + 1
            for _ in range(2 * effective_row + 1):
                print("*", end="")
            
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 3
    
    print(f"--- Approach 1: Stacked (n={n}) ---")
    solver.pattern9_stacked(n)
    
    print(f"\n--- Approach 2: Single Loop (n={n}) ---")
    solver.pattern9_single_loop(n)