import math

class MathCheatSheet:

    # ---------------------------------------------------------
    # 1. DIGIT MANIPULATION
    # ---------------------------------------------------------
    def digit_basics(self, n: int):
        n = abs(n)
        if n == 0: return 1
        
        # Count Digits O(1)
        count = int(math.log10(n)) + 1
        
        # Iterate Digits (Reverse Order)
        temp = n
        while temp > 0:
            digit = temp % 10
            # Do work with digit...
            temp //= 10
            
    # ---------------------------------------------------------
    # 2. PRIMES & DIVISORS (The Sqrt Pattern)
    # ---------------------------------------------------------
    def is_prime(self, n: int) -> bool:
        """
        Check Prime in O(sqrt(N))
        Rule: 0, 1 are NOT prime. 2 is the only even prime.
        """
        if n <= 1: return False
        if n <= 3: return True
        if n % 2 == 0 or n % 3 == 0: return False # 6k optimization
        
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True

    def get_divisors(self, n: int) -> list[int]:
        """
        Get all factors in O(sqrt(N))
        Rule: Divisors come in pairs.
        """
        divs = []
        for i in range(1, int(math.isqrt(n)) + 1):
            if n % i == 0:
                divs.append(i)
                if i != n // i: # Avoid duplicate for perfect squares (e.g., 6x6=36)
                    divs.append(n // i)
        return sorted(divs)

    # ---------------------------------------------------------
    # 3. GCD & LCM (Euclidean Algorithm)
    # ---------------------------------------------------------
    def gcd(self, a, b):
        """
        Greatest Common Divisor in O(log(min(a,b)))
        """
        while b:
            a, b = b, a % b
        return a

    def lcm(self, a, b):
        """
        Least Common Multiple
        Formula: (a * b) / GCD(a, b)
        """
        if a == 0 or b == 0: return 0
        return abs(a * b) // self.gcd(a, b)

    # ---------------------------------------------------------
    # 4. MODULO ARITHMETIC (Crucial for "Return answer modulo 10^9 + 7")
    # ---------------------------------------------------------
    def modulo_rules(self):
        MOD = 10**9 + 7
        a, b = 10**10, 10**10 # Large numbers
        
        # Addition: (a + b) % m = ((a % m) + (b % m)) % m
        sum_val = (a % MOD + b % MOD) % MOD
        
        # Multiplication: (a * b) % m = ((a % m) * (b % m)) % m
        prod_val = (a % MOD * b % MOD) % MOD
        
        # Python handles negative mod correctly, but in C++/Java:
        # (a - b) % m => ((a - b) % m + m) % m
        
    # ---------------------------------------------------------
    # 5. PALINDROME NUMBER (Without String Conversion)
    # ---------------------------------------------------------
    def is_palindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0): 
            return False # Negatives & numbers ending in 0 (except 0) aren't palindromes
        
        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10
            
        # Check for even length (x == rev) or odd length (x == rev//10)
        return x == reversed_half or x == reversed_half // 10