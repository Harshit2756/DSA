import sys

class Solution:
    """
    Problem: Print a solid square pattern of size N x N.
    Example Input: n = 3
    Example Output:
    ***
    ***
    ***
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # ~ Approach 1: Nested Loops (Standard Interview Approach)
    # Analysis: Time O(N^2) | Space O(1)
    def pattern1_nested(self, n):
        for i in range(n):
            for j in range(n):
                # - Print star, stay on same line
                print("*", end="")
            
            # - Move to next line after printing N columns
            print()

    # ~ Approach 2: Pythonic Optimization
    # Analysis: Time O(N^2) | Space O(1)
    def pattern1_pythonic(self, n):
        # . Uses string multiplication to remove the inner loop
        # . This is preferred in production code, but Approach 1 is better for Algo interviews.
        for i in range(n):
            print("*" * n)

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 4
    
    print(f"--- Approach 1: Nested Loops (N={N}) ---")
    solver.pattern1_nested(N)
    
    print(f"\n--- Approach 2: Pythonic (N={N}) ---")
    solver.pattern1_pythonic(N)