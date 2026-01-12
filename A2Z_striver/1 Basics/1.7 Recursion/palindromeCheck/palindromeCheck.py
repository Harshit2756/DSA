"""
Problem: Palindrome Check
Approach: Two-Pointer Tail Recursion
Engineering Constraints:
- String access must be O(1).
- Avoid slicing (s[1:-1]) to prevent O(N) memory copies.
"""

class Solution:
    # ~ Approach 1: Two-Pointer Linear Recursion (Your Approach)
    # Analysis: Time O(N) / Space O(N) stack
    # >> C++ Perspective: High-level abstraction of a 'while' loop.
    # >> C++ Perspective: Equivalent to iterating with two pointers from outside-in.
    # . Memory Efficiency: High (No new string objects created).
    def palindromeCheck(self, s: str) -> bool:
        # Standardize input if necessary (e.g., lowercase/strip)
        return self._is_palindrome_recursive(s, 0, len(s) - 1)

    def _is_palindrome_recursive(self, s, left, right):
        # ! Base Case: Entire string validated
        if left >= right:
            return True
            
        # ! Character Comparison: Immediate exit on mismatch (Short-circuit)
        if s[left] != s[right]:
            return False
            
        # ! Tail Call: Move pointers inward
        return self._is_palindrome_recursive(s, left + 1, right - 1)

    # ~ Approach 2: Middle-Out Recursion (Expanding from Center)
    # Analysis: Time O(N) / Space O(N)
    # >> C++ Perspective: Useful for finding palindromes within a larger buffer.
    # . Logic: Start at the center and expand outwards.
    def is_palindrome_middle_out(self, s, left, right):
        # Base case: we've reached the boundaries of the string
        if left < 0 or right >= len(s):
            return True
        if s[left] != s[right]:
            return False
        return self.is_palindrome_middle_out(s, left - 1, right + 1)
    

    # ~ Approach 3: Iterative (Production Standard)
    # Analysis: Time O(N) / Space O(1)
    # >> C++ Perspective: Compiles to the most efficient machine code.
    # ! Fix: No stack frames, zero risk of overflow.
    def is_palindrome_iterative(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

if __name__ == "__main__":
    sol = Solution()
    test = "racecar"
    print(f"Linear:    {sol.is_palindrome_linear(test, 0, len(test)-1)}")
    # Middle-out check (Start at center)
    mid = len(test) // 2
    # If even length, left=mid-1, right=mid. If odd, left=mid, right=mid.
    L, R = (mid, mid) if len(test) % 2 != 0 else (mid - 1, mid)
    print(f"Middle-Out: {sol.is_palindrome_middle_out(test, L, R)}")
    print(f"Iterative: {sol.is_palindrome_iterative(test)}")