# Recursion
- Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem.
- It is commonly used for problems that can be broken down into smaller, similar subproblems.
- A recursive function typically has two main components:
  1. Base Case: The condition under which the function stops calling itself to prevent infinite recursion.
  2. Recursive Case: The part of the function where it calls itself with a modified argument to work towards the base case.

### Example of a Recursive Function
Here is a simple example of a recursive function to calculate the factorial of a number:
#### Python
```python
def countdown(n):
    # 1. Base Case
    if n == 0:
        print("Blastoff!")
        return
    
    # 2. Recursive Step
    print(n)
    countdown(n - 1) 
```

#### C++
```cpp
void countdown(int n) {
    // 1. Base Case
    if (n == 0) {
        std::cout << "Blastoff!" << std::endl;
        return;
    }
    // 2. Recursive Step
    std::cout << n << std::endl;
    countdown(n - 1);
}
```
#### In this example, the function `factorial` calls itself with the argument `n - 1` until it reaches the base case of `n` being 0 or 1.
# Lesson 2: Under the Hood - The Call Stack (Visualized)
**Focus:** Memory Management & Execution Flow | **Example:** `factorial(3)`


## The Concept
When a function calls itself, the computer does not "restart" the function. It pauses the current version and creates a **brand new instance** of that function in memory.

This area of memory is called the **Call Stack**. It works like a stack of plates:
1.  **Push:** When a function is called, a new "plate" (Stack Frame) is added to the top.
2.  **Pop:** When a function returns, the top plate is removed, and we resume the one below it.

### 🖼️ Mermaid Diagram 1: The Execution Flow
This Sequence Diagram shows exactly how the computer "pauses" execution.
* **Solid lines (`->`)** represent the "Winding" phase (Calling).
* **Dotted lines (`-->`)** represent the "Unwinding" phase (Returning).
* *Notice how `factorial(3)` stays alive (active bar) the entire time!*

```mermaid
---
config:
  theme: redux-dark
---
sequenceDiagram
    participant Main
    participant F3 as Factorial(3)
    participant F2 as Factorial(2)
    participant F1 as Factorial(1)

    Note over Main: User calls factorial(3)
    Main->>F3: call(3)
    activate F3
    
    Note right of F3: Needs 3 * F(2)<br/>PAUSE & CALL
    F3->>F2: call(2)
    activate F2
    
    Note right of F2: Needs 2 * F(1)<br/>PAUSE & CALL
    F2->>F1: call(1)
    activate F1
    
    Note right of F1: Base Case (n==1)<br/>RETURN 1
    F1-->>F2: return 1
    deactivate F1
    
    Note right of F2: Resume!<br/>Calc: 2 * 1 = 2
    F2-->>F3: return 2
    deactivate F2
    
    Note right of F3: Resume!<br/>Calc: 3 * 2 = 6
    F3-->>Main: return 6
    deactivate F3
```

### 🖼️ Mermaid Diagram 2: The Memory Snapshot
This diagram represents the computer's RAM at the **deepest moment** of recursion (just before the base case returns).

* This is why recursion uses **O(N) Memory**.
* If this stack gets too high (e.g., `factorial(10000)`), you run out of RAM = **Stack Overflow**.

```mermaid
---
config:
  theme: default
---
graph BT
    subgraph "Computer Memory (RAM)"
        direction BT
        
        F1[Frame 3: factorial 1 <br/> n=1 <br/> Waiting for: Nothing ]
        
        F2[Frame 2: factorial 2 <br/> n=2 <br/> Waiting for: factorial 1]
        
        F3[Frame 1: factorial 3 <br/> n=3 <br/> Waiting for: factorial 2]
        
        Main[Frame 0: Main Program <br/> Waiting for: factorial 3]
        
        F1 --> F2
        F2 --> F3
        F3 --> Main
    end
    
    style F1 fill:#ffcccc,stroke:#333,stroke-width:2px
    style F2 fill:#ffeebb,stroke:#333
    style F3 fill:#ffeebb,stroke:#333
    style Main fill:#eebbff,stroke:#333
```

## Lesson 3: Recursion vs Iteration

| Feature | Recursion | Iteration (Loops) |
| :--- | :--- | :--- |
| **Readability** | High (often fewer lines) | Moderate (can get messy) |
| **State** | Implicit (managed by Stack) | Explicit (managed by counters) |
| **Memory Usage** | High (O(N) stack space) | Low (O(1) usually) |
| **Performance** | Slower (function overhead) | Faster (CPU optimized) |

 **Rule of Thumb: Use recursion for `trees, graphs, and hierarchical data`. Use iteration for simple `lists or counters`.**


