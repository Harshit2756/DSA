"""
Problem: Find the Greatest Common Divisor (GCD) of two numbers.

Example Input: a = 48, b = 18
Example Output: 6
Logic: 
    - 48 % 18 = 12
    - 18 % 12 = 6
    - 12 % 6 = 0  -> GCD is 6

Constraints:
    - 0 <= a, b <= 10^9
    - O(log(min(a, b))) Time Complexity required (Euclidean Algorithm).
"""

class Solution:

    # ~ Approach 1: Brute Force (User's Logic - Cleaned)
    # Analysis: Time O(min(a,b)) | Space O(1)
    # ! RISK: TLE on large inputs
    def gcdBrute(self, a: int, b: int) -> int:
        if a==b:
            return a
        minimum = min(a, b)
        ans = 1
        # . Optimization: Iterate backwards to find the "Greatest" sooner
        for i in range(minimum, 0, -1):
            if a % i == 0 and b % i == 0:
                return i
        return ans

    # ~ Approach 2: Euclidean Algorithm (Iterative)
    # Analysis: Time O(log(min(a,b))) | Space O(1)
    # This is the "Gold Standard" for interviews.
    def gcdEuclidean(self, a: int, b: int) -> int:
        while b > 0:
            # - Update a to be b, and b to be remainder of a/b
            a, b = b, a % b
        return a

    # ~ Approach 3: Euclidean Algorithm (Recursive)
    # Analysis: Time O(log(min(a,b))) | Space O(log(min(a,b))) due to recursion stack
    def gcdRecursive(self, a: int, b: int) -> int:
        if b == 0:
            return a
        return self.gcdRecursive(b, a % b)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    test_cases = [(48, 18), (101, 10), (270, 192), (7, 13)]
    
    print(f"{'Inputs':<15} | {'Euclidean Result':<15}")
    print("-" * 35)
    
    for a, b in test_cases:
        res = sol.gcdEuclidean(a, b)
        print(f"{str((a, b)):<15} | {res:<15}")