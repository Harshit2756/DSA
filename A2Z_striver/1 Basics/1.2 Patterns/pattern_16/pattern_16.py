import sys

class Solution:
    """
    Problem: Print Repeated Letter Triangle.
    Example Input: n = 3
    Example Output:
    A
    BB
    CCC
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Standard Algo) - YOUR APPROACH
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern16_nested(self, n):
        for i in range(n):
            # // ! Logic: Character depends on ROW index 'i'
            val = ord('A') + i
            for j in range(i + 1):
                print(chr(val), end="")
            print()

    # // ~ Approach 2: Pythonic (String Multiplication)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Concise, removes explicit inner loop.
    def pattern16_pythonic(self, n):
        for i in range(n):
            char = chr(ord('A') + i)
            # // Repeat character (i+1) times
            print(char * (i + 1))

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 4
    
    print(f"--- Approach 1: Nested (n={n}) ---")
    solver.pattern16_nested(n)
    
    print(f"\n--- Approach 2: Pythonic (n={n}) ---")
    solver.pattern16_pythonic(n)