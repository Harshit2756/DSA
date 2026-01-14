# Python Libraries Part 1 - Theory - TUF+

## Python Libraries for DSA & Interviews

### (Your Toolkit for Problem Solving)

Welcome to Python Libraries!  
Python provides powerful built-in libraries for data structures and algorithms.  
Comparable to C++ STL or Java Collections - essential tools for DSA!

### Reasons to Learn

-   Save time (pre-written, optimized code)
-   Interview essential (expected knowledge)
-   Makes DSA problems easier
-   Industry standard
  

---

## Built-in Functions - Common Operations

### Sorting:

`sorted(iterable, key=None, reverse=False)`

-   Returns new sorted list
-   key: function to determine sort order
-   reverse: True for descending

### Examples:


```python
arr = [3, 1, 4, 1, 5]
sorted(arr)                    # [1, 1, 3, 4, 5]
sorted(arr, reverse=True)      # [5, 4, 3, 1, 1]

arr = [-3, 1, -4, 2, -1]
sorted(arr, key=lambda x: abs(x))   # [1, -1, 2, -3, -4]

# Sort list in-place
arr.sort()                     # Modifies original list

# Sort by custom key
words = ["apple", "pie", "banana"]
sorted(words, key=len)         # ['pie', 'apple', 'banana']
```

### Min/Max:

`min(iterable, key=None)`: Minimum value  
`max(iterable, key=None)`: Maximum value

### Examples:

```python
min([3, 1, 4, 1, 5])           # 1
max([3, 1, 4, 1, 5])           # 5
```

### Sum/Product:

`sum(iterable, start=0)`: Sum of elements  
For product, use: `functools.reduce` or `math.prod`

### Examples:

```python
sum([1, 2, 3, 4])              # 10
sum([1, 2, 3], 10)             # 16 (starts from 10)

import math
math.prod([2, 3, 4])          # Product: 24 (Python 3.8+)
```

### Length/Count:

`len(iterable)`: Length/count  
`count = iterable.count(value)`: Count occurrences

### Examples:

```python
len([1, 2, 3])                 # 3
"hello".count('l')             # 2
```

### Any/All:

`any(iterable)`: True if any element is True  
`all(iterable)`: True if all elements are True

### Examples:

```python
any([False, True, False])       # True
all([True, True, True])        # True
any([])                        # False (empty is False)
```

### Enumerate:

`enumerate(iterable, start=0)`: Returns (index, value) pairs

### Examples:

```python
for i, val in enumerate([10, 20, 30]):
    print(i, val)              # 0 10, 1 20, 2 30
list(enumerate(['a', 'b', 'c']))  # [(0, 'a'), (1, 'b'), (2, 'c')]
list(enumerate(['a', 'b'], 1))     # [(1, 'a'), (2, 'b')] (start=1)
```

### Zip:

`zip(*iterables)`: Combine multiple iterables

### Examples:

```python
list(zip([1, 2], [3, 4]))      # [(1, 3), (2, 4)]
list(zip([1, 2, 3], [4, 5]))   # [(1, 4), (2, 5)] (stops at shortest)
list(zip([1, 2], [3, 4], [5, 6]))  # [(1, 3, 5), (2, 4, 6)]
```

### Reversed:

`reversed(iterable)`: Reverse iterator

### Examples:

```python
list(reversed([1, 2, 3]))     # [3, 2, 1]
"hello"[::-1]                  # "olleh" (string slicing)
```

### Range:

`range(stop)`: 0 to stop-1  
`range(start, stop)`: start to stop-1  
`range(start, stop, step)`: with step

### Examples:

```python
list(range(5))                 # [0, 1, 2, 3, 4]
list(range(1, 5))              # [1, 2, 3, 4]
list(range(0, 10, 2))          # [0, 2, 4, 6, 8]
```

---

## Itertools - Iteration Tools

### Import:

`import itertools`

### Functions:

