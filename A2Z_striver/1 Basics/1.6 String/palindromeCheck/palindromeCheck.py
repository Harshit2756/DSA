class Solution:
    # ~ Approach 1: Two Pointers (Optimal)
    # Analysis: Time O(N) | Space O(1)
    def isPalindrome(self, s):
        left = 0
        right = len(s) - 1
        
        while left < right:
            # - Logic: Mismatch found -> Not a palindrome
            if s[left] != s[right]:
                return False
            
            # - Step: Move inward
            left += 1
            right -= 1
            
        return True

    # ~ Approach 2: String Slicing (Pythonic)
    # Analysis: Time O(N) | Space O(N)
    # Note: Creates a copy of the string in memory.
    def isPalindromeSlice(self, s):
        return s == s[::-1]

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    s1 = "hannah"
    s2 = "aabbaaa"
    
    print(f"Test 1 ('{s1}'): {sol.isPalindrome(s1)}") # True
    print(f"Test 2 ('{s2}'): {sol.isPalindrome(s2)}") # False