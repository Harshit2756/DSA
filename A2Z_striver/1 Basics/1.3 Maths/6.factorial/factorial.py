import math

# Header Comment Block
# Problem: Calculate Factorial of N (N!).
# Example Input: n = 5 -> Output: 120 (5*4*3*2*1)
# Example Input: n = 0 -> Output: 1
# Goal: O(N) Time | O(1) Space.

class Solution:
    # ~ Approach 1: Iterative (Safe & Standard)
    # Analysis: Time O(N) | Space O(1)
    # Pros: No risk of Stack Overflow Error (Recursion Depth).
    def factorial_Iterative(self, n: int) -> int:
        if n < 0:
            return None # Or raise ValueError
            
        val = 1
        
        # . Loop from n down to 1
        while n > 0:
            val *= n
            n -= 1
            
        return val

    # ~ Approach 2: Recursive (Mathematical Definition)
    # Analysis: Time O(N) | Space O(N) (Stack Space)
    # Pros: Matches the math definition n! = n * (n-1)!
    def factorial_Recursive(self, n: int) -> int:
        # Base Case
        if n == 0 or n == 1:
            return 1
        
        # Recursive Step
        return n * self.factorial_Recursive(n - 1)

if __name__ == "__main__":
    sol = Solution()
    
    # Test Cases
    print(f"5! (Iterative): {sol.factorial_Iterative(5)}")
    print(f"5! (Recursive): {sol.factorial_Recursive(5)}")
    print(f"0! : {sol.factorial_Iterative(0)}")

