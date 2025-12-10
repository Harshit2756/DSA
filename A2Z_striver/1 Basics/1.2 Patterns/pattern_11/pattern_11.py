import sys

class Solution:
    """
    Problem: Print a Binary Triangle (Alternating 1s and 0s).
    Example Input: n = 3
    Example Output:
    1
    0 1
    1 0 1
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Coordinate Parity (Your Approach)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Stateless, purely mathematical.
    def pattern11_parity(self, n):
        for i in range(n):
            for j in range(i + 1):
                # // ! Optimization: Move logic inside print
                # // Logic: Even sum -> 1, Odd sum -> 0
                print("1 " if (i + j) % 2 == 0 else "0 ", end="")
            print()

    # // ~ Approach 2: Toggle Method (State-based)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Intuitive simulation of "flipping" a switch.
    def pattern11_toggle(self, n):
        for i in range(n):
            # // - Start with 1 if row is even, else 0
            start = 1 if i % 2 == 0 else 0
            
            for j in range(i + 1):
                print(f"{start} ", end="")
                # // - Flip the bit: 1->0, 0->1
                start = 1 - start 
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 3
    
    print(f"--- Approach 1: Parity (n={n}) ---")
    solver.pattern11_parity(n)
    
    print(f"\n--- Approach 2: Toggle (n={n}) ---")
    solver.pattern11_toggle(n)