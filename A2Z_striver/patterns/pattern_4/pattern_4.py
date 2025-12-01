import sys


class Solution:
    """
    Problem: Print a Right-Angled Triangle of repeating row numbers.
    Example Input: n = 4
    Example Output:
    1
    22
    333
    4444
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Pythonic (String Replication)
    # // Analysis: Time O(N^2) | Space O(N) (Temp string creation)
    def pattern4_pythonic(self, n):
        for i in range(1, n + 1):
            # // . Creates string "333" directly
            print(str(i) * i)

    # // ~ Approach 2: Nested Loops (Algorithmic Standard)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern4_nested(self, n):
        for i in range(1, n + 1):
            # // - Inner loop runs 'i' times
            for j in range(i):
                print(i, end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Pythonic (N={N}) ---")
    solver.pattern4_pythonic(N)
    
    print(f"\n--- Approach 2: Nested Loops (N={N}) ---")
    solver.pattern4_nested(N)