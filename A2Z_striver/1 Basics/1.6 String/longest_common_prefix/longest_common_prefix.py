from typing import List

class Solution:
    
    # ~ Approach 1: Horizontal Scanning (Iterative Reduction)
    # Analysis: Time O(S) | Space O(1)
    # Logic: Take string[0]. Compare with string[1], cut excess. 
    #        Compare result with string[2], cut excess.
    def longestCommonPrefixHorizontal(self, strs: List[str]) -> str:
        if not strs: return ""
        
        # Start assuming the whole first string is the prefix
        prefix = strs[0]
        
        for i in range(1, len(strs)):
            # While the current string 's' does not start with 'prefix'
            # (find() returns 0 if it starts with it, -1 or >0 otherwise)
            while strs[i].find(prefix) != 0:
                # Shorten the prefix by one character from the end
                prefix = prefix[:-1]
                if not prefix: return ""
                
        return prefix

    # ~ Approach 2: Vertical Scanning (Column by Column)
    # Analysis: Time O(S) | Space O(1)
    # Logic: Check index 0 of all strings. Then index 1. Stop at mismatch.
    # BEST for: "Fail fast" if strings differ early.
    def longestCommonPrefixVertical(self, strs: List[str]) -> str:
        if not strs: return ""
        
        # Iterate over columns (chars of first string)
        for i in range(len(strs[0])):
            char = strs[0][i]
            
            # Iterate over rows (rest of the strings)
            for j in range(1, len(strs)):
                # Stop if:
                # 1. We run past the end of string j
                # 2. Character mismatch
                if i == len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]
                    
        return strs[0]

    # ~ Approach 3: Sorting (The Interview Favorite)
    # Analysis: Time O(N log N) | Space O(1)
    # Logic: Sort -> First and Last strings are most different. Compare them.
    def longestCommonPrefixSorting(self, strs: List[str]) -> str:
        if not strs: return ""
        strs.sort()
        first = strs[0]
        last = strs[-1]
        ans = []
        for i in range(min(len(first),len(last))):
            if first[i] != last[i]:
                return ''.join(ans)
            ans.append(first[i])
            # print(f"{ans} : {first[i]}")
        
        return ''.join(ans)

    # ~ Approach 4: Binary Search (Length Optimization)
    # Analysis: Time O(S * log M) where M is min_len
    # Logic: Guess length K. Check if all strings share prefix of length K.
    #        If yes, try longer. If no, try shorter.
    def longestCommonPrefixBinarySearch(self, strs: List[str]) -> str:
        if not strs: return ""
        
        # Find minimum length in array
        minLen = min(len(s) for s in strs)
        
        low, high = 1, minLen
        while low <= high:
            mid = (low + high) // 2
            if self.isCommon(strs, mid):
                low = mid + 1 # Try longer
            else:
                high = mid - 1 # Try shorter
                
        return strs[0][:(low + high) // 2]

    # Helper for Binary Search
    def isCommon(self, strs, length):
        str0 = strs[0][:length]
        for i in range(1, len(strs)):
            if not strs[i].startswith(str0):
                return False
        return True

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    arr = ["flower", "flow", "flight"]
    
    print(f"Horizontal: {sol.longestCommonPrefixHorizontal(arr)}")
    print(f"Vertical:   {sol.longestCommonPrefixVertical(arr)}")
    print(f"Sorting:    {sol.longestCommonPrefixSorting(list(arr))}")
    print(f"BinSearch:  {sol.longestCommonPrefixBinarySearch(arr)}")