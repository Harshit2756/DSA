import sys
from collections import Counter

# Header Comment Block
# Problem: Find the most frequent element (Smallest on tie).
# Approaches: Brute Force (Yours), Sorting, Hashing.

class Solution:

    # ~ Approach 1: Brute Force with Visited Array (Your Code)
    # Analysis: Time O(N^2) | Space O(N)
    def mostFrequentBrute(self, nums):
        n = len(nums)
        maxFr = 0
        maxEle = -1  # Init with infinity for proper min comparison
        visited = [False] * n
        for i in range(n):
            # - Logic: Skip if we already counted this number
            if visited[i]:
                continue

            fr = 0
            for j in range(i, n):
                if nums[i] == nums[j]:
                    fr += 1
                    visited[j] = True

            # - Logic: Update Max (Strict Greater)
            if fr > maxFr:
                maxFr = fr
                maxEle = nums[i]
            # - Logic: Tie-Breaker (Equal Freq) -> Pick Smaller
            elif fr == maxFr:
                maxEle = min(maxEle, nums[i])

        return maxEle

    # ~ Approach 2: Sorting
    # Analysis: Time O(N log N) | Space O(1) (depends on sort impl)
    def mostFrequentSorting(self, nums):
        if not nums:
            return -1

        nums.sort()  # O(N log N)
        n = len(nums)
        maxFr = 0
        maxEle = nums[0]
        currFr = 1

        # - Step: Iterate starting from index 1
        for i in range(1, n):
            if nums[i] == nums[i - 1]:
                currFr += 1
            else:
                currFr = 1  # Reset counter

            # - Logic: Update only if strictly greater.
            # Since array is sorted, we encounter smaller numbers first.
            # So for ties, we automatically keep the smaller one by doing nothing.
            if currFr > maxFr:
                maxFr = currFr
                maxEle = nums[i]

        # Edge case: If array length is 1 or all unique, initial maxEle is correct
        return maxEle if n > 1 else nums[0]

    # ~ Approach 3: Hashing (Optimal)
    # Analysis: Time O(N) | Space O(N)
    def mostFrequentHashing(self, nums):
        # - Step 1: Count Frequencies (One Liner)
        count = Counter(nums)
        maxFr = 0
        maxEle = -1
        # - Step 2: Iterate and Compare
        for num, fr in count.items():
            if fr > maxFr:
                maxFr = fr
                maxEle = num
            elif fr == maxFr:
                maxEle = min(maxEle, num)
        return maxEle


# --- Driver Code ---

if __name__ == "__main__":
    sol = Solution()

    # Test Case: 10 appears 2x, 20 appears 2x. Winner should be 10.
    arr = [20, 10, 20, 10, 30]

    print(f"1. Brute Force: {sol.mostFrequentBrute(arr)}")

    print(f"2. Sorting:     {sol.mostFrequentSorting(list(arr))}")  # Pass copy to avoid sorting original

    print(f"3. Hashing:     {sol.mostFrequentHashing(arr)}")
