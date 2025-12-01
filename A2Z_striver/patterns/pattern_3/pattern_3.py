import sys


class Solution:
    """
    Problem: Print a Right-Angled Triangle of increasing numbers.
    Example Input: n = 4
    Example Output (Space separated):
    1
    1 2
    1 2 3
    1 2 3 4
    
    Constraints: 1 <= n <= 100
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Nested Loops (Universal Logic)
    # // Analysis: Time O(N^2) | Space O(1)
    def pattern3_nested(self, n):
        for i in range(n):
            # // . Inner loop runs i+1 times
            for j in range(i + 1):
                # // ! Logic: Print (j + 1) because j starts at 0
                # // - end=" " ensures readability for multi-digit numbers
                print(j + 1, end=" ")
            
            # // - Move to next line
            print()

    # // ~ Approach 2: Pythonic One-Liner (String Join)
    # // Analysis: Time O(N^2) | Space O(N) (creates a temporary list per row)
    def pattern3_pythonic(self, n):
        for i in range(n):
            # // - Create a range 1 to i+1, convert to str, join with spaces
            row_str = " ".join(str(x) for x in range(1, i + 2))
            print(row_str)

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    N = 5
    
    print(f"--- Approach 1: Nested Loops (N={N}) ---")
    solver.pattern3_nested(N)
    
    print(f"\n--- Approach 2: Pythonic (N={N}) ---")
    solver.pattern3_pythonic(N)