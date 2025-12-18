"""
Problem: Reverse Integer (LeetCode #7 Style)
Example Input/Output: 123 -> 321, -123 -> -321, 120 -> 21
Constraints: Return 0 if the result overflows 32-bit range [-2^31, 2^31 - 1].
Goal: O(log N) Time | O(1) Space.
"""

class Solution:
    # ~ Approach 1: Mathematical (Pop & Push)
    # Analysis: Time O(log N) | Space O(1)
    # ! Fix: Added 32-bit overflow check as required by most competitive platforms.
    def reverse_Math(self, n: int) -> int:
        sign = -1 if n < 0 else 1
        n = abs(n)
        rev = 0
        
        # . 32-bit Limit: 2147483647
        LIMIT = 2**31 - 1
        
        while n != 0:
            pop = n % 10
            n //= 10
            
            # . Check for overflow before it happens
            # - If rev * 10 will exceed LIMIT, return 0
            if rev > (LIMIT - pop) // 10:
                return 0
                
            rev = (rev * 10) + pop
            
        return rev * sign

    # ~ Approach 2: String Slicing (Pythonic)
    # Analysis: Time O(log N) | Space O(log N)
    def reverse_Pythonic(self, n: int) -> int:
        sign = -1 if n < 0 else 1
        # - Slice [::-1] creates a reversed copy of the string
        s_rev = str(abs(n))[::-1]
        res = int(s_rev) * sign
        
        # . Check bounds after conversion
        if res < -2**31 or res > 2**31 - 1:
            return 0
        return res

if __name__ == "__main__":
    sol = Solution()
    
    # - Standard case
    print(f"Standard: {sol.reverse_Math(123)}") 
    # - Trailing zero
    print(f"Trailing Zero: {sol.reverse_Pythonic(120)}") 
    # - Overflow case (Should return 0)
    print(f"Overflow: {sol.reverse_Math(1534236469)}")