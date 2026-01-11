"""
Problem: Reverse String (In-Place)
Approach: Two-Pointer Tail Recursion
Engineering Constraints: 
- Input 's' must be a mutable sequence (List of chars).
- In-place modification to ensure O(1) auxiliary heap space.
"""

class Solution:
    # ~ Approach 1: Tail Recursion (Your Current Solution)
    # Analysis: Time O(N) / Space O(N) stack
    # >> C++ Perspective: If 's' is std::vector<char>, this is highly efficient.
    # . Memory Efficiency: In-place swaps avoid creating new string objects.
    def reverseString(self, s: list[str]) -> list[str]:
        self._reverse_recursive(s, 0, len(s) - 1)
        return s

    def _reverse_recursive(self, s, left, right):
        # ! Base Case: Pointers meet or cross in the middle
        if left >= right:
            return
        
        # ! The Swap: Classic Pythonic unpacking
        # >> C++ Perspective: std::swap(s[left], s[right])
        s[left], s[right] = s[right], s[left]
        
        # ! Tail Call: No operations follow this call
        self._reverse_recursive(s, left + 1, right - 1)

    # ~ Approach 2: Iterative (The "True" Engineering Solution)
    # Analysis: Time O(N) / Space O(1)
    # >> C++ Perspective: Eliminates the stack frame overhead entirely.
    def reverse_iterative(self, s: list[str]) -> None:
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

if __name__ == "__main__":
    solution = Solution()
    input_list = ["h", "e", "l", "l", "o"]
    
    print(f"Original: {input_list}")
    solution.reverseString(input_list)
    print(f"Reversed: {input_list}")