## Lesson 4: Types of Recursion & Optimization Strategies

## Part I: The Types of Recursion (The Shapes)

Recursion comes in three primary "shapes," defined by **where** and **how often** the recursive call happens.

### 1. Naive/Tree Recursion (The "Explosion")
**Definition:** A function is "Tree Recursive" if it makes **more than one** recursive call inside a single step.

**Example:** The naive Fibonacci sequence (`fib(n) = fib(n-1) + fib(n-2)`).
* **The Shape:** It does not form a straight line. It splits into branches.
* **The Cost:** It grows exponentially ($O(2^n)$). Every step doubles the work.

#### The Code (Naive Approach)
```python
def fib(n):
    if n <= 1: return n
    return fib(n - 1) + fib(n - 2)
```

#### 🖼️ Mermaid Diagram: The Explosion
*Notice how `fib(2)` and `fib(3)` appear multiple times. We are doing the same work over and over!*

```mermaid
---
config:
  theme: default
---
flowchart TB
 subgraph subGraph0["The Exponential Tree"]
        F4["fib 4"]
        F5["fib 5"]
        F3_A["fib 3"]
        F3_B["fib 3"]
        F2_A["fib 2"]
        F2_B["fib 2"]
        F1_A["fib 1"]
        F2_C["fib 2"]
        F1_B["fib 1"]
  end
    F5 --> F4 & F3_A
    F4 --> F3_B & F2_A
    F3_A --> F2_B & F1_A
    F3_B --> F2_C & F1_B
    note["The Red nodes show redundant work.<br>We calculate fib(3) twice and fib(2) three times!"]
    
    style F3_A fill:#ffcccc
    style F3_B fill:#ffcccc
    style F2_A fill:#ffcccc
    style F2_B fill:#ffcccc
    style F2_C fill:#ffcccc
```

---

### 2. Head Recursion (The Boomerang / Stack Build-up)
* **Definition:** The recursive call is made **before** the actual work is done.
* **Flow:** Dive down -> Hit Base Case -> Calculate on the way up.
* **Memory:** High. Stack frames must stay open to perform the multiplication later.


**Head Recursion (Call First):**
```python
def factorial_head(n):
    # Base Case
    if n == 0: 
        return 1
    
    # Recursive Step (Head)
    # We cannot return yet! We must wait for the result of factorial_head(n-1)
    # and THEN multiply it by n.
    result = factorial_head(n - 1)
    return n * result
```

#### 🖼️ Mermaid Diagram: The "Boomerang" Flow
*Notice how nothing is printed during the "Call" phase. All the printing happens during the "Return" phase.*

```mermaid

---
config:
  theme: redux-dark
---
sequenceDiagram
    participant Main
    participant F3 as Fact(3)
    participant F2 as Fact(2)
    participant F1 as Fact(1)

    Note over Main: Goal: 3!

    %% THE WINDING (GOING DOWN)
    Main->>F3: Call(3)
    activate F3
    Note right of F3: Can't finish yet.<br/>Need Fact(2).
    
    F3->>F2: Call(2)
    activate F2
    Note right of F2: Can't finish yet.<br/>Need Fact(1).
    
    F2->>F1: Call(1)
    activate F1
    Note right of F1: Base Case!<br/>Return 1.
    
    %% THE UNWINDING (DOING WORK)
    F1-->>F2: Return 1
    deactivate F1
    
    Note right of F2: Now I can work!<br/>2 * 1 = 2
    F2-->>F3: Return 2
    deactivate F2
    
    Note right of F3: Now I can work!<br/>3 * 2 = 6
    F3-->>Main: Return 6
    deactivate F3

```

#### 🖼️ Mermaid Diagram: The "Boomerang" Graph

```mermaid
---
config:
  theme: default
---
flowchart TB
 subgraph subGraphHead["Head Recursion: The Boomerang"]
        H3["Fact(3) <br> 'I need to wait...'"]
        H2["Fact(2) <br> 'I need to wait...'"]
        H1["Fact(1) <br> Base Case: Return 1"]
        Result["Final Result: 6"]
  end
    
    %% The Winding Phase (Calls)
    H3 -- "1. Call & Pause" --> H2
    H2 -- "2. Call & Pause" --> H1
    
    %% The Unwinding Phase (Work)
    H1 -. "3. Return 1" .-> H2
    H2 -. "4. Calc 2*1 -> Return 2" .-> H3
    H3 -. "5. Calc 3*2 -> Return 6" .-> Result
    
    %% Styling
    style H3 fill:#ffcccc,stroke:#333
    style H2 fill:#ffcccc,stroke:#333
    style H1 fill:#ccffcc,stroke:#333
    style Result fill:#ccffcc,stroke:#333,stroke-width:4px
```

