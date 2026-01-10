"""
Problem: Factorial Calculation (n!)
Examples: 5! = 120, 0! = 1
Engineering Constraints: 
- Python recursion limit (~1000).
- Memory overhead of PyFrameObjects.
"""

class Solution:
    # ~ Approach 1: Head Recursion (Your Approach)
    # Analysis: Time O(n) / Space O(n)
    # >> C++ Perspective: Pushes a frame for every 'n' onto the system stack.
    # ! : Added n <= 1 check for safety.
    def factorial_head(self, n: int) -> int:
        if n <= 1:
            return 1
        return n * self.factorial_head(n - 1)

    # ~ Approach 2: Tail Recursion (Optimized Structure)
    # Analysis: Time O(n) / Space O(n) in Python (O(1) in C++ with TCO)
    # >> C++ Perspective: Compilers optimize this to a 'jump' instruction, reusing the same stack frame.
    # . : The 'accumulator' carries the result, so no work is left after the call.
    def factorial_tail(self, n: int, accumulator: int = 1) -> int:
        if n <= 1:
            return accumulator
        return self.factorial_tail(n - 1, n * accumulator)

    # ~ Approach 3: Iterative (Production Grade)
    # Analysis: Time O(n) / Space O(1)
    # >> C++ Perspective: The most efficient use of registers; no stack growth.
    # . Memory efficiency: Uses a single integer object for the result.
    def factorial_iterative(self, n: int) -> int:
        res = 1
        for i in range(2, n + 1):
            res *= i
        return res

if __name__ == "__main__":
    sol = Solution()
    val = 5
    print(f"Head Recursive (User's): {sol.factorial_head(val)}")
    print(f"Tail Recursive:         {sol.factorial_tail(val)}")
    print(f"Iterative (Best):       {sol.factorial_iterative(val)}")