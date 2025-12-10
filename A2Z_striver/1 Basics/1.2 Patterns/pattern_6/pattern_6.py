import sys

class Solution:
    """
    Problem: Print an Inverted Number Triangle.
    Example Input: n = 5
    Example Output:
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Standard Algo)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern6_nested(self, n):
        for i in range(n):
            # // ! Logic: Run loop (n-i) times
            # // - We range from 1 to (n-i) inclusive for cleaner printing
            for j in range(1, n - i + 1):
                print(j, end=" ")
            print()

    # // ~ Approach 2: Pythonic (List Comprehension)
    # // Analysis: Time O(N^2) | Space O(N) (Temp list creation)
    def pattern6_pythonic(self, n):
        for i in range(n):
            # // . Generate list of numbers, map to str, and join
            print(" ".join(str(x) for x in range(1, n - i + 1)))

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Nested Loops (N={N}) ---")
    solver.pattern6_nested(N)
    
    print(f"\n--- Approach 2: Pythonic (N={N}) ---")
    solver.pattern6_pythonic(N)