"""
Problem: Array Sum via Recursion
Approach: Head Recursion with Indexing (Avoiding Slices)
Engineering Constraints: 
- Avoid O(N) slicing to maintain O(N) time complexity.
- Mimic C-style pointer arithmetic using an index pointer.
"""

class Solution:
    # ~ Approach 1: Index-Based Head Recursion (The "C++ Bridge" Fix)
    # Analysis: Time O(N) / Space O(N)
    # >> C++ Perspective: Mimics passing a pointer and incrementing it (arr + idx).
    # ! Fixes applied: Replaced nums[1:] with an index to prevent O(N) copies.
    def arraySum(self, nums, idx=0):
        # Base Case: Pointer has reached the end of the memory block
        if idx == len(nums):
            return 0
        
        # . Logic: Current element + recursive call for the next 'memory address'
        return nums[idx] + self.arraySum(nums, idx + 1)

    # ~ Approach 2: Tail Recursion (Optimized Structure)
    # Analysis: Time O(N) / Space O(N) in Python
    # >> C++ Perspective: Tail-call optimized by compilers into a loop.
    def arraySum_tail(self, nums, idx=0, acc=0):
        if idx == len(nums):
            return acc
        return self.arraySum_tail(nums, idx + 1, acc + nums[idx])

    # ~ Approach 3: Head Recursion (Your Current Solution)
    # Analysis: Time O(N) / Space O(N)
    # >> C++ Perspective: Equivalent to: return *(ptr) + recursive_call(ptr + 1)
    # . Memory Efficiency: Improved! No list copies, only integer increments.
    def arraySum(self, nums: list[int]) -> int:
        return self._sum_recursive(nums, 0)

    def _sum_recursive(self, nums, index):
        # Base case: Pointer is out of bounds
        if index >= len(nums):
            return 0
        
        # ! Head Recursion: Pending addition waits for the stack to unwind
        return nums[index] + self._sum_recursive(nums, index + 1)
    
if __name__ == "__main__":
    sol = Solution()
    test_arr = [1, 2, 3, 4, 5]
    
    # >> Engineering Note: Always prefer iterative for arrays in Python.
    print(f"Index-based Sum: {sol.arraySum(test_arr)}")
    print(f"Tail-recursive Sum: {sol.arraySum_tail(test_arr)}")