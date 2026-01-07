from collections import Counter, defaultdict

class Solution:
    """
    Problem: Return array of unique characters sorted by:
             1. Frequency (High -> Low)
             2. Alphabetical (a -> z)
    Constraint: O(N) Time.
    """

    # ~ Approach 1: The "Pythonic" Standard (Recommended)
    # Analysis: Time O(N + U log U) -> O(N) | Space O(U) -> O(1)
    def frequencySortPythonic(self, s: str) -> list[str]:
        # 1. Count frequencies: O(N)
        # count = Counter(s)
        
        # # 2. Sort keys based on custom tuple:
        # #    -x[1] : Frequency Descending (negate to use default Ascending sort)
        # #    x[0]  : Character Ascending (Tie-breaker)
        # #    items() returns [(char, count), ...]
        # sorted_items = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        
        # # 3. Extract just the characters
        # return [char for char, freq in sorted_items]

        # =========================OR =========================
        return [item[0] for item in sorted(Counter(s).items(), key=lambda x: (-x[1], x[0]))]

    # ~ Approach 2: Bucket Sort / Grouping (Robust)
    # Analysis: Time O(N) | Space O(N)
    # This approach is useful if sorting is banned or U is very large.
    def frequencySortBucket(self, s: str) -> list[str]:
        # 1. Count frequencies
        counts = Counter(s)
        
        # 2. Create buckets where index = frequency
        #    Max frequency cannot exceed len(s)
        max_freq = len(s)
        buckets = defaultdict(list)
        
        for char, freq in counts.items():
            buckets[freq].append(char)
            
        # 3. Iterate buckets from Max Frequency down to 1
        result = []
        for freq in range(max_freq, 0, -1):
            if freq in buckets:
                # Sort characters alphabetically within the same frequency tier
                chars_in_tier = sorted(buckets[freq]) 
                result.extend(chars_in_tier)
                
        return result

# --- Driver Code ---
if __name__ == "__main__":
    sol = Solution()
    
    # Test Case 1: Standard
    input_1 = "tree"
    print(f"Input: {input_1}")
    print(f"Pythonic: {sol.frequencySortPythonic(input_1)}")
    
    # Test Case 2: Tie-breaking check
    # 'b' appears 2 times, 'a' appears 2 times. 
    # Logic should put 'a' before 'b' because of alphabetical tie-break.
    input_2 = "bbaacc" 
    print(f"\nInput: {input_2}")
    print(f"Bucket:   {sol.frequencySortBucket(input_2)}")