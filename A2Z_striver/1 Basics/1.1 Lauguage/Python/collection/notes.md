
## Collections Module - Specialized Data Structures

### Import:

`from collections import deque, Counter, defaultdict, OrderedDict, namedtuple`

### DEQUE - Double-Ended Queue:

Fast add/remove from both ends (O(1))

### Methods:

```python
d = deque([1, 2, 3])
d.append(4)                    # Add to right: deque([1, 2, 3, 4])
d.appendleft(0)                # Add to left: deque([0, 1, 2, 3, 4])
d.pop()                        # Remove from right: returns 4
d.popleft()                    # Remove from left: returns 0
d.extend([5, 6])               # Extend from right: deque([1, 2, 3, 5, 6])
d.extendleft([-1, 0])         # Extend from left: deque([0, -1, 1, 2, 3])
d.rotate(2)                    # Rotate 2 steps right: deque([2, 3, 0, -1, 1])
d.rotate(-1)                   # Rotate 1 step left: deque([3, 0, -1, 1, 2])
len(d)                         # Length: 5
d[0]                           # Access by index: 3
```

### When to Use:

-   Queue/Stack implementation
-   Sliding window problems
-   BFS traversal
-   Fast add/remove from both ends

### COUNTER - Frequency Counter:

Counts occurrences automatically

### Methods:

```python
c = Counter([1, 2, 2, 3, 3, 3])
c[2]                           # Get count: 2
c[5]                           # Get count (not found): 0
c.most_common(2)               # Top 2: [(3, 3), (2, 2)]
list(c.elements())             # All elements: [1, 2, 2, 3, 3, 3]
c.update([3, 4])               # Add counts: Counter({3: 4, 2: 2, 1: 1, 4: 1})
c.subtract([2, 2])             # Subtract: Counter({3: 3, 1: 1, 4: 1, 2: 0})
c2 = Counter([3, 4, 4])
c + c2                         # Add: Counter({3: 5, 4: 3, 1: 1})
c - c2                         # Subtract: Counter({3: 3, 1: 1})
c & c2                         # Intersection (min): Counter({3: 1, 4: 1})
c | c2                         # Union (max): Counter({3: 4, 4: 2, 1: 1})
```

### When to Use:

-   Frequency counting
-   Most common elements
-   Anagram problems
-   Frequency-based problems

### DEFAULTDICT - Dictionary with Defaults:

Never raises KeyError, creates default value

### Methods:

```python
dd = defaultdict(int)           # Default: 0
dd['a']                        # Returns 0 (auto-created)
dd['a'] += 1                   # Now dd['a'] = 1

dd_list = defaultdict(list)    # Default: []
dd_list['fruits'].append('apple')  # Auto-creates list
dd_list['fruits']              # ['apple']

dd_set = defaultdict(set)       # Default: set()
dd_set['nums'].add(1)          # Auto-creates set
dd_set['nums']                 # {1}

dd_custom = defaultdict(lambda: "N/A")  # Custom default
dd_custom['missing']           # Returns "N/A"
```

### When to Use:

-   Grouping elements
-   Building graphs
-   Avoiding KeyError checks
-   Counting with auto-initialization

### ORDEREDDICT - Ordered Dictionary:

Maintains insertion order (Python 3.7+ dicts also do this)

### Methods:

```python
od = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
od['d'] = 4                    # Set value: OrderedDict([('a',1), ('b',2), ('c',3), ('d',4)])
od.move_to_end('a')            # Move to end: OrderedDict([('b',2), ('c',3), ('d',4), ('a',1)])
od.move_to_end('c', last=False) # Move to beginning: OrderedDict([('c',3), ('b',2), ('d',4), ('a',1)])
od.popitem()                   # Remove last: returns ('a', 1)
od.popitem(last=False)         # Remove first: returns ('c', 3)
```

### When to Use:

-   LRU Cache implementation
-   Need ordered dictionary
-   Special pop operations

### NAMEDTUPLE - Named Tuples:

Tuples with named fields (immutable, lightweight)

### Methods:

```python
Point = namedtuple('Point', ['x', 'y'])
p = Point(1, 2)                # Create: Point(x=1, y=2)
p.x                            # Access by name: 1
p.y                            # Access by name: 2
p[0]                           # Access by index: 1
p[1]                           # Access by index: 2
# Immutable: p.x = 3  # ERROR! Cannot modify
```

### When to Use:

-   Lightweight data structures
-   Return multiple values
-   Immutable records
-   Dictionary keys

  

---

## Heapq - Priority Queue

### Import:

`import heapq`  
Note: Creates MIN-HEAP (smallest at top)

### Functions:

```python
heap = []
heapq.heappush(heap, 3)         # Push: heap = [3]
heapq.heappush(heap, 1)         # Push: heap = [1, 3]
heapq.heappush(heap, 2)         # Push: heap = [1, 2, 3]
heapq.heappop(heap)             # Pop smallest: returns 1, heap = [2, 3]
arr = [3, 1, 4, 1, 5]
heapq.heapify(arr)              # Convert to heap: arr = [1, 1, 4, 3, 5]
heapq.heappushpop(heap, 0)      # Push 0 then pop: returns 0
heapq.heapreplace(heap, 5)       # Pop then push 5: returns 2
heap[0]                         # Get smallest: 3 (without removing)
heapq.nlargest(3, [1,2,3,4,5])   # 3 largest: [5, 4, 3]
heapq.nsmallest(2, [3,1,4,1,5])  # 2 smallest: [1, 1]
```

### Max-Heap Trick:

```python
max_heap = []
heapq.heappush(max_heap, -10)   # Push negated: [-10]
heapq.heappush(max_heap, -5)    # Push negated: [-10, -5]
max_val = -heapq.heappop(max_heap)  # Pop and negate: returns 10
```

### When to Use:

-   Priority queue
-   K largest/smallest elements
-   Merge K sorted lists
-   Dijkstra's algorithm

  

---

## Bisect - Binary Search

### Import:

`import bisect`  
Note: arr must be sorted!

### Functions:

```python
arr = [1, 3, 3, 3, 5, 7]
bisect.bisect_left(arr, 3)      # Leftmost position: 1
bisect.bisect_left(arr, 4)      # Position to insert 4: 4
bisect.bisect_right(arr, 3)     # Rightmost position: 4
bisect.bisect(arr, 3)           # Same as bisect_right: 4
arr = [1, 3, 5]
bisect.insort_left(arr, 2)      # Insert at leftmost: [1, 2, 3, 5]
bisect.insort_right(arr, 3)     # Insert at rightmost: [1, 2, 3, 3, 5]
bisect.insort(arr, 4)           # Same as insort_right: [1, 2, 3, 3, 4, 5]
```

### When to Use:

-   Binary search
-   Maintain sorted list
-   Find insertion position
-   Range queries

  
