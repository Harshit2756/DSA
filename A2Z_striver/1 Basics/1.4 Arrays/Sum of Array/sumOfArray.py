"""
Problem: Calculate the sum of elements in an array.

Example Input: [1, 2, 3]
Example Output: 6

Constraints:
    - O(N) Time
    - O(1) Space
"""

class Solution:

    # ~ Approach 1: Pythonic (The Standard)
    # Analysis: Time O(N) | Space O(1)
    def arraySumBuiltIn(self, arr: list[int]) -> int:
        # ! Direct call avoids creating a copy
        return sum(arr)

    # ~ Approach 2: Iterative (Language Agnostic)
    # Analysis: Time O(N) | Space O(1)
    def arraySumIterative(self, arr: list[int]) -> int:
        total = 0
        for num in arr:
            total += num
        return total

    # ~ Approach 3: Recursive (Educational)
    # Analysis: Time O(N) | Space O(N) due to Recursion Stack
    def arraySumRecursive(self, arr: list[int], n: int) -> int:
        # Base Case: No elements left
        if n <= 0:
            return 0
        
        # Recursive Step: Sum last element + Sum of the rest
        # (Using n-1 as index is a common pattern)
        return arr[n-1] + self.arraySumRecursive(arr, n-1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    arr = [1, 5, 10, 20]
    n = len(arr)
    
    print(f"Built-in:  {sol.arraySumBuiltIn(arr)}")
    print(f"Iterative: {sol.arraySumIterative(arr)}")
    print(f"Recursive: {sol.arraySumRecursive(arr, n)}")