import sys


class Solution:
    """
    Problem: Print the Alpha-Hill (Palindromic Char Pyramid).
    Example Input: n = 3
    Example Output:
      A
     ABA
    ABCBA
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Breakpoint/Midpoint Logic (Your Solution)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Intuitive. We explicitly count up, hit the middle, then count down.
    def pattern17_breakpoint(self, n):
        for i in range(n):
            # 1. Spaces
            for j in range(n - i - 1):
                print(" ", end="")
            
            # 2. Characters
            mid = i  # Peak is at index 'i' (e.g., if width is 3, indices are 0,1,2. Peak is 1)
            val = ord('A')
            
            for j in range(2 * i + 1):
                print(chr(val), end="")
                # If strictly left of mid -> Climb Up. Else -> Slide Down.
                val = val + 1 if (j < mid) else val - 1
            
            print()

    # // ~ Approach 2: Coordinate Geometry (Single Loop Math)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Single inner loop handles spaces and chars using index boundaries.
    def pattern17_coordinate(self, n):
        for i in range(n):
            val = ord('A') - 1
            
            # // Iterate until the theoretical end of the pyramid for this row
            # // Boundary: Center(n-1) + offset(i)
            for j in range(n - 1 + i + 1):
                
                # // 1. LEADING SPACES
                # // Formula: The pyramid starts 'i' steps before the center (n-1).
                if j < n - 1 - i:
                    print(" ", end="")
                
                # // 2. RISING EDGE (Climbing Up)
                # // We are inside the pyramid, but <= Center (n-1).
                elif j <= n - 1:
                    val += 1
                    print(chr(val), end="")
                
                # // 3. FALLING EDGE (Sliding Down)
                # // We are past the Center.
                else:
                    val -= 1
                    print(chr(val), end="")
            
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 3
    
    print(f"--- Approach 1: Breakpoint (n={n}) ---")
    solver.pattern17_breakpoint(n)
    
    print(f"\n--- Approach 2: Coordinate (n={n}) ---")
    solver.pattern17_coordinate(n)