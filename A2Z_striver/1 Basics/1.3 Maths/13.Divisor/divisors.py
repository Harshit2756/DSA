import math

"""
Problem: Find all divisors of a number n.

Example Input: 36
Example Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]

Constraints:
    - 1 <= n <= 10^9
    - Return list sorted ascendingly (usually required).
"""

class Solution:

    # ~ Approach 1: Brute Force (User's Logic)
    # Analysis: Time O(N) | Space O(D)
    # ! SLOW for large N
    def printDivisorsBrute(self, n: int) -> list[int]:
        divs = []
        for i in range(1, n + 1):
            if n % i == 0:
                divs.append(i)
        return divs

    # ~ Approach 2: Square Root Optimization (Interview Standard)
    # Analysis: Time O(sqrt(N)) | Space O(D)
    def printDivisorsOptimized(self, n: int) -> list[int]:
        divs = []
        
        # - Iterate only up to sqrt(n)
        for i in range(1, int(math.isqrt(n)) + 1):
            if n % i == 0:
                divs.append(i) # Add the small divisor
                
                # - Check if the pair is distinct (avoid duplicates for perfect squares)
                if i != n // i:
                    divs.append(n // i) # Add the large pair divisor
        
        # ! The result will be unsorted (e.g., [1, 36, 2, 18...])
        # Sorting is efficient here because D (count of divisors) is usually small relative to N.
        divs.sort()
        
        return divs

    # ~ Approach 3: Alternative Square Root Optimization (while loop)
    # Analysis: Time O(sqrt(N)) | Space O(D)
    
    def printdivisorsOptimized2(self, n: int) -> list[int]:
        divisor=[]

        a = 1
        while a**2 <= n:    
            if n%a==0:
                divisor.append(a)
                if a != n // a:
                    divisor.append(n // a)
            a+=1
        divisor.sort()
        return divisor 

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    test_cases = [36, 1, 97, 100] # 97 is prime
    
    print(f"{'N':<5} | {'Divisors (Optimized)':<30}")
    print("-" * 40)
    
    for n in test_cases:
        result = sol.printDivisorsOptimized(n)
        print(f"{n:<5} | {str(result):<30}")