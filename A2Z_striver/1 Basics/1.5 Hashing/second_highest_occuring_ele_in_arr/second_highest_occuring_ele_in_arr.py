from collections import Counter
import sys

# Header Comment Block
# Problem: Find Second Highest Occurring Element (Strictly lower frequency).
# Logic: If multiple elements appear second most times, find the smallest value.
# Return -1 if no second frequent element exists.

class Solution:

    # ~ Approach 1: Frequency Sorting (Mental Model)
    # Analysis: Time O(N log N) | Space O(N)
    def secondMostFrequentSorting(self, nums):
        if not nums: return -1
        counts = Counter(nums)
        
        # - Step 1: Get Unique Frequencies Descending
        # Ex: {4:2, 5:2, 6:1} -> Freqs [2, 1]
        unique_freqs = sorted(list(set(counts.values())), reverse=True)
        
        # If less than 2 distinct frequencies, no second place exists
        if len(unique_freqs) < 2:
            return -1
            
        target_freq = unique_freqs[1]
        
        # - Step 2: Find smallest element with target_freq
        min_ele = float('inf')
        for num, fr in counts.items():
            if fr == target_freq:
                min_ele = min(min_ele, num)
                
        return min_ele


    # ~ Approach 2: One-Pass Traversal (Your Logic)
    # Analysis: Time O(N) | Space O(N)
    def secondMostFrequentTraversal(self, nums):
        count = Counter(nums)

        # Init with -1 so we can return it directly if no second exists
        MaxEle = -1
        secEle = -1
        
        maxFr = 0
        secFr = 0

        for ele, fr in count.items():
            
            # Case 1: New Max Found
            # The old Max becomes the new "Best Second Place Candidate"
            if fr > maxFr:
                secEle, secFr = MaxEle, maxFr
                MaxEle, maxFr = ele, fr
            
            # Case 2: Tie for Max
            # Update MaxEle to smallest value. 
            # DO NOT update secEle, because 'ele' has maxFr (not strictly lower)
            elif fr == maxFr:
                MaxEle = min(MaxEle, ele)
            
            # Case 3: New Second Max Found
            # Strictly less than maxFr, but better than current secFr
            elif fr > secFr:
                secEle, secFr = ele, fr
            
            # Case 4: Tie for Second Max
            # Smallest value tie-breaker
            elif fr == secFr:
                if secEle == -1: # Handle initialization edge case
                    secEle = ele
                else:
                    secEle = min(secEle, ele)

        return secEle

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Ex 1: [1, 2, 2, 3, 3, 3] -> Max(3) is 3, Sec(2) is 2.
    print(f"Test 1: {sol.secondMostFrequentTraversal([1, 2, 2, 3, 3, 3])}") 
    
    # Ex 2: [4, 4, 5, 5, 6, 7] -> Max(2) is 4/5. Sec(1) is 6/7. Smallest is 6.
    print(f"Test 2: {sol.secondMostFrequentTraversal([4, 4, 5, 5, 6, 7])}")
    
    # Ex 3: [1, 1, 2, 2] -> Max(2). No strictly lower freq. Return -1.
    print(f"Test 3: {sol.secondMostFrequentTraversal([1, 1, 2, 2])}")