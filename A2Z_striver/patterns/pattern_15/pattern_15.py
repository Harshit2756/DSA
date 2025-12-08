import sys

class Solution:
    """
    Problem: Print Inverted Increasing Letter Triangle.
    Example Input: n = 5
    Example Output:
    A B C D E
    A B C D
    A B C
    A B
    A
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Stateless)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern15_stateless(self, n):
        for i in range(n):
            # // - Inner loop shrinks as i increases
            for j in range(n - i):
                # // - Calculate char based on COLUMN (j)
                print(chr(ord('A') + j), end=" ")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 5
    print(f"Test Case (n={n}):")
    solver.pattern15_stateless(n)