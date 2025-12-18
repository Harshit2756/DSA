import math

# Header Comment Block
# Problem: Count all prime numbers from 0 up to n.
# Example Input: n = 20 -> Output: 8 (2, 3, 5, 7, 11, 13, 17, 19)
# Goal: Provide different implementation styles for the SAME problem.

class Solution:
    # ~ Approach 1: While-Loop Trial Division (Your Original Style)
    # Analysis: Time O(N sqrt N) | Space O(1)
    # . Fixed: Standardized variable naming and removed redundant checks.
    def countPrimes_While(self, n: int) -> int:
        def check_is_prime(num):
            # . Base case: Numbers less than 2 are not prime
            if num < 2: return False
            divisor = 2
            while divisor * divisor <= num:
                if num % divisor == 0:
                    return False
                divisor += 1
            return True

        count = 0
        for i in range(n + 1):
            if check_is_prime(i):
                count += 1
        return count

    # ~ Approach 2: For-Loop Trial Division with Step Optimization
    # Analysis: Time O(N sqrt N) | Space O(1)
    # . Optimization: Skips even numbers in the primality check.
    # . This effectively cuts the work of the inner loop in half.
    def countPrimes_Optimized(self, n: int) -> int:
        def check_is_prime(num):
            if num < 2: return False
            if num == 2: return True
            if num % 2 == 0: return False
            
            # Start from 3 and skip all even divisors
            for d in range(3, int(math.isqrt(num)) + 1, 2):
                if num % d == 0:
                    return False
            return True

        count = 0
        # - Iterate through the entire range [0, n]
        # . range(n + 1) ensures we include the number n itself
        for i in range(n + 1):
            if check_is_prime(i):
                count += 1
        return count

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    limit = 20
    
    print(f"Counting primes up to {limit}:")
    print(f"Original Style Result:  {sol.countPrimes_While(limit)}")
    print(f"Optimized Style Result: {sol.countPrimes_Optimized(limit)}")