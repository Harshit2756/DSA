import math

"""
Problem: Find the Least Common Multiple (LCM) of two numbers.

Example Input: n1 = 12, n2 = 15
Example Output: 60
Logic: 
    - Multiples of 12: 12, 24, 36, 48, 60...
    - Multiples of 15: 15, 30, 45, 60...
    - First match is 60.

Formula: LCM(a, b) = (a * b) // GCD(a, b)
"""

class Solution:

    # ~ Approach 1: Iterative (User's Logic - Optimized Step)
    # Analysis: Time O(A*B) worst case | Space O(1)
    # ! Still risky for large inputs, but better than step=1
    def lcmIterative(self, n1: int, n2: int) -> int:
        if n1 == 0 or n2 == 0: return 0
        
        # - Optimization: Always step by the larger number
        # If looking for LCM(4, 6), only check 6, 12, 18...
        # Checking 5, 7, 8 is a waste of time.
        larger = max(n1, n2)
        candidate = larger
        
        while True:
            if candidate % n1 == 0 and candidate % n2 == 0:
                return candidate
            candidate += larger

    # ~ Approach 2: Formulaic (Standard Interview Solution)
    # Analysis: Time O(log(min(a,b))) due to GCD | Space O(1)
    def lcmFormula(self, a: int, b: int) -> int:
        if a == 0 or b == 0: 
            return 0
        
        # - Calculate GCD first (Euclidean Algorithm)
        def gcd(x, y):
            while y:
                x, y = y, x % y
            return x
            
        # - Apply Formula: (a * b) // gcd(a, b)
        # - Use // for integer division
        return abs(a * b) // gcd(a, b)

    # ~ Approach 3: Python Built-in (For Real World)
    def lcmBuiltIn(self, a: int, b: int) -> int:
        # math.lcm is available in Python 3.9+
        return math.lcm(a, b)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    test_cases = [(4, 6), (12, 15), (7, 5), (2, 2)]
    
    print(f"{'Inputs':<10} | {'Formula Result':<15}")
    print("-" * 30)
    
    for n1, n2 in test_cases:
        res = sol.lcmFormula(n1, n2)
        print(f"{str((n1, n2)):<10} | {res:<15}")