### 3. Tail Recursion (The Tunnel / Accumulator)
* **Definition:** The recursive call is the **absolute last action** of the function.
* **Flow:** Calculate -> Pass Result -> Dive down.
* **Memory:** Low (Potential $O(1)$). The parent has no work left, so the compiler can close the stack frame.

#### The Code (Accumulator Style)
We pass the state (`a`, `b`) *down* the chain. The function never needs to "wait" for a return value to do more math.

```python
def factorial_tail(n, accumulator=1):
    # Base Case: Return the specific answer we built
    if n == 0: 
        return accumulator
    
    # Tail Recursive Step
    # We do the math (accumulator * n) NOW.
    # Then we pass the result down. No waiting!
    return factorial_tail(n - 1, accumulator * n)
```

#### 🖼️ Mermaid Diagram: The "Tunnel" Flow

*Notice how each call does its work immediately and passes the result down. There is no waiting!*

```mermaid

---
config:
  theme: redux-dark
---

sequenceDiagram
    participant Main
    participant Func as Tail_Fact

    Note over Main: Goal: 3!
    
    %% STEP 1
    Main->>Func: Call(n=3, acc=1)
    activate Func
    Note right of Func: Math: 1 * 3 = 3<br/>Pass it down!
    
    %% STEP 2
    Func->>Func: Call(n=2, acc=3)
    Note right of Func: Math: 3 * 2 = 6<br/>Pass it down!
    
    %% STEP 3
    Func->>Func: Call(n=1, acc=6)
    Note right of Func: Math: 6 * 1 = 6<br/>Pass it down!
    
    %% BASE CASE
    Func->>Func: Call(n=0, acc=6)
    Note right of Func: Base Case Reached.<br/>Return Acc (6).
    
    %% THE RETURN (Instant)
    Func-->>Main: Result: 6
    deactivate Func

```

#### mermaid Diagram: The "Tunnel" Graph

```mermaid
---
config:
  theme: default
  layout: elk
---
flowchart TB
 subgraph subGraphTail["Tail Recursion: The Tunnel"]
        T3["Fact(3, acc=1) <br> Current State: 1"]
        T2["Fact(2, acc=3) <br> Current State: 3"]
        T1["Fact(1, acc=6) <br> Current State: 6"]
        Base["Base Case (n=0) <br> Return Acc"]
        Result["Final Result: 6"]
  end

    %% The Work happens ON THE WAY DOWN
    T3 -- "1. Calc 1*3 -> Pass 3" --> T2
    T2 -- "2. Calc 3*2 -> Pass 6" --> T1
    T1 -- "3. Calc 6*1 -> Pass 6" --> Base
    
    %% The Direct Return (Tunnel)
    Base -- "4. Return Final Value" --> Result

    %% Styling (All Green because no memory is held 'waiting')
    style T3 fill:#ccffcc,stroke:#333
    style T2 fill:#ccffcc,stroke:#333
    style T1 fill:#ccffcc,stroke:#333
    style Base fill:#ccffcc,stroke:#333
    style Result fill:#ccffcc,stroke:#333,stroke-width:4px
```

  
 
## Part II: Optimization Strategies (The Fixes)

We apply specific optimizations to specific problems.

### Optimization I: Memoization (Fixing Tree Recursion)

- **The Problem:** Tree Recursion recalculates the same sub-problems (e.g., `fib(3)`) multiple times.
- **The Fix:** **Cache** the result the first time we see it.
- **Result:** Transforms the Tree into a **Directed Acyclic Graph (DAG)**. Complexity drops from $O(2^n)$ to $O(N)$.

#### The Code (Memoized)
```python
memo = {}

def fib_memo(n):
    if n <= 1: return n
    
    # 1. Check Cache
    if n in memo:
        return memo[n]
    
    # 2. Calculate and Cache
    result = fib_memo(n - 1) + fib_memo(n - 2)
    memo[n] = result
    return result
```

#### 🖼️ Sequence Diagram: The Cache Hit
*Watch the "Right Branch" skip the work because the "Left Branch" already did it.*

