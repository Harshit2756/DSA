from collections import Counter
import sys

# Header Comment Block
# Problem: Sum of Highest and Lowest Frequencies.
# Input: Array of integers.
# Output: Sum (int).
# Goal: O(N) Time.

class Solution:

    # ~ Approach 1: Sorting (Your Solution)
    # Analysis: Time O(N + U log U) | Space O(N)
    # Note: 'U' is the number of unique elements. 
    # If all elements are unique, this becomes O(N log N).
    def sumHighestAndLowestSorting(self, nums):
        if not nums: return 0
        
        count = Counter(nums)
        
        # - Step 1: Get Unique Sorted Frequencies
        # set() removes duplicates, sorted() orders them
        Frq = sorted(list(set(count.values())))
        
        # - Step 2: Add First (Min) and Last (Max)
        return Frq[0] + Frq[-1]


    # ~ Approach 2: Min/Max Functions (Optimal / Pythonic)
    # Analysis: Time O(N) | Space O(N)
    # Why: We avoid sorting entirely. Finding min and max takes O(U) time.
    def sumHighestAndLowestOptimal(self, nums):
        if not nums: return 0
        
        # - Step 1: Count Frequencies
        counts = Counter(nums)
        
        # - Step 2: Get all frequency values
        freq_values = counts.values()
        
        # - Step 3: Find Max and Min directly
        # Internal Logic: Iterates through the list once for max, once for min.
        high_freq = max(freq_values)
        low_freq  = min(freq_values)
        
        return high_freq + low_freq

    # ~ Approach 3: Manual Loop (The "Under the Hood" Way)
    # Analysis: Time O(N) | Space O(N)
    def sumHighestAndLowestManual(self, nums):
        if not nums: return 0
        
        # - Step 1: Count Frequencies
        # Time: O(N)
        counts = Counter(nums)
        
        # - Step 2: Initialize Extremes
        # We start min with infinity so the first number we see is smaller.
        # We start max with -1 (or -inf) so the first number is larger.
        min_freq = float('inf')
        max_freq = float('-inf')
        
        # - Step 3: Single Pass Loop
        # Time: O(U) where U is unique elements
        for freq in counts.values():
            
            # Update Max
            if freq > max_freq:
                max_freq = freq
                
            # Update Min
            if freq < min_freq:
                min_freq = freq
                
        # - Step 4: Return Sum
        return max_freq + min_freq


# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Ex 1: Freqs {1:1, 2:2, 3:3} -> Min 1, Max 3 -> Sum 4
    arr1 = [1, 2, 2, 3, 3, 3]
    
    # Ex 2: Freqs {4:2, 5:2, 6:1} -> Min 1, Max 2 -> Sum 3
    arr2 = [4, 4, 5, 5, 6]
    
    # Edge Case: Single Element [1] -> Freq {1:1} -> Min 1, Max 1 -> Sum 2
    arr3 = [1]

    print(f"Sorting Approach (Ex1): {sol.sumHighestAndLowestSorting(arr1)}")
    print(f"Optimal Approach (Ex1): {sol.sumHighestAndLowestOptimal(arr1)}")
    print(f"Optimal Approach (Ex3): {sol.sumHighestAndLowestOptimal(arr3)}")