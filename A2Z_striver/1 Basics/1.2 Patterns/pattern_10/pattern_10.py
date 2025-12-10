import sys

class Solution:
    """
    Problem: Print a Half Diamond Pattern (Single Peak).
    Example Input: n = 3
    Example Output:
    *
    **
    ***
    **
    *
    Goal: Print the pattern using different algorithmic strategies.
    """

    # // ~ Approach 1: Split Loops (Intuitive/Brute Force)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern10_split(self, n):
        # // - Part 1: Growing Phase (1 to n)
        for i in range(1, n + 1):
            for j in range(i):
                print("*", end="")
            print()
            
        # // - Part 2: Shrinking Phase (n-1 down to 1)
        for i in range(n - 1, 0, -1):
            for j in range(i):
                print("*", end="")
            print()

    # // ~ Approach 2: Single Loop (Mathematical/Optimized)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern10_single_loop(self, n):
        # // ! Critical: Run for 2*n - 1 rows
        for i in range(2 * n - 1):
            
            # // - Logic: Calculate stars based on 'i'
            # //   If i < n: stars = i + 1
            # //   If i >= n: stars = 2*n - i - 1
            stars = i + 1
            if i >= n:
                stars = 2 * n - i - 1
            
            for j in range(stars):
                print("*", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 3
    
    print(f"--- Approach 1: Split Loops (n={n}) ---")
    solver.pattern10_split(n)
    
    print(f"\n--- Approach 2: Single Loop (n={n}) ---")
    solver.pattern10_single_loop(n)