```python
list(itertools.combinations([1,2,3], 2))      # [(1,2), (1,3), (2,3)]
list(itertools.combinations_with_replacement([1,2], 2))  # [(1,1), (1,2), (2,2)]
list(itertools.permutations([1,2], 2))        # [(1,2), (2,1)]
list(itertools.product([1,2], [3,4]))         # [(1,3), (1,4), (2,3), (2,4)]
list(itertools.cycle([1,2,3]))[:7]            # [1,2,3,1,2,3,1] (first 7)
list(itertools.repeat(5, 3))                  # [5, 5, 5]
list(itertools.chain([1,2], [3,4], [5]))      # [1, 2, 3, 4, 5]
list(itertools.accumulate([1,2,3,4]))        # [1, 3, 6, 10] (cumulative sum)
list(itertools.accumulate([1,2,3,4], lambda x,y: x*y))  # [1, 2, 6, 24]
groups = itertools.groupby([1,1,2,2,2,3])
[(k, list(g)) for k, g in groups]            # [(1, [1,1]), (2, [2,2,2]), (3, [3])]
```

### When to Use:

-   Generate combinations/permutations
-   Cartesian products
-   Grouping elements
-   Complex iteration patterns

  

---

## Functools - Function Tools

### Import:

`import functools`

### Functions:

```python
# LRU Cache
@functools.lru_cache(maxsize=128)
def fibonacci(n):
    if n < 2: return n
    return fibonacci(n-1) + fibonacci(n-2)
fibonacci(10)                                  # First call: computes
fibonacci(10)                                  # Second call: uses cache (instant!)

# Reduce
from functools import reduce
reduce(lambda x, y: x + y, [1, 2, 3, 4])      # Sum: 10
reduce(lambda x, y: x * y, [1, 2, 3, 4])      # Product: 24
reduce(lambda x, y: x + y, [1, 2, 3], 10)     # With initial: 16

# Partial
def multiply(x, y): return x * y
double = functools.partial(multiply, 2)
double(5)                                      # 10 (2 * 5)
triple = functools.partial(multiply, 3)
triple(4)                                      # 12 (3 * 4)

# Wraps (preserves function metadata)
def my_decorator(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper
```

### When to Use:

-   Memoization (caching)
-   Function composition
-   Reducing sequences
-   Function manipulation

  

---

## Math Module - Mathematical Operations

### Import:

`import math`

### Constants:

`math.pi` (3.14...)  
`math.e` (2.71...)

### Functions:

```python
math.sqrt(16)                  # Square root: 4.0
math.pow(2, 3)                 # 2^3: 8.0
math.factorial(5)              # 5!: 120
math.gcd(48, 18)               # GCD: 6
math.lcm(12, 8)                # LCM: 24 (Python 3.9+)
math.log(math.e)               # Natural log: 1.0
math.log10(100)                # Base 10 log: 2.0
math.log2(8)                   # Base 2 log: 3.0
math.sin(math.pi/2)            # sin(90°): 1.0
math.cos(0)                    # cos(0°): 1.0
math.degrees(math.pi)          # Radians to degrees: 180.0
math.radians(180)              # Degrees to radians: 3.14159...
math.ceil(4.3)                # Ceiling: 5
math.floor(4.7)                # Floor: 4
math.isfinite(10)              # Check if finite: True
math.isinf(float('inf'))       # Check if infinite: True
```

### When to Use:

-   Mathematical calculations
-   GCD/LCM
-   Prime checking
-   Distance calculations

  

---

## Random Module - Randomness

### Import:

`import random`

### Functions:

```python
random.random()                # Float in [0.0, 1.0): 0.123456...
random.randint(1, 10)           # Integer in [1, 10]: 7 (example)
random.randrange(0, 10, 2)     # Even numbers 0-8: 4 (example)
random.choice([1, 2, 3, 4])    # Random element: 3 (example)
random.sample([1,2,3,4,5], 3)  # 3 random elements: [2, 5, 1] (example)
arr = [1, 2, 3, 4, 5]
random.shuffle(arr)            # Shuffle in-place: arr = [3, 1, 5, 2, 4] (example)
random.uniform(1.0, 10.0)      # Float in [1.0, 10.0]: 5.678... (example)
```

### When to Use:

-   Generate test cases
-   Shuffle arrays
-   Random sampling
-   Testing algorithms

  

---

## String Module - String Constants

### Import:

`import string`

### Constants:

```python
string.ascii_lowercase         # 'abcdefghijklmnopqrstuvwxyz'
string.ascii_uppercase         # 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
string.ascii_letters           # Lowercase + uppercase
string.digits                  # '0123456789'
string.hexdigits               # '0123456789abcdefABCDEF'
string.punctuation             # All punctuation
string.whitespace              # Space, tab, newline, etc.
```

