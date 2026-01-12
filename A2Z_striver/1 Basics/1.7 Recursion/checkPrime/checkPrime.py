import sys

# Optional: Increase recursion limit for medium-sized inputs if needed
sys.setrecursionlimit(2000)

class Solution:
    def checkPrime(self, num):
        if num <= 1:
            return False
        # Start recursion from 2
        return self.checkPrime_recursive(num, 2)

    def checkPrime_recursive(self, num, index):
        # ~ Optimization: Stop at sqrt(num)
        # If index^2 > num, we have checked all possible smaller factors.
        # It is Prime.
        if index * index > num:
            return True

        # Base Case: Found a divisor? Not Prime.
        if num % index == 0:
            return False

        # Recursive Step: Check next number
        return self.checkPrime_recursive(num, index + 1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(f"Check 7: {sol.checkPrime(7)}")       # True
    print(f"Check 10: {sol.checkPrime(10)}")     # False
    print(f"Check 97: {sol.checkPrime(97)}")     # True