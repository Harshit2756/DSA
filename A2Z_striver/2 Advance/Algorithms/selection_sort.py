from typing import List
# Animation here: https://algomaster.io/animations/dsa/selection-sort
class Solution:
    # ~ Approach: Selection Sort
    # Analysis: Time O(N^2) | Space O(1)
    # Pros: Simple, minimizes swaps (max N swaps).
    # Cons: Slow for large datasets.
    def selectionSort(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        # We only need to go up to n-1 because the last element will automatically be in the correct place.
        for i in range(n - 1):
            
            # Step 1: Assume current index is minimum
            min_index = i
            
            # Step 2: Search for a smaller element in the rest of the array
            for j in range(i + 1, n):
                if nums[j] < nums[min_index]:
                    min_index = j
            
            # Step 3: Swap if a new minimum was found
            if min_index != i:
                nums[i], nums[min_index] = nums[min_index], nums[i]
                
        return nums

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    arr = [64, 25, 12, 22, 11]
    print(f"Sorted: {sol.selectionSort(arr)}") 
    # Output: [11, 12, 22, 25, 64]