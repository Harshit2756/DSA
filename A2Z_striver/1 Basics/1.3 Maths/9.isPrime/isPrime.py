import math

# Header Comment Block
# Problem: Check if a single integer n is prime efficiently.
# Example Input: n = 37 -> Output: True
# Example Input: n = 49 -> Output: False
# Goal: O(sqrt(N)) Time | O(1) Space.

class Solution:
    # ~ Approach 1: Basic Trial Division (Your Original)
    # Analysis: Time O(sqrt(N)) | Space O(1)
    # . Simple and easy to recall under pressure.
    def isPrime_Basic(self, n: int) -> bool:
        if n <= 1: return False
        for i in range(2, int(math.isqrt(n)) + 1):
            if n % i == 0:
                return False
        return True

    # ~ Approach 2: Optimized Trial Division (The "Elite" Way)
    # Analysis: Time O(sqrt(N) / 3) | Space O(1)
    # ! Fix: Handles 2 and 3 as base cases to allow for faster jumping.
    def is_prime_optimized(self, n: int) -> bool:
        # - 1. Handle base cases
        if n <= 1: return False
        if n <= 3: return True  # 2 and 3 are prime
        
        # - 2. Eliminate even numbers and multiples of 3
        if n % 2 == 0 or n % 3 == 0:
            return False
        
        # - 3. Check divisors using 6k ± 1 pattern
        # . We start at 5 and increment by 6 (checking 5, 7, 11, 13, 17, 19...)
        # . This skips 2, 3, and all their multiples.
        limit = int(math.isqrt(n))
        for i in range(5, limit + 1, 6):
            if n % i == 0 or n % (i + 2) == 0:
                return False
                
        return True

if __name__ == "__main__":
    sol = Solution()
    
    # Test Cases
    test_val = 997 # A known prime
    print(f"Basic Check ({test_val}):    {sol.isPrime_Basic(test_val)}")
    print(f"Optimized Check ({test_val}): {sol.is_prime_optimized(test_val)}")
    
    # Check a composite number
    print(f"Optimized Check (121):   {sol.is_prime_optimized(121)}")