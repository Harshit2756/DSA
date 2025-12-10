import sys

class Solution:
    """
    Problem: Print Reverse Alpha Triangle.
    Example Input: n = 5
    Example Output:
    E
    D E
    C D E
    B C D E
    A B C D E
    
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Stateless One-Liner (Your Implementation)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Compact, good for "Systems" interviews where memory matters.
    def pattern18_stateless(self, n):
        # Optimization: Store constant outside loops
        base = ord('A') 
        
        for i in range(n):
            for j in range(i + 1):
                # ! Logic: 
                #   We want to print characters starting from a specific point.
                #   Start Point moves backwards as 'i' increases.
                #   Formula: Base + (TotalOffset) - RowOffset + ColOffset
                #   Example (n=5, i=0): 65 + 4 - 0 + 0 = 69 ('E')
                
                char_code = base + (n - 1) - i + j
                print(chr(char_code), end=" ")
            print()

    # // ~ Approach 2: Explicit Start Variable (Readability Optimized)
    # // Analysis: Time O(N^2) | Space O(1)
    # // Pros: Much easier to explain on a whiteboard. clearly separates "Row Logic" from "Col Logic".
    def pattern18_explicit(self, n):
        for i in range(n):
            
            # // Step 1: Calculate the STARTING character for this row.
            # // Row 0 starts at 'E' (A + 4)
            # // Row 1 starts at 'D' (A + 3)
            # // Row i starts at 'A' + (n - 1 - i)
            start_char = ord('A') + (n - 1) - i
            
            # // Step 2: Print the row starting from that character
            for j in range(i + 1):
                # // Just add 'j' to the starting character
                current_char = start_char + j
                print(chr(current_char), end=" ")
            print()

# Driver Code
if __name__ == "__main__":
    solver = Solution()
    n = 5
    
    print(f"--- Approach 1: Stateless (n={n}) ---")
    solver.pattern18_stateless(n)
    
    print(f"\n--- Approach 2: Explicit Start (n={n}) ---")
    solver.pattern18_explicit(n)