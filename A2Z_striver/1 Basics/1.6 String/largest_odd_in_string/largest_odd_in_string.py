class Solution:
    # ~ Approach: Two Pointers (Start & End)
    # Analysis: Time O(N) | Space O(1)
    def largestOddNumber(self, s: str) -> str:
        n = len(s)
        
        # Step 1: Find the LAST odd digit (End Pointer)
        # We start from the right because the number ending later is mathematically larger.
        end = -1
        for i in range(n - 1, -1, -1):
            if int(s[i]) % 2 != 0:
                end = i
                break
        
        # If no odd digit found, return empty
        if end == -1:
            return ""
            
        # Step 2: Find the FIRST non-zero digit (Start Pointer)
        # We must strip leading zeros to satisfy the constraint.
        start = 0
        while start < end and s[start] == '0':
            start += 1
            
        # Step 3: Return the slice
        # s[start_index:end_index + 1] gives us the desired substring.
        return s[start : end + 1]

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Ex 1: Standard case
    print(f"Test 1: '{sol.largestOddNumber('52')}'")       # Output: "5"
    
    # Ex 2: Leading zeros case
    # Rightmost odd is '5' at index 3. Start moves past '00'.
    print(f"Test 2: '{sol.largestOddNumber('0052')}'")     # Output: "5"
    
    # Ex 3: All zeros/No odd
    print(f"Test 3: '{sol.largestOddNumber('0042')}'")     # Output: ""
    
    # Ex 4: Odd number is buried inside zeros
    # Rightmost odd is '7'. Start skips first '0'.
    print(f"Test 4: '{sol.largestOddNumber('010070')}'")   # Output: "1007"