class PatternCheatSheet:
    # ==========================================
    # 1. NESTED LOOPS (The Grid)
    # ==========================================
    def concept_grid(self, n):
        for i in range(n):
            for j in range(n):
                print("*", end=" ")
            print()

    # ==========================================
    # 2. PYTHONIC STRING MULTIPLICATION
    # ==========================================
    # Concept: Python allows multiplying strings ("*" * 5). 
    # This replaces the inner loop entirely.
    # Use for: Almost any simple shape.
    def concept_pythonic(self, n):
        for i in range(n):
            # Growing Triangle
            print("*" * (i + 1))
            
            # Shrinking Triangle
            # print("*" * (n - i))

    # ==========================================
    # 3. THE PYRAMID FORMULA
    # ==========================================
    def concept_pyramid(self, n):
        for i in range(n):
            # Math: Spaces + Stars
            spaces = " " * (n - i - 1)
            stars = "*" * (2 * i + 1)
            print(spaces + stars)

    # ==========================================
    # 4. MIRRORING (Single Loop Logic)
    # ==========================================
    def concept_symmetry(self, n):
        # Range: 0 to 2*n - 2 (Total 2*n-1 rows)
        for i in range(2 * n - 1):
            
            # FOLD LOGIC
            # If we cross the halfway point 'n', reverse the index
            row = i
            if i >= n:
                row = (2 * n - 2) - i
            
            # Logic uses 'row' (0 -> n-1 -> 0)
            print("*" * (row + 1))

    # ==========================================
    # 5. COORDINATE MATH (List Comprehension)
    # ==========================================
    # Concept: Generate the whole grid in one massive stateless logic block.
    # Use for: Pattern 22 (Spiral)
    def concept_coordinates(self, n):
        size = 2 * n - 1
        # For every cell (i, j), calculate value immediately
        for i in range(size):
            for j in range(size):
                # Min distance to any of the 4 edges
                min_dist = min(i, j, size - 1 - i, size - 1 - j)
                print(n - min_dist, end=" ")
            print()