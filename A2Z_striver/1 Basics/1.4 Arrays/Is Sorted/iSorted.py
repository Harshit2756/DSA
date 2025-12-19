import sys

"""
Problem: Check if an array is sorted (non-decreasing).

Example Input: [10, 20, 30, 40]
Example Output: True

Constraints:
    - O(N) Time
    - O(1) Space
    - Handle empty or single-element arrays (trivially sorted).
"""

class Solution:

    # ~ Approach 1: Pythonic One-Liner (Fixed)
    # Analysis: Time O(N) | Space O(1)
    def isSortedPythonic(self, arr: list[int], n: int) -> bool:
        # ! Fix: range(n - 1) prevents IndexError
        # If n=0 or n=1, range is empty -> returns True (Correct)
        return all(arr[i] <= arr[i + 1] for i in range(n - 1))

    # ~ Approach 2: Iterative (Standard Interview)
    # Analysis: Time O(N) | Space O(1)
    def isSortedIterative(self, arr: list[int], n: int) -> bool:
        # Iterate up to the second to last element
        for i in range(n - 1):
            # If we find ANY pair out of order, return False immediately
            if arr[i] > arr[i + 1]:
                return False
        return True

    # ~ Approach 3: Recursive (Educational)
    # Analysis: Time O(N) | Space O(N) due to recursion stack
    def isSortedRecursive(self, arr: list[int], n: int) -> bool:
        # Base Case: Array with 0 or 1 element is sorted
        if n <= 1:
            return True
            
        # Check last pair: If last two are out of order, return False
        if arr[n - 2] > arr[n - 1]:
            return False
            
        # Recursive Step: Check the rest of the array (size n-1)
        return self.isSortedRecursive(arr, n - 1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Test Cases: Sorted, Unsorted, Edge Cases
    test_cases = [
        ([1, 2, 3, 4, 5], 5),
        ([1, 5, 3, 4, 2], 5),
        ([10], 1),
        ([], 0)
    ]
    
    print(f"{'Array':<20} | {'Is Sorted?':<10}")
    print("-" * 35)
    
    for arr, n in test_cases:
        # Note: Usually we derive n from len(arr), but respecting signature
        result = sol.isSortedPythonic(arr, n)
        print(f"{str(arr):<20} | {str(result):<10}")