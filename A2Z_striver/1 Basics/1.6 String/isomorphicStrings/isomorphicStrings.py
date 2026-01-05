class Solution:
    # ~ Approach 1: Two Hash Maps (Most Readable)
    # Analysis: Time O(N) | Space O(N)
    def isomorphicStrings(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        map_s_t = {} # Maps s -> t
        map_t_s = {} # Maps t -> s
        
        for c1, c2 in zip(s, t):
            # Case 1: c1 is seen before. Check consistency.
            if c1 in map_s_t:
                if map_s_t[c1] != c2:
                    return False
            
            # Case 2: c2 is seen before. Check consistency.
            if c2 in map_t_s:
                if map_t_s[c2] != c1:
                    return False
            
            # Case 3: New mapping. Add to both maps.
            map_s_t[c1] = c2
            map_t_s[c2] = c1
            
        return True

    # ~ Approach 2: One Map + One Set (Slightly faster in Python)
    # This fixes your original logic by using a Set for O(1) lookups
    def isomorphicStringsOptimized(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        
        mapping = {}
        used_chars = set() # Replaces checking c.values()
        
        for c1, c2 in zip(s, t):
            if c1 in mapping:
                # If mapped, must match current char in t
                if mapping[c1] != c2:
                    return False
            else:
                # If not mapped, ensure c2 isn't already used by someone else
                if c2 in used_chars:
                    return False
                
                mapping[c1] = c2
                used_chars.add(c2)
                
        return True

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(sol.isomorphicStrings("egg", "add"))  # True
    print(sol.isomorphicStrings("foo", "bar"))  # False
    print(sol.isomorphicStrings("paper", "title")) # True