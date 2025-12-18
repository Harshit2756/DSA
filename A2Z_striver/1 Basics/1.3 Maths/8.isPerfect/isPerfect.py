import math

"""
Problem: Check if a number is a Perfect Number.
A Perfect Number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.

Example Input: 28
Example Output: True
Logic: Divisors of 28 (excluding 28) are 1, 2, 4, 7, 14.
       Sum = 1 + 2 + 4 + 7 + 14 = 28.

Constraints:
    - 1 <= n <= 10^8 (Typical constraint)
    - O(sqrt(N)) Time Complexity required.
"""

class Solution:

    # ~ Approach 1: Brute Force (User's Logic)
    # Analysis: Time O(N) | Space O(1)
    # ! RISK: TLE on large inputs
    def isPerfectBrute(self, n: int) -> bool:
        if n <= 1: return False
        s = 0
        for i in range(1, n):
            if n % i == 0:
                s += i
        return s == n

    # ~ Approach 2: Square Root Optimization (Standard Interview Solution)
    # Analysis: Time O(sqrt(N)) | Space O(1)
    def isPerfectOptimized(self, n: int) -> bool:
        # ! Edge Case: 1 is not a perfect number (sum of proper divisors is 0)
        if n <= 1:
            return False
        
        # Start sum at 1 because 1 is always a proper divisor for n > 1
        s = 1
        
        # - Iterate only up to square root of n
        # - Example n=28, sqrt=5.29. Loop runs 2 to 5.
        for i in range(2, int(math.isqrt(n)) + 1):
            if n % i == 0:
                s += i
                # . Optimization: Add the pair divisor immediately
                # If i=2, pair=14. Add both.
                pair_divisor = n // i
                if pair_divisor != i: # Avoid double counting for perfect squares (e.g., 6*6=36)
                    s += pair_divisor
                    
        return s == n

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # 6, 28, 496, 8128 are the first few Perfect Numbers
    test_cases = [6, 28, 496, 12, 1, 100]
    
    print(f"{'Number':<10} | {'Optimized Result':<15}")
    print("-" * 30)
    
    for num in test_cases:
        result = sol.isPerfectOptimized(num)
        print(f"{num:<10} | {str(result):<15}")

