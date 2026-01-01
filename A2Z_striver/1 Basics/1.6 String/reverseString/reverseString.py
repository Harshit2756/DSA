class Solution:
    # ~ Approach: Two Pointers (Optimal)
    # Analysis: Time O(N) | Space O(1)
    def reverseString(self, s):
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1
        
        # - Step: Iterate until pointers meet
        while left < right:
            # - Logic: Swap elements
            # Python allows tuple unpacking for easy swapping
            s[left], s[right] = s[right], s[left]
            
            # - Step: Move pointers inward
            left += 1
            right -= 1

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case
    s = ["h","e","l","l","o"]
    sol.reverseString(s)
    
    print(f"Reversed: {s}") 
    # Output: ['o', 'l', 'l', 'e', 'h']