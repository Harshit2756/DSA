# Basic Hashing - Summary Notes

## What is Hashing?

- **Hashing** is a computer science technique for fast data storage and retrieval.
- It converts data (like numbers or strings) into a fixed-size value (hash) pointing to storage locations in a structure called a hash table.
- Main goal: **Fast data retrieval**, even with large data volumes.
- Applications: Searching databases, password management, quick data lookups in software, etc.

## Real-Life Example

- Used in food delivery apps: Storing/retrieving user details for fast autofill by hashing order details.
- Data is stored and located using hash values tied to user profiles, speeding up repeat operations.

## Hashing in Arrays: Counting Occurrences

### Method 1: Basic Traversal

- Traverse the entire array, count specific values (e.g., how many times 6 appears).
- Simple but not efficient for large arrays.

### Method 2: Hashing (Efficient Counting)

- Use a hash table (array or map) to count all values in one pass.
- Index represents element, and value at that index is the count (frequency).
- Much faster for large data.

## Character Hashing

- Focused on handling individual characters efficiently (e.g., counting character frequencies).
- Uses ASCII values to map characters, especially efficient for lowercase letters:
  - ASCII of 'a' = 97, 'z' = 122
- Hash table can use `hash[char - 'a']` for 0–25 indices for lowercase letters.

### Time and Space Complexity

- Time: O(N) (populate hash table) + O(q) (answering queries)
- Space: O(1) since only a fixed size (like 26 for lowercase) is needed

## Implementations in Programming Languages

- **C++**: Uses `unordered_map` (avg O(1), worst O(N)) or `map` (O(log N))
- **Java**: Uses `HashMap` (avg O(1)), `TreeMap` (O(log N))

## Hashing Techniques

### Division Method

- Hash function: `h(k) = k % p` (p = prime number)
- Ensures more uniform distribution
- Example: given keys [56, 75, 42, 88, 91] and p=7, compute h for each
- **Drawback**: Collisions are possible

### Folding Method

- Divide key into equal parts and sum them to create hash value
- Handle leftover part by padding or wrapping

### Mid-Square Method

- Square the key and use some middle digits as the hash value

## Handling Collisions: Chaining

- Store colliding keys in a list (linked list) at the same index
- Example: Keys [56, 75, 42, 88, 91] with p=7 — multiple values at index 0 are stored in a chain

## Problems and Challenges

- **Collisions:** Unavoidable, even with good hash functions; chaining manages them but adds complexity
- **Load Factor:** Ratio of stored elements to positions—high value increases collisions, low wastes memory
- **Hash Function Quality:** Poor functions cause clustering and reduce efficiency
- **Memory Overhead:** Chaining and extra structures increase space usage

## Conclusion

- Hashing = fast data operations
- Number hashing often uses division; chaining tackles collisions
- Character hashing for text uses ASCII/letter mapping
- Internal methods: division, folding, mid-square
- Efficient data storage and retrieval is powered by hashing

## Practice Problems

- Highest Occurring Element in Array
- Second Highest Occurring Element
- Sum of Highest and Lowest Frequency
