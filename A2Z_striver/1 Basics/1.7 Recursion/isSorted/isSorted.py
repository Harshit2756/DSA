import sys
sys.setrecursionlimit(2000)

class Solution:
    def isSorted(self, nums):
        if not nums:
            return True
        return self.isSorted_recursive(nums, 0)

    def isSorted_recursive(self, nums, index):
        # ~ Base Case: Reached the last element?
        # If we are at the last index (len - 1), there is no "next" number to check.
        # So we are done, and the array is sorted.
        if index == len(nums) - 1:
            return True

        # ~ Check: Current vs Next
        # Note: If valid sorted is 1,2,2,3 (non-decreasing), use >
        # If valid sorted is 1,2,3 (strictly increasing), use >=
        if nums[index] > nums[index + 1]: 
            return False

        # ~ Recursive Step: Move to NEXT index
        # BUG FIX: changed '0' to 'index + 1'
        return self.isSorted_recursive(nums, index + 1)

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(sol.isSorted([1, 2, 3, 4, 5])) # True
    print(sol.isSorted([1, 2, 4, 3, 5])) # False