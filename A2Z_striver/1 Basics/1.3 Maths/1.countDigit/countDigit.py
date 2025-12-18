"""
Problem: Count the total number of digits in an integer n.
Example: Input: n = 12345 | Output: 5
Constraints: -2^31 <= n <= 2^31 - 1
Goal: O(log N) time or O(1) using math.
"""

import math

class DigitCounter:
    # ~ Approach 1: Iterative (Standard Interview Approach)
    # Analysis: Time O(log10 N), Space O(1)
    def count_iterative(self, n: int) -> int:
        # ! Fix: Handle negative numbers by taking absolute value
        n = abs(n)
        
        # ! Fix: Zero is a 1-digit number
        if n == 0: 
            return 1
            
        count = 0
        while n > 0:
            # . Optimization: Floor division peels the last digit
            n //= 10
            count += 1
        return count

    # ~ Approach 2: Logarithmic (Mathematical Approach)
    # Analysis: Time O(1)*, Space O(1) 
    # *Note: math.log10 is effectively O(1) for fixed-width integers.
    def count_math(self, n: int) -> int:
        n = abs(n)
        if n == 0: return 1
        
        # - The number of digits in x is floor(log10(x)) + 1
        # . This avoids the loop entirely.
        return math.floor(math.log10(n)) + 1

    # ~ Approach 3: String Conversion (Pythonic/Practical)
    # Analysis: Time O(N) where N is digits, Space O(N) to store string
    def count_string(self, n: int) -> int:
        # . Fast to write, but uses extra space for the string representation
        return len(str(abs(n)))

# --- Driver Code ---
if __name__ == "__main__":
    solver = DigitCounter()
    test_cases = [12345, -500, 0, 7]
    
    print(f"{'Input':<10} | {'Iterative':<10} | {'Math':<10} | {'String':<10}")
    print("-" * 50)
    for t in test_cases:
        print(f"{t:<10} | {solver.count_iterative(t):<10} | "
              f"{solver.count_math(t):<10} | {solver.count_string(t):<10}")