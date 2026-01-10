"""
Problem: N-Numbers Sum via Tail, Head, and Tree Recursion.
Engineering Constraints: 
- Demonstrate different stack behaviors and frame lifecycle.
- Note: Tree recursion is purely for structural demonstration here.
"""

class Solution:
    # ~ Approach 1: Tail Recursion
    # Analysis: Time O(N) / Space O(N)
    # >> C++ Perspective: Compilers like Clang would optimize this to O(1) space (TCO).
    # . Memory Efficiency: The 'accumulator' carries the state forward.
    def sum_tail(self, N, accumulator=0):
        if N == 0:
            return accumulator
        # ! The addition happens BEFORE the call; nothing left to do after.
        return self.sum_tail(N - 1, accumulator + N)

    # ~ Approach 2: Head Recursion
    # Analysis: Time O(N) / Space O(N)
    # >> C++ Perspective: Requires full stack unwinding; cannot be optimized to a loop.
    # . Memory Efficiency: Each frame stays active until the base case is hit.
    def sum_head(self, N):
        if N == 0:
            return 0
        # ! The call happens FIRST; addition happens during unwinding.
        res = self.sum_head(N - 1)
        return N + res

if __name__ == "__main__":
    sol = Solution()
    N = 5
    print(f"Tail Recursive: {sol.sum_tail(N)}")
    print(f"Head Recursive: {sol.sum_head(N)}")