import sys


class Solution:
    """
    Problem: Print the Number Crown.
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Three Loops (Stateless/Mathematical) - YOUR CURRENT CODE
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Pure logic, no mutable state variable 'k'.
    def pattern12_stateless(self, n):
        for i in range(n):
            # 1. Left Numbers (j+1)
            for j in range(i + 1):
                print(j + 1, end="")
            
            # 2. Spaces
            for _ in range(2 * (n - i - 1)):
                print(" ", end="")
            
            # 3. Right Numbers (Stateless Math)
            # Logic: We want to print (i+1) down to 1.
            # j goes 0 to i.
            # Formula: (i + 1) - j
            for j in range(i + 1):
                print(i + 1 - j, end="")
            
            print()

    # // ~ Approach 2: Three Loops (Stateful)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Intuitive if you prefer tracking values manually.
    def pattern12_stateful(self, n):
        for i in range(n):
            k = 0
            # Left
            for j in range(i + 1):
                k += 1
                print(k, end="")
            # Spaces
            for _ in range(2 * (n - i - 1)):
                print(" ", end="")
            # Right (Reuse k)
            for j in range(i + 1):
                print(k, end="")
                k -= 1
            print()

    # // ~ Approach 3: Single Loop (Coordinate Logic)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Compact, tests index mastery.
    def pattern12_single_loop(self, n):
        for i in range(n):
            k = 0
            for j in range(2 * n):
                if j <= i:
                    k += 1
                    print(k, end="")
                elif j >= 2 * n - 1 - i:
                    print(k, end="")
                    k -= 1
                else:
                    print(" ", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 4
    print(f"--- Approach 1: Stateless (n={n}) ---")
    solver.pattern12_stateless(n)