### When to Use:

-   Character validation
-   String filtering
-   Character set operations

  

---

## List Methods - Common Operations

### Methods:

```python
lst = [1, 2, 3]
lst.append(4)                  # Add to end: [1, 2, 3, 4]
lst.extend([5, 6])             # Extend: [1, 2, 3, 4, 5, 6]
lst.insert(0, 0)              # Insert at index 0: [0, 1, 2, 3, 4, 5, 6]
lst.remove(3)                  # Remove first 3: [0, 1, 2, 4, 5, 6]
lst.pop()                      # Remove last: returns 6, lst = [0, 1, 2, 4, 5]
lst.pop(0)                     # Remove at index 0: returns 0, lst = [1, 2, 4, 5]
lst.index(2)                   # Index of 2: 1
lst.count(2)                   # Count of 2: 1
lst.sort()                     # Sort: [1, 2, 4, 5]
lst.sort(reverse=True)         # Sort descending: [5, 4, 2, 1]
lst.reverse()                  # Reverse: [1, 2, 4, 5]
lst.clear()                    # Clear: []
lst = [1, 2, 3]
lst2 = lst.copy()              # Shallow copy: [1, 2, 3]
```

  

---

## Dict Methods - Dictionary Operations

### Methods:

```python
d = {'a': 1, 'b': 2}
d['a']                         # Get value: 1
d['c']                         # KeyError (missing key)
d.get('a')                     # Get value: 1
d.get('c', 0)                  # Get with default: 0
d['c'] = 3                     # Set value: {'a': 1, 'b': 2, 'c': 3}
d.update({'d': 4})             # Update: {'a': 1, 'b': 2, 'c': 3, 'd': 4}
d.pop('c')                     # Remove and return: 3
d.pop('x', -1)                 # Remove with default: -1 (key not found)
d.popitem()                    # Remove last: ('d', 4)
list(d.keys())                 # View of keys: ['a', 'b']
list(d.values())               # View of values: [1, 2]
list(d.items())                # View of pairs: [('a', 1), ('b', 2)]
d.clear()                      # Clear: {}
d = {'a': 1, 'b': 2}
'a' in d                       # Check if key exists: True
d2 = d.copy()                  # Shallow copy: {'a': 1, 'b': 2}
```

  

---

## Set Methods - Set Operations

### Methods:

```python
s = {1, 2, 3}
s.add(4)                        # Add element: {1, 2, 3, 4}
s.remove(2)                    # Remove: {1, 3, 4}
s.remove(5)                     # KeyError (not found)
s.discard(3)                    # Remove: {1, 4}
s.discard(5)                    # No error (not found): {1, 4}
s.pop()                         # Remove arbitrary: returns 1, s = {4}
s.clear()                       # Clear: set()
s = {1, 2, 3}
s2 = s.copy()                   # Shallow copy: {1, 2, 3}
```

### Operations:

```python
s1 = {1, 2, 3}
s2 = {3, 4, 5}
s1 | s2                         # Union: {1, 2, 3, 4, 5}
s1 & s2                         # Intersection: {3}
s1 - s2                         # Difference: {1, 2}
s1 ^ s2                         # Symmetric difference: {1, 2, 4, 5}
{1, 2} <= s1                    # Subset: True
s1 >= {1, 2}                    # Superset: True
```

  

---

## String Methods - String Operations

### Methods:

```python
s = "Hello World"
s.upper()                       # Uppercase: "HELLO WORLD"
s.lower()                       # Lowercase: "hello world"
s.capitalize()                  # First letter capital: "Hello world"
s.title()                       # Title case: "Hello World"
"  hello  ".strip()             # Remove whitespace: "hello"
s.split()                       # Split by space: ['Hello', 'World']
s.split('l')                    # Split by 'l': ['He', '', 'o Wor', 'd']
"-".join(['a', 'b', 'c'])       # Join: "a-b-c"
s.replace('World', 'Python')    # Replace: "Hello Python"
s.find('World')                 # Find index: 6
s.find('xyz')                  # Not found: -1
s.index('World')                # Find index: 6
s.index('xyz')                 # ValueError (not found)
s.startswith('Hello')          # Check prefix: True
s.endswith('World')            # Check suffix: True
s.count('l')                   # Count occurrences: 3
"abc".isalpha()                 # All alphabetic: True
"123".isdigit()                 # All digits: True
"abc123".isalnum()              # Alphanumeric: True
```

