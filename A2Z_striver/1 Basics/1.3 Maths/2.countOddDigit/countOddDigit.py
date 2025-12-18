"""
Problem: Count the number of odd digits in an integer n.
Example: Input: n = 12345 | Output: 3 (1, 3, 5)
Constraints: Handle all integers (positive, negative, zero).
Goal: O(log N) Time, O(1) Space.
"""

class DigitProcessor:
    # ~ Approach 1: Iterative Digit Extraction
    # Analysis: Time O(log10 N), Space O(1)
    def count_odd_digits(self, n: int) -> int:
        # ! Fix: Ensure n is positive to handle negative inputs correctly
        # - The odd/even nature of a digit is independent of the number's sign.
        n = abs(n)
        
        count = 0
        
        # . Optimization: Using a while loop is the standard for digit peeling
        while n > 0:
            digit = n % 10
            
            # - Check if digit is odd (not divisible by 2)
            if digit % 2 != 0:
                count += 1
                
            # . Remove the last digit
            n //= 10
            
        return count

    # ~ Approach 2: Functional / Pythonic (One-Liner)
    # Analysis: Time O(log10 N), Space O(log10 N) due to string/list creation
    def count_odd_digits_functional(self, n: int) -> int:
        # . Good for showing language fluency, but Approach 1 is better for memory
        return sum(1 for d in str(abs(n)) if int(d) % 2 != 0)

# --- Driver Code ---
if __name__ == "__main__":
    solver = DigitProcessor()
    test_cases = [1357, 2468, -123, 0]
    
    print(f"{'Input':<10} | {'Result (Iterative)':<20} | {'Result (Functional)':<20}")
    print("-" * 60)
    for t in test_cases:
        res1 = solver.count_odd_digits(t)
        res2 = solver.count_odd_digits_functional(t)
        print(f"{t:<10} | {res1:<20} | {res2:<20}")