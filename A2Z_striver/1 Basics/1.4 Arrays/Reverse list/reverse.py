"""
Problem: Reverse an array in-place.

Example Input: [1, 2, 3, 4, 5]
Example Output: [5, 4, 3, 2, 1]

Constraints:
    - O(N) Time
    - O(1) Space (No extra array allowed)
"""

class Solution:

    # ~ Approach 1: Iterative Two Pointers (User's Logic + Pythonic Syntax)
    # Analysis: Time O(N) | Space O(1)
    def reverseIterative(self, arr: list[int], n: int) -> None:
        # Use integer division //
        for i in range(n // 2):
            # ! Pythonic Tuple Swap
            # Swaps left element (i) with right element (n-1-i)
            arr[i], arr[n - 1 - i] = arr[n - 1 - i], arr[i]

    # ~ Approach 2: Explicit Two Pointers (While Loop)
    # Analysis: Time O(N) | Space O(1)
    # This is the most "Universal" interview answer (applies to C++, Java, etc.)
    def reverseExplicit(self, arr: list[int], n: int) -> None:
        start = 0
        end = n - 1
        
        while start < end:
            # Swap
            arr[start], arr[end] = arr[end], arr[start]
            # Move pointers inward
            start += 1
            end -= 1

    # ~ Approach 3: Recursive (Educational)
    # Analysis: Time O(N) | Space O(N) due to Recursion Stack
    def reverseRecursive(self, arr: list[int], start: int, end: int) -> None:
        if start >= end:
            return
            
        arr[start], arr[end] = arr[end], arr[start]
        self.reverseRecursive(arr, start + 1, end - 1)

    # ~ Approach 4: Python Slicing (The "Cheat")
    # Analysis: Time O(N) | Space O(N) internally (usually creates copy)
    def reverseSlicing(self, arr: list[int]) -> None:
        # arr[:] selects all elements and replaces them
        arr[:] = arr[::-1]

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    arr = [10, 20, 30, 40, 50]
    n = len(arr)
    
    print(f"Original: {arr}")
    sol.reverseExplicit(arr, n)
    print(f"Reversed: {arr}")