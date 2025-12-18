# Header Comment Block
# Problem: Check if a number is a Palindrome.
# Example Input: n = 121 -> Output: True
# Example Input: n = -121 -> Output: False (Reads as 121-)
# Goal: O(log N) Time | O(1) Space.

class Solution:
    # ~ Approach 1: Mathematical Reversal (Standard)
    # Analysis: Time O(log N) | Space O(1)
    # Pros: No extra space used for strings.
    def isPalindrome_Math(self, n: int) -> bool:
        # ! Edge Case: Negative numbers are not palindromes
        if n < 0:
            return False
            
        original = n
        reversed_num = 0
        
        while n > 0:
            digit = n % 10
            reversed_num = (reversed_num * 10) + digit
            n //= 10
            
        return original == reversed_num

    # ~ Approach 2: String Slicing (Pythonic)
    # Analysis: Time O(log N) | Space O(log N)
    # Pros: Readable one-liner.
    def isPalindrome_String(self, n: int) -> bool:
        s = str(n)
        return s == s[::-1]

if __name__ == "__main__":
    sol = Solution()
    
    # Test Cases
    print(f"121:  {sol.isPalindrome_Math(121)}")
    print(f"-121: {sol.isPalindrome_Math(-121)}")
    print(f"10:   {sol.isPalindrome_Math(10)}")

