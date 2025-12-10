import sys

class Solution:
    """
    Problem: Print the Symmetric Void Pattern.
    Example Input: n = 5
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Split Loops (Your Code)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Very readable, easy to derive.
    def pattern19_split(self, n):
        # 1. Top Half
        for i in range(n):
            # Left Stars
            for j in range(n - i):
                print('*', end='')
            # Spaces
            for j in range(2 * i):
                print(' ', end='')
            # Right Stars
            for j in range(n - i):
                print('*', end='')
            print()

        # 2. Bottom Half
        for i in range(n):
            # Left Stars
            for j in range(i + 1):
                print('*', end='')
            # Spaces
            for j in range(2 * (n - i - 1)):
                print(' ', end='')
            # Right Stars
            for j in range(i + 1):
                print('*', end='')
            print()

    # // ~ Approach 2: Single Loop (Coordinate Logic)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Concise, demonstrates mastery of indices.
    def pattern19_single_loop(self, n):
        for i in range(2 * n):
            
            # // 1. Calculate Effective Row (Mirror Logic)
            # // Top Half (i<n): 0, 1, ...
            # // Bot Half (i>=n): Flips back to ..., 1, 0
            row = i
            if i >= n:
                row = 2 * n - 1 - i
            
            # // 2. Condition Logic
            # // Left Block: j < (n - row)
            # // Right Block: j >= (n + row)
            for j in range(2 * n):
                if j < n - row or j >= n + row:
                    print("*", end="")
                else:
                    print(" ", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 5
    print(f"--- Approach 1: Split (n={n}) ---")
    solver.pattern19_split(n)
    print(f"--- Approach 2: Single Loop (n={n}) ---")
    solver.pattern19_single_loop(n)