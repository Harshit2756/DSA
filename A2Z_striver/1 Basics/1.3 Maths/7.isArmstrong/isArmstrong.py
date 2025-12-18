
import math

"""
Problem: Check if a number is an Armstrong Number.
An Armstrong number (of order k) is a number that is the sum of its digits each raised to the power of k.

Example Input: 153
Example Output: True
Logic: 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

Constraints:
    - -2^31 <= n <= 2^31 - 1
    - Handle negative inputs (typically return False).
"""

class Solution:

    # ~ Approach 1: Mathematical (Best for Space Complexity)
    # Analysis: Time O(log N) | Space O(1)
    def isArmstrongMath(self, n: int) -> bool:
        # ! Edge Case: Negative numbers are not Armstrong numbers
        if n < 0:
            return False
            
        original_n = n
        
        # - Calculate number of digits using log10 for O(1) space
        # - equivalent to len(str(n)) but without string allocation
        if n == 0:
            digit_count = 1
        else:
            digit_count = int(math.log10(n)) + 1
            
        power_sum = 0
        
        while n > 0:
            digit = n % 10
            # . Optimization: In heavy loops, math.pow is slower than **
            power_sum += digit ** digit_count 
            n //= 10
            
        return power_sum == original_n

    # ~ Approach 2: Pythonic / String Conversion (Best for Readability)
    # Analysis: Time O(log N) | Space O(log N) due to string creation
    def isArmstrongString(self, n: int) -> bool:
        if n < 0:
            return False
            
        # - Convert to string to easily iterate digits
        s_n = str(n)
        digit_count = len(s_n)
        
        # ! List comprehension for concise summing
        power_sum = sum(int(digit) ** digit_count for digit in s_n)
        
        return power_sum == n

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    test_cases = [153, 370, 371, 9474, 123, -153, 0]
    
    print(f"{'Number':<10} | {'Math Approach':<15} | {'String Approach':<15}")
    print("-" * 45)
    
    for num in test_cases:
        res_math = sol.isArmstrongMath(num)
        res_str = sol.isArmstrongString(num)
        print(f"{num:<10} | {str(res_math):<15} | {str(res_str):<15}")
