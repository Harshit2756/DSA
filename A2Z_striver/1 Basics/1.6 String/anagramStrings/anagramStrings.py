from collections import Counter

class Solution:
    
    # ~ Approach 1: Sorting (The One-Liner)
    # Analysis: Time O(N log N) | Space O(N) or O(1) depending on sort implementation
    # Logic: "nagaram" sorted is "aaagmnr". "anagram" sorted is "aaagmnr". Equal!
    def isAnagramSorting(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        return sorted(s) == sorted(t)


    # ~ Approach 2: Hash Map (The Standard)
    # Analysis: Time O(N) | Space O(N)
    # Logic: Use Python's Counter to build frequency maps and compare them.
    def isAnagramHashMap(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        
        # Counter builds a dictionary like {'a': 3, 'n': 1, ...}
        return Counter(s) == Counter(t)


    # ~ Approach 3: Fixed-Size Array (The "Under the Hood" Optimized)
    # Analysis: Time O(N) | Space O(1) (We always use exactly 26 ints)
    # Logic: Increment index for s, decrement for t. All must be 0 at end.
    def isAnagramArray(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        
        # Array for 26 lowercase letters
        count = [0] * 26
        
        for i in range(len(s)):
            # ord('a') gives 97. ord(char) - 97 maps 'a'->0, 'b'->1...
            count[ord(s[i]) - ord('a')] += 1
            count[ord(t[i]) - ord('a')] -= 1
            
        # Check if any non-zero value remains
        for val in count:
            if val != 0:
                return False
                
        return True

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(f"Sorting: {sol.isAnagramSorting('anagram', 'nagaram')}")
    print(f"HashMap: {sol.isAnagramHashMap('rat', 'car')}")
    print(f"Array:   {sol.isAnagramArray('anagram', 'nagaram')}")