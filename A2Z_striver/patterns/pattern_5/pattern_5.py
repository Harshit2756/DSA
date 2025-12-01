import sys

class PatternSolver:
    """
    Problem: Print an inverted right triangle of stars.
    Example Input: n = 5
    Example Output:
    *****
    ****
    ***
    **
    *
    
    Constraints: 1 <= n <= 100 (Typical for pattern printing)
    Goal: O(N^2) Time.
    """

    # // ~ Approach 1: Pythonic (String Multiplication)
    # // Analysis: Time O(N^2) | Space O(1)
    def print_inverted_pythonic(self, n):
        # // . Uses Python's '*' operator to avoid inner loops
        for i in range(n):
            # // - (n - i) decreases as i increases
            print("*" * (n - i))

    # // ~ Approach 2: Nested Loops (Language Agnostic/Standard)
    # // Analysis: Time O(N^2) | Space O(1)
    def print_inverted_nested(self, n):
        # // ! This demonstrates raw logic control, preferred in strict Algo interviews
        for i in range(n):
            # // - We need to print (n - i) stars
            for j in range(n - i):
                # // - end="" prevents new line after every star
                print("*", end="") 
            # // - Print new line after the row is complete
            print() 

    # // ~ Approach 3: Recursive (Functional)
    # // Analysis: Time O(N^2) | Space O(N) due to stack depth
    def print_inverted_recursive(self, n):
        # // - Base case: Stop when n is 0
        if n == 0:
            return
        
        # // . Print current row
        print("*" * n)
        
        # // - Recursive call for the next row (n-1)
        self.print_inverted_recursive(n - 1)

#Driver Code
if __name__ == "__main__":
    solver = PatternSolver()
    N = 5
    
    print(f"--- Approach 1: Pythonic (N={N}) ---")
    solver.print_inverted_pythonic(N)
    
    print(f"\n--- Approach 2: Nested Loops (N={N}) ---")
    solver.print_inverted_nested(N)
    
    print(f"\n--- Approach 3: Recursive (N={N}) ---")
    solver.print_inverted_recursive(N)