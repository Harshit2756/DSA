import sys

class Solution:
    """
    Problem: Print Floyd's Triangle (Continuous Numbers).
    Example Input: n = 4
    Example Output:
    1
    2 3
    4 5 6
    7 8 9 10
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: The Accumulator (Your Approach)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Simple, keeps track of state naturally.
    def pattern13_accumulator(self, n):
        value = 1
        for i in range(n):
            for _ in range(i + 1):
                print(value, end=" ")
                value += 1
            print()

    # // ~ Approach 2: Stateless (Mathematical)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Allows random access (calculating row 'i' without running previous rows).
    def pattern13_stateless(self, n):
        for i in range(n):
            # // --- Math Logic ---
            # // 1. Count total numbers in previous rows (0 to i-1).
            # //    Sum = 1 + 2 + ... + i = (i * (i+1)) // 2
            # // 2. Start of current row is Sum + 1.
            start_val = (i * (i + 1)) // 2 + 1
            
            for j in range(i + 1):
                # // Print StartVal + Offset (j)
                print(f"{start_val + j} ", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 4
    
    print(f"--- Approach 1: Accumulator (n={n}) ---")
    solver.pattern13_accumulator(n)
    
    print(f"\n--- Approach 2: Stateless (n={n}) ---")
    solver.pattern13_stateless(n)