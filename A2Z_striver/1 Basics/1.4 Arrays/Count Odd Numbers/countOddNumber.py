"""
Problem: Count the number of odd integers in an array.

Example Input: [1, 2, 3, 4, 5]
Example Output: 3 (1, 3, 5)

Constraints:
    - O(N) Time
    - O(1) Space (Strict Requirement)
"""

class Solution:

    # ~ Approach 1: Generator Expression (Best Pythonic)
    # Analysis: Time O(N) | Space O(1)
    def countOddGenerator(self, arr: list[int]) -> int:
        # ! Logic: Removing [] turns list comprehension into a generator
        # This yields values one by one, using constant memory.
        return sum(1 for x in arr if x % 2 != 0)

    # ~ Approach 2: Explicit Loop (Best for C++/Java translation)
    # Analysis: Time O(N) | Space O(1)
    def countOddIterative(self, arr: list[int]) -> int:
        count = 0
        for x in arr:
            # Check bitwise for odd (faster than modulo in low-level langs)
            # if x & 1:  <-- slightly faster optimization for "is odd"
            if x % 2 != 0:
                count += 1
        return count

    # ~ Approach 3: Recursion (Educational / "Whiteboard" Practice)
    # Analysis: Time O(N) | Space O(N) due to Stack
    def countOddRecursive(self, arr: list[int], index: int = 0) -> int:
        # Base Case: End of array
        if index == len(arr):
            return 0
        
        # Recursive Step
        is_current_odd = 1 if arr[index] % 2 != 0 else 0
        return is_current_odd + self.countOddRecursive(arr, index + 1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 4, 5, 12, 13] 
    
    print(f"Array: {arr}")
    print(f"Generator Count: {sol.countOddGenerator(arr)}")
    print(f"Iterative Count: {sol.countOddIterative(arr)}")