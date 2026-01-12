import sys

# Optional: Increase recursion limit for large arrays
sys.setrecursionlimit(2000)

class Solution:
    # ~ Approach: Recursive Two Pointers
    # Analysis: Time O(N) | Space O(N) (due to recursion stack)
    def reverseArray(self, nums):
        if not nums:
            return []
            
        self._reverse_recursive(nums, 0, len(nums) - 1)
        return nums

    def _reverse_recursive(self, nums, left, right):
        # Base Case: Pointers meet or cross
        if left >= right:
            return 
        
        # Action: Swap
        nums[left], nums[right] = nums[right], nums[left]
        
        # Recursive Step: Move inward
        self._reverse_recursive(nums, left + 1, right - 1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 4, 5]
    print(f"Reversed: {sol.reverseArray(arr)}") # [5, 4, 3, 2, 1]