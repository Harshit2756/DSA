
# Header Comment Block
# Problem: Find the largest digit in a number N.
# Example Input: n = 492 -> Output: 9
# Example Input: n = -58 -> Output: 8
# Goal: O(log N) Time | O(1) Space.

class Solution:
    # ~ Approach 1: Iterative Extraction (Math)
    # Analysis: Time O(log N) | Space O(1)
    def largestDigit_Math(self, n: int) -> int:
        # ! Handle Negatives: Convert to absolute value
        n = abs(n)
        
        # ! Edge Case: 0
        if n == 0: return 0
        
        max_digit = 0
        
        while n > 0:
            val = n % 10
            if val > max_digit:
                max_digit = val
            
            # . Optimization: If we found 9, we can't get higher.
            if max_digit == 9:
                return 9
                
            n //= 10
            
        return max_digit

    # ~ Approach 2: String Conversion (Pythonic)
    # Analysis: Time O(log N) | Space O(log N)
    # Pros: One-liner using the max() function on the string characters.
    def largestDigit_String(self, n: int) -> int:
        return int(max(str(abs(n))))

if __name__ == "__main__":
    sol = Solution()
    
    # Test Cases
    print(f"492: {sol.largestDigit_Math(492)}")
    print(f"-58: {sol.largestDigit_Math(-58)}")
    print(f"0: {sol.largestDigit_Math(0)}")