class Solution:
    # ~ Approach 1: Clever Concatenation (Optimal)
    # Analysis: Time O(N) | Space O(N)
    # Why: 's + s' contains all possible rotations. We just check if 'goal' is a substring.
    def rotateStringOptimal(self, s: str, goal: str) -> bool:
            
        # Length check (Crucial!)
        # "abc" + "abc" contains "abc", but "abc" is not a rotation of "ab"
        # Checks if goal is inside s+s
        return len(s) == len(goal) and goal in (s + s)

    # ~ Approach 2: Simulation (Your Loop Code)
    # Analysis: Time O(N^2) | Space O(N)
    # Why: String slicing s[:-1] takes O(N). Doing it N times = O(N^2).
    def rotateStringSimulation(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
            
        # Check original first
        if s == goal: return True
        
        # Try all N rotations
        for _ in range(len(s)):
            # Rotate: Move first char to end
            # s[1:] is the rest, s[0] is the first char
            s = s[1:] + s[0] 
            
            if s == goal:
                return True
                
        return False
    
    # ~ Approach 3: KMP Algorithm (Theoretical Optimal)
    # Analysis: Time O(N) | Space O(N)
    # Guarantees linear time even in worst-case scenarios (e.g., "aaaaa...b")
    def rotateStringKMP(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        
        # Text is s+s, Pattern is goal
        text = s + s
        pattern = goal
        return self.kmp_search(text, pattern)

    def kmp_search(self, text, pattern):
        n = len(text)
        m = len(pattern)
        if m == 0: return True
        
        # Step 1: Build LPS Array for the Pattern
        lps = [0] * m
        prev_lps = 0
        i = 1
        
        while i < m:
            if pattern[i] == pattern[prev_lps]:
                prev_lps += 1
                lps[i] = prev_lps
                i += 1
            else:
                if prev_lps == 0:
                    lps[i] = 0
                    i += 1
                else:
                    prev_lps = lps[prev_lps - 1]
        
        # Step 2: Search Pattern in Text
        i = 0 # text index
        j = 0 # pattern index
        while i < n:
            if text[i] == pattern[j]:
                i += 1
                j += 1
                
                # Found the full pattern
                if j == m:
                    return True
            else:
                # Mismatch after some matches
                if j > 0:
                    # Do not move i (text pointer), just rollback j using LPS
                    j = lps[j - 1]
                else:
                    # No matches yet, just move text pointer
                    i += 1
                    
        return False

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(sol.rotateStringOptimal("abcde", "cdeab")) # True
    print(sol.rotateStringOptimal("abcde", "abced")) # False