### Slicing:

```python
s = "Hello"
s[1:4]                          # Slice: "ell"
s[:3]                           # From start: "Hel"
s[2:]                           # To end: "llo"
s[::-1]                         # Reverse: "olleH"
s[::2]                          # Every 2nd char: "Hlo"
```

  

---

## Common Algorithms - Quick Reference

### Sorting:

```python
# List sorting
arr.sort()                      # In-place
sorted_arr = sorted(arr)        # New list

# Custom sorting
arr.sort(key=lambda x: x[1])    # Sort by second element
arr.sort(key=len)               # Sort by length

# Multiple criteria
arr.sort(key=lambda x: (x[1], x[0]))  # Sort by second, then first
```

### Searching:

```python
# Linear search
target in arr                   # O(n) - check existence
arr.index(target)               # O(n) - get index

# Binary search (sorted array)
import bisect
pos = bisect.bisect_left(arr, target)  # O(log n)
```

### Finding Min/Max:

```python
min(arr)                        # Minimum
max(arr)                        # Maximum
min(arr, key=len)               # Minimum by key
max(arr, key=len)               # Maximum by key
```

### Counting:

```python
# Using Counter
from collections import Counter
counter = Counter(arr)
counter.most_common(k)         # K most common

# Manual counting
freq = {}
for item in arr:
    freq[item] = freq.get(item, 0) + 1
```

### Grouping:

```python
# Using defaultdict
from collections import defaultdict
groups = defaultdict(list)
for item in arr:
    groups[key].append(item)
```

### Filtering:

```python
filtered = [x for x in arr if condition]  # List comprehension
filtered = filter(lambda x: condition, arr)  # Filter function
```

### Mapping:

```python
mapped = [func(x) for x in arr]  # List comprehension
mapped = map(func, arr)          # Map function
```

### Reducing:

```python
from functools import reduce
result = reduce(lambda x, y: x + y, arr)  # Sum
result = reduce(lambda x, y: x * y, arr)  # Product
```

  

---

## When to Use Which - Quick Guide

-   **Use DEQUE for:** Queue/Stack operations, Sliding window, BFS traversal, fast add/remove from both ends.
-   **Use COUNTER for:** Frequency counting, most common elements, anagram problems.
-   **Use DEFAULTDICT for:** Grouping elements, building graphs, avoiding KeyError.
-   **Use HEAPQ for:** Priority queue, K largest/smallest, merge K sorted lists.
-   **Use BISECT for:** Binary search, maintaining sorted list, range queries.
-   **Use ITERTOOLS for:** Combinations/permutations, Cartesian products, grouping consecutive.
-   **Use FUNCTOOLS for:** Memoization needed, function composition, reducing sequences.

  

---

## Common Interview Patterns

### Pattern 1: Two Sum

```python
seen = {}
for i, num in enumerate(nums):
    if target - num in seen:
        return [seen[target - num], i]
    seen[num] = i
```

### Pattern 2: Group Anagrams

```python
from collections import defaultdict
groups = defaultdict(list)
for s in strs:
    groups[''.join(sorted(s))].append(s)
return list(groups.values())
```

### Pattern 3: Top K Frequent

```python
from collections import Counter
counter = Counter(nums)
return [num for num, _ in counter.most_common(k)]
```

### Pattern 4: LRU Cache


```python
from collections import OrderedDict
cache = OrderedDict()
cache.move_to_end(key)          # Mark as recently used
cache.popitem(last=False)       # Remove least recent
```

### Pattern 5: Sliding Window

```python
from collections import deque
dq = deque()
dq.popleft()                    # Remove out of window
dq.pop()                        # Remove smaller elements
dq.append(i)                    # Add current
```

  

---

## Key Takeaways

### Essential Libraries:

-   **Collections:** deque, Counter, defaultdict, OrderedDict, namedtuple
-   **Heapq:** priority queue
-   **Bisect:** binary search
-   **Itertools:** combinations, permutations
-   **Functools:** lru\_cache, reduce
-   **Math:** GCD, LCM, sqrt, etc.
-   **Built-in functions:** sorted, min, max, sum, etc.

### Remember:

-   Know when to use which library
-   Understand time complexities
-   Practice common patterns
-   Read documentation when needed
