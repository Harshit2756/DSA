import sys

class Solution:
    """
    Problem: Print Butterfly Pattern (Single Peak).
    Example Input: n = 3
    Example Output:
    * *
    ** **
    ****** (Row n-1: Peak)
    ** **
    * *
    Goal: O(N) Time (due to string mult) or O(N^2) characters.
    """

    # // ~ Approach 1: Pythonic Split Loops (Your Code)
    # // Analysis: Time O(N) lines | Space O(N) string construction
    # // Pros: Extremely clean, leverages Python's string multiplication.
    def pattern20_split(self, n):
        # Part 1: Growing Phase (0 to n-1)
        for i in range(n):
            stars_count = i + 1
            spaces_count = 2 * n - 2 * stars_count
            
            # String Multiplication: '*' * 3 -> "***"
            stars = "*" * stars_count
            spaces = " " * spaces_count
            print(stars + spaces + stars)
            
        # Part 2: Shrinking Phase (0 to n-2)
        # We run n-1 times to avoid duplicating the middle row
        for i in range(n - 1):
            stars_count = n - 1 - i
            spaces_count = 2 * n - 2 * stars_count
            
            stars = "*" * stars_count
            spaces = " " * spaces_count
            print(stars + spaces + stars)

    # // ~ Approach 2: Single Loop (Coordinate Math)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Universal logic (works in C++/Java too), demonstrates index mastery.
    def pattern20_single_loop(self, n):
        # Run for 2*n - 1 rows (Single Peak variant)
        # Indices: 0, 1, ... n-1 (Peak) ... 2n-2
        for i in range(2 * n - 1):
            
            # // --- 1. MIRROR LOGIC ---
            # // Goal: Map bottom indices back to top indices.
            # // Top Half (i < n): row = i
            # // Bottom Half (i >= n):
            # //    - Last Row Index is (2*n - 2). We want this to map to Row 0.
            # //    - Formula: row = (LastIndex) - i
            # //    - Formula: row = (2*n - 2) - i
            row = i
            if i >= n:
                row = 2 * n - 2 - i
            
            # // --- 2. BOUNDARY LOGIC ---
            # // We need stars on the edges, spaces in the middle.
            # // Left Star Count: row + 1 (Row 0 has 1 star)
            # // Right Star Start: TotalWidth - LeftStars
            
            stars_limit = row + 1
            total_width = 2 * n
            
            for j in range(total_width):
                # // Condition:
                # // Left Side: j < stars_limit
                # // Right Side: j >= total_width - stars_limit
                if j < stars_limit or j >= total_width - stars_limit:
                    print("*", end="")
                else:
                    print(" ", end="")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 3
    print(f"--- Approach 1: Pythonic Split (n={n}) ---")
    solver.pattern20_split(n)
    
    print(f"\n--- Approach 2: Single Loop (n={n}) ---")
    solver.pattern20_single_loop(n)