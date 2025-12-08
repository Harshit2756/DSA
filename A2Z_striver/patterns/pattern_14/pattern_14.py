import sys

class Solution:
    """
    Problem: Print Increasing Letter Triangle.
    Example Input: n = 3
    Example Output:
    A
    A B
    A B C
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Stateless (ASCII Math) - Your Approach
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Direct calculation, idiomatic Python.
    def pattern14_stateless(self, n):
        for i in range(n):
            for j in range(i + 1):
                # // Logic: 'A' is 65. Add 'j' to get 'B', 'C', etc.
                char_code = ord('A') + j
                print(chr(char_code), end=" ")
            print()

    # // ~ Approach 2: Stateful (Pre-calculated String)
    # // Analysis: Time O(N^2) | Space O(N) (String slicing overhead)
    # // Pros: Extremely Pythonic for interviews allowing slicing.
    def pattern14_pythonic(self, n):
        # // Create a reference string
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        for i in range(n):
            # // Slice from 0 to i+1
            print(" ".join(alphabet[:i+1]))

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 4
    
    print(f"--- Approach 1: Stateless (n={n}) ---")
    solver.pattern14_stateless(n)
    
    print(f"\n--- Approach 2: Pythonic (n={n}) ---")
    solver.pattern14_pythonic(n)