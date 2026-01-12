class Solution:

    # ~ Approach 1: Naive Recursion (Your Code 1)
    # Analysis: Time O(2^N) | Space O(N) (Depth of tree)
    # Problem: Calculates fib(3) thousands of times for large N.
    def fibNaive(self, n: int) -> int:
        if n <= 1: return n
        return self.fibNaive(n - 1) + self.fibNaive(n - 2)


    # ~ Approach 2: Memoization / Top-Down DP (Your Code 2)
    # Analysis: Time O(N) | Space O(N) + O(N) (Map + Stack)
    # Fix: Use an instance variable for cache, not a class variable
    # to avoid bugs across multiple test cases.
    def fibMemo(self, n: int) -> int:
        self.memo = {}
        return self._memoHelper(n)

    def _memoHelper(self, n: int) -> int:
        if n <= 1: return n
        if n in self.memo: return self.memo[n]
        
        result = self._memoHelper(n - 1) + self._memoHelper(n - 2)
        self.memo[n] = result
        return result


    # ~ Approach 3: Tail Recursion (Your Code 3)
    # Analysis: Time O(N) | Space O(N) (Python doesn't optimize tail calls)
    # Logic: It mimics a loop. 'a' is current, 'b' is next.
    def fibTail(self, n: int) -> int:
        return self._tailHelper(n, 0, 1)

    def _tailHelper(self, n, a, b):
        if n == 0: return a
        # Shift state: (a becomes b), (b becomes a+b)
        return self._tailHelper(n - 1, b, a + b)


    # ~ Approach 4: Iterative Loop (Industry Standard)
    # Analysis: Time O(N) | Space O(1)
    # Why? No recursion stack overhead.
    def fibIterative(self, n: int) -> int:
        if n <= 1: return n
        
        a, b = 0, 1
        for _ in range(2, n + 1):
            # Simultaneous update (Python magic)
            a, b = b, a + b
            
        return b

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(f"Tail: {sol.fibTail(10)}")      # 55
    print(f"Iter: {sol.fibIterative(10)}") # 55