class Solution:

    # ~ Approach 1: Your Solution (Head Recursion)
    # Analysis: Time O(log N) | Space O(log N) (Recursion Stack)
    # Type: "Head Recursion" (Logic happens after the recursive call returns)
    def addDigitsHead(self, num: int) -> int:
        if num == 0:
            return 0
            
        # Step 1: Sum the digits recursively
        # This breaks down 38 -> 3 + 8 = 11
        current_sum = num % 10 + self.addDigitsHead(num // 10)
        
        # Step 2: The "Check" (Unique to your logic)
        # If the sum is still > 9 (like 11), you recurse AGAIN on the sum.
        if current_sum > 9:
            return self.addDigitsHead(current_sum)
            
        return current_sum
    
    # ~ Approach 2: Tail Recursion (The "accumulator" style)
    # Analysis: Time O(log N) | Space O(log N) (Python doesn't optimize tail calls, but C++ does)
    # Why Tail? The recursive call is the absolute final instruction.
    # We pass the 'current_sum' forward into the next frame.
    def addDigitsTail(self, num: int) -> int:
        # Start the helper with sum = 0
        return self._tailHelper(num, 0)

    def _tailHelper(self, num, current_sum):
        # Base Case 1: Number is fully summed
        if num == 0:
            # Check if the sum is single digit
            if current_sum < 10:
                return current_sum
            else:
                # Restart process with the new sum
                return self._tailHelper(current_sum, 0)
        
        # Recursive Step: Pass updated sum FORWARD
        return self._tailHelper(num // 10, current_sum + (num % 10))


    # ~ Approach 3: Hybrid (Tail Driver + Head Helper)
    # Analysis: Time O(log N) | Space O(log N)
    # Pros: Best Readability. Separates "Summing" from "Reducing".    
    # ---------------------------------------------------------
    # PART 1: The "Driver" (Tail Recursive)
    # ---------------------------------------------------------
    def addDigits(self, num):
        # Base case: Already single digit? Done.
        if num < 10:
            return num

        # Step 1: Calculate the sum (Delegated to helper)
        sum_digits = self.sumDigits(num)

        # Step 2: Tail Recursive Call
        # We pass the result directly to the next frame.
        # No math happens here after this line returns.
        return self.addDigits(sum_digits)
    
    # ---------------------------------------------------------
    # PART 2: The "Calculator" (Head Recursive)
    # ---------------------------------------------------------
    def sumDigits(self, num):
        # Base case: 0
        if num == 0:
            return 0

        # Head Recursive Step
        # The function must "wait" for the child (num // 10) to return
        # BEFORE it can add (num % 10) to it.
        return self.sumDigits(num // 10) + (num % 10)

    # ~ Approach 4: One-Liner Recursion (Mathematical Trick)
    # Logic: Recursively subtract 9 until single digit. 
    # Works because modulo 9 logic is cyclical.
    def addDigitsOneLine(self, num: int) -> int:
        if num < 10: return num
        # 38 -> 3+8=11 -> 1+1=2. 
        # Mathematically similar to just calling recursively on sum of digits
        sum_digits = num % 10 + num // 10 # Only works for 2 digit numbers strictly
        # General version:
        return self.addDigitsOneLine( sum(int(d) for d in str(num)) )

    # ~ Approach 5: Iterative Simulation (Standard Loop)
    # Analysis: Time O(log N) | Space O(1)
    # Why: Safer than recursion (no stack overflow risk).
    def addDigitsIterative(self, num: int) -> int:
        while num > 9:
            sum_val = 0
            while num > 0:
                sum_val += num % 10
                num //= 10
            num = sum_val
        return num

    # ~ Approach 6: Mathematical / Digital Root (The O(1) "Magic")
    # Analysis: Time O(1) | Space O(1)
    # Logic: This is based on "Congruence Formula".
    # Any number % 9 is equivalent to the sum of its digits % 9.
    # Ex: 38 % 9 = 2. (3+8=11 -> 1+1=2).
    def addDigitsMath(self, num: int) -> int:
        if num == 0: return 0
        if num % 9 == 0: return 9
        return num % 9

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    print(f"Head (Yours): {sol.addDigitsHead(38)}")   # 2
    print(f"Tail:         {sol.addDigitsTail(38)}")   # 2
    print(f"Iterative: {sol.addDigitsIterative(38)}") # Output: 2
    print(f"Math O(1): {sol.addDigitsMath(38)}")      # Output: 2