import sys

class Solution:
    """
    Problem: Print a Right-Angled Triangle of stars.
    Example Input: n = 4
    Example Output:
    *
    **
    ***
    ****
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Pythonic (String Multiplication)
    # // Analysis: Time O(N^2) | Space O(1)
    def print_increasing_triangle_pythonic(self, n):
        for i in range(n):
            # // . Logic: Row 0 needs 1 star, Row 1 needs 2 stars...
            print("*" * (i + 1))

    # // ~ Approach 2: Nested Loops (Universal Logic)
    # // Analysis: Time O(N^2) | Space O(1)
    def print_increasing_triangle_nested(self, n):
        # // ! This logic translates directly to C++/Java
        for i in range(n):
            # // - Inner loop runs (i + 1) times
            for j in range(i + 1):
                print("*", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Pythonic (N={N}) ---")
    solver.print_increasing_triangle_pythonic(N)
    
    print(f"\n--- Approach 2: Nested Loops (N={N}) ---")
    solver.print_increasing_triangle_nested(N)