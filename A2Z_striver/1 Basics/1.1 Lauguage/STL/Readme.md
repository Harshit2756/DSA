# 🛠️ C++ STL: Phase 1 (Pairs, Vectors, & Iterators)

The **Standard Template Library (STL)** is your toolkit for competitive programming. Instead of writing dynamic arrays or sort functions from scratch, you use these highly optimized tools.

---

## 🧩 STL Key Components

The Standard Template Library (STL) consists of 4 main pillars that work together to manage data efficiently.

---

## 1. Containers
**Role:** Storage & Data Structures.
* **Purpose:** Store collections of objects efficiently.
* **Types:**
    * **Sequential:** `vector`, `list`, `deque`.
    * **Associative:** `set`, `map`, `multiset`.
    * **Unordered:** `unordered_set`, `unordered_map`.
* **Header:** `#include <vector>`, `#include <map>`, etc.

## 2. Algorithms
**Role:** Data Manipulation.
* **Purpose:** Functions to process data independent of the container type.
* **Operations:** Sorting, Searching, Modifying.
* **Examples:** `sort()`, `binary_search()`, `reverse()`, `min_element()`.
* **Header:** `#include <algorithm>`

## 3. Functions
**Role:** Custom Logic utilities.
* **Purpose:** Objects treated as functions to define specific operations during execution.
* **Examples:**
    * `for_each`: Apply logic to every element.
    * `transform`: Modify elements based on a rule.
    * Custom Comparators: Defining how to sort a custom Struct/Object.
* **Header:** `#include <functional>`

## 4. Iterators
**Role:** The Bridge (Container $\leftrightarrow$ Algorithm).
* **Purpose:** Traverse through container elements without exposing internal implementation.
* **Mechanism:** Acts like a smart pointer.
* **Key Operations:**
    * `begin()`: Points to first element.
    * `end()`: Points to *theoretical* element after the last.
    * `*it`: Dereference to get value.
    * `it++`: Move to next element.

---

### 🧠 The Big Picture Relationship
`Algorithm` uses `Iterator` to manipulate data inside `Container`.

---

## 2. The Utility: `std::pair`
Stores exactly two values. Useful for coordinates `(x, y)` or returning two results from a function.

### C++ Syntax
```cpp
#include <utility>

void explainPair() {
    // 1. Simple Declaration
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second; // Output: 1 3

    // 2. Nested Pair (Storing 3 items)
    // Concept: Store {1, {3, 4}}
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.second.second; // Output: 4

    // 3. Array of Pairs (Common in Graphs)
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second; // Output: 5
}
```

### Python Equivalent
```python
# Tuples are the closest equivalent
p1 = (1, 3)
p2 = (1, (3, 4))
arr = [(1, 2), (2, 5)]
```

---

## 3. The Dynamic Array: `std::vector`
Unlike `int arr[100]` which is fixed, a `vector` grows automatically when you add elements.

### Core Functions
| Function | Description | Time Complexity |
| :--- | :--- | :--- |
| `push_back(x)` | Add `x` to end | O(1) |
| `pop_back()` | Remove last element | O(1) |
| `size()` | Current count of elements | O(1) |
| `clear()` | Erase all elements | O(N) |

### C++ Syntax
```cpp
#include <vector>

void explainVector() {
    // 1. Empty Vector
    vector<int> v; 

    // 2. Adding Elements
    v.push_back(1);      // {1}
    v.emplace_back(2);   // {1, 2} (Faster than push_back)

    // 3. Pre-filled Vector
    // vector<type> name(size, value);
    vector<int> v2(5, 100); // {100, 100, 100, 100, 100}
    
    // 4. Copying
    vector<int> v3(v2); // v3 is a copy of v2
}
```

---

## 4. Iterators (How to Loop)
Iterators are like pointers that point to the **memory address** of an element.

### Key Iterators
* **`v.begin()`**: Points to the **first** element.
* **`v.end()`**: Points to the position **after the last** element (Not the last element itself!).
* **`v.rbegin()`**: Points to the last element (Reverse Begin).
* **`v.rend()`**: Points to before the first element (Reverse End).

### Looping Syntax
```cpp
void explainIterators() {
    vector<int> v = {10, 20, 30};

    // 1. The Manual Way (Rarely used now)
    vector<int>::iterator it = v.begin();
    cout << *(it); // Prints 10 (Dereference pointer)

    // 2. The Standard Loop
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    
    // 3. The "Auto" Keyword (Interview Standard)
    // 'auto' automatically detects the type
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    // 4. For-Each Loop (Cleanest)
    for (auto element : v) {
        cout << element << " ";
    }
}
```

---

## 5. Deletion (Erase)
You can delete a single element or a range of elements.

```cpp
void explainErase() {
    vector<int> v = {10, 20, 12, 23, 35};

    // 1. Single Erase
    // v.begin() points to 10. +1 points to 20.
    v.erase(v.begin() + 1); // Removes 20

    // 2. Range Erase [start, end)
    // Deletes from start (inclusive) to end (exclusive)
    v.erase(v.begin() + 2, v.begin() + 4); 
}
```