```mermaid

---
config:
  theme: redux-dark
---

sequenceDiagram
    participant Main
    participant F4 as Fib(4)
    participant F3 as Fib(3)
    participant F2 as Fib(2)
    participant Cache as Cache {}

    Note over Main: Goal: Fib(4)
    Main->>F4: Call(4)
    activate F4
    
    %% --- LEFT BRANCH: DOING THE WORK ---
    Note right of F4: Needs Fib(3) (Not in cache)
    F4->>F3: Call(3)
    activate F3
    
    Note right of F3: Needs Fib(2) (Not in cache)
    F3->>F2: Call(2)
    activate F2
    
    Note right of F2: Base cases... Result=1
    F2->>Cache: STORE {2: 1}
    F2-->>F3: Return 1
    deactivate F2

    Note right of F3: Calc: 1 + 1 (F1) = 2
    F3->>Cache: STORE {3: 2}
    F3-->>F4: Return 2
    deactivate F3

    %% --- RIGHT BRANCH: THE OPTIMIZATION ---
    Note right of F4: Needs Fib(2) again...
    
    F4->>Cache: Check key "2"?
    Cache-->>F4: HIT! Value is 1
    Note right of F4: ⚡ Skipped F2 Call!
    
    %% --- FINAL ---
    Note right of F4: Calc: 2 (from F3) + 1 (from Cache) = 3
    F4->>Cache: STORE {4: 3}
    F4-->>Main: Return 3
    deactivate F4
```

#### 🖼️ Graph Diagram: The Lean DAG
*The dashed lines show where we reuse existing answers.*

```mermaid
---
config:
  theme: default
---
graph TD
    subgraph "Memoized Graph (Linear Time)"
    M5[fib 5] --> M4[fib 4]
    M5 -.-> M3[fib 3 <br/> From Cache]
    
    M4 --> M3_Real[fib 3]
    M4 -.-> M2[fib 2 <br/> From Cache]
    
    M3_Real --> M2_Real[fib 2]
    M3_Real -.-> M1[fib 1]
    
    M2_Real --> M1_Real[fib 1]
    M2_Real --> M0[fib 0]
    end
    
    style M3 fill:#ccffcc,stroke:#333,stroke-dasharray: 5 5
    style M2 fill:#ccffcc,stroke:#333,stroke-dasharray: 5 5
```

---

### Optimization II: Tail Call Optimization (Fixing Space)

- **The Problem:** Standard recursion (Head or Tree) keeps Stack Frames open waiting for children to return. `fib(10000)` causes **Stack Overflow**.
- **The Fix:** **Tail Recursion**. Since the parent has no work left to do, the compiler can safely "delete" the parent's stack frame before jumping to the child.
- **Result:** Space Complexity drops from $O(N)$ to $O(1)$.

#### The Code (Tail Recursive Fibonacci)
```python
def fib_tail(n, a=0, b=1):
    # Base Case
    if n == 0:
        return a
    # Tail Recursive Step
    return fib_tail(n - 1, b, a + b)
```

#### 🖼️ Sequence Diagram: The Flat Chain
*Notice there is no unwinding. The `Result: 5` is just passed along.*

```mermaid
---
config:
  theme: redux-dark
---
sequenceDiagram
    participant Main
    participant Function as Fib_Tail
    
    Note right of Main: Calculating Fib(5)
    
    Main->>Function: fib(5, 0, 1)
    Note right of Function: Current: 0, Next: 1
    
    Function->>Function: fib(4, 1, 1)
    Note right of Function: Current: 1, Next: 1+0=1
    
    Function->>Function: fib(3, 1, 2)
    Note right of Function: Current: 1, Next: 1+1=2
    
    Function->>Function: fib(2, 2, 3)
    Note right of Function: Current: 2, Next: 2+1=3
    
    Function->>Function: fib(1, 3, 5)
    Note right of Function: Base Case! Return 5
    
    Function-->>Main: Result: 5
```

---

## Summary Matrix

| Strategy | Shape | Time Complexity | Space Complexity | Best For |
| :--- | :--- | :--- | :--- | :--- |
| **Naive / Tree** | Exploding Pyramid | $O(2^n)$ (Horrible) | $O(N)$ | Understanding logic |
| **Memoization** | Pruned Graph (DAG) | $O(N)$ (Fast) | $O(N)$ | Dynamic Programming |
| **Tail Rec** | Flat Tunnel | $O(N)$ (Fast) | $O(1)$* | Production Systems (Loops) |

*\*O(1) space assumes the compiler supports Tail Call Optimization (like C++, Scala, Haskell). Python does not support this naturally.*

For more details about the head and tail use case, refer to [Parameterized Recursion.](https://takeuforward.org/plus/dsa/problems/recursion-concepts-with-parameters?category=beginner-problem&subcategory=basic-recursion)