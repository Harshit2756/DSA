import os

# We split the backticks to prevent syntax errors in the python string
mermaid_start = "```mermaid"
mermaid_end = "```"

markdown_content = f"""# 🚀 C++ STL Ultimate Cheat Sheet

## 🌳 STL Decision Tree: Which Container to Use?

{mermaid_start}
flowchart TD
    %% --- NODES ---
    Start([Start: Choose Container])
    
    %% Decisions (Conditions)
    KeyValue{{Store Key-Value Pairs?}}
    SortKey{{Sorted by Key?}}
    UniqueKey{{Unique Keys?}}
    UniqueElem{{Unique Elements Only?}}
    SortElem{{Sorted?}}
    Order{{Specific Order Needed?}}
    Access{{Access Pattern?}}

    %% Data Structures (Grouped by Type)
    Map[std::map]
    MultiMap[std::multimap]
    UnorderedMap[std::unordered_map]
    
    Set[std::set]
    UnSet[std::unordered_set]
    
    Stack[std::stack]
    Queue[std::queue]
    PQ[std::priority_queue]
    
    Vector[std::vector]
    Deque[std::deque]
    List[std::list]

    %% --- LOGIC FLOW ---
    Start --> KeyValue
    
    %% MAP BRANCH
    KeyValue -- Yes --> SortKey
    SortKey -- Yes --> UniqueKey
    UniqueKey -- "Yes" --> Map
    UniqueKey -- "No (Duplicates)" --> MultiMap
    SortKey -- "No (Hash Table)" --> UnorderedMap

    %% SET BRANCH
    KeyValue -- No --> UniqueElem
    UniqueElem -- Yes --> SortElem
    SortElem -- Yes --> Set
    SortElem -- "No (Hash Table)" --> UnSet
    
    %% ADAPTERS & SEQUENCE BRANCH
    UniqueElem -- No --> Order
    Order -- "LIFO\n(Recursion / Undo)" --> Stack
    Order -- "FIFO\n(BFS / Scheduling)" --> Queue
    Order -- "Highest Priority\n(Dijkstra / Top-K)" --> PQ
    
    Order -- "Flexible / None" --> Access
    Access -- "Random Access v[i]\n(Default Choice)" --> Vector
    Access -- "Front & Back Ops\n(Sliding Window)" --> Deque
    Access -- "Mid Insertions\n(No Random Access)" --> List

    %% --- STYLING ---
    %% 1. Start Node (Green)
    classDef startNode fill:#2ecc71,stroke:#27ae60,stroke-width:2px,color:white;
    class Start startNode;

    %% 2. Decisions (Yellow)
    classDef decision fill:#f1c40f,stroke:#f39c12,stroke-width:2px,color:black;
    class KeyValue,SortKey,UniqueKey,UniqueElem,SortElem,Order,Access decision;

    %% 3. Maps (Purple)
    classDef mapGroup fill:#9b59b6,stroke:#8e44ad,stroke-width:2px,color:white;
    class Map,MultiMap,UnorderedMap mapGroup;

    %% 4. Sets (Orange)
    classDef setGroup fill:#e67e22,stroke:#d35400,stroke-width:2px,color:white;
    class Set,UnSet setGroup;

    %% 5. Adapters (Blue)
    classDef adapterGroup fill:#3498db,stroke:#2980b9,stroke-width:2px,color:white;
    class Stack,Queue,PQ adapterGroup;

    %% 6. Sequences (Teal)
    classDef seqGroup fill:#1abc9c,stroke:#16a085,stroke-width:2px,color:white;
    class Vector,Deque,List seqGroup;
{mermaid_end}

---

## ⚡ Quick Reference: When & Why

| Container | Internal Structure | When to Use | Why? (Pros/Cons) |
| :--- | :--- | :--- | :--- |
| **Vector** | Dynamic Array | Default for any list of items. | ✅ O(1) Random Access. <br> ❌ O(N) Insert/Delete at front. |
| **List** | Doubly Linked List | Frequent inserts/deletes in middle/front. | ✅ O(1) Insert anywhere (if iter known). <br> ❌ No Random Access ($l[i]$). |
| **Deque** | Chunked Arrays | Sliding Window problems. | ✅ O(1) Push/Pop Front & Back. <br> ✅ Supports $d[i]$. |
| **Stack** | Adapter (LIFO) | Recursion, Parsing, DFS. | ✅ Restricted access ensures correctness. |
| **Queue** | Adapter (FIFO) | BFS, Scheduling, Buffers. | ✅ Process data in order of arrival. |
| **Priority Queue** | Heap (Binary Tree) | Dijkstra, Top-K elements. | ✅ O(1) Access to Max/Min. <br> ❌ No iteration. |
| **Set** | Red-Black Tree | Removing duplicates, Ordered data. | ✅ Always sorted. O(log N) lookup. |
| **Unordered Set** | Hash Table | Checking existence (Visited set). | ✅ O(1) Avg lookup. <br> ❌ Random order. |
| **Map** | Red-Black Tree | Frequency counting, Dictionaries. | ✅ Key-Value association. Sorted Keys. |
| **Unordered Map** | Hash Table | Fast caching/hashing. | ✅ O(1) Avg lookup. |

---

## ⏱️ Time Complexity Cheat Sheet

| Operation | Vector | List | Set/Map | Unordered Set/Map | Priority Queue |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Push Back** | $O(1)$ | $O(1)$ | $O(\log N)$ | $O(1)$ avg | $O(\log N)$ |
| **Push Front** | $O(N)$ | $O(1)$ | N/A | N/A | N/A |
| **Find/Search**| $O(N)$ | $O(N)$ | $O(\log N)$ | $O(1)$ avg | N/A |
| **Access [i]** | $O(1)$ | $O(N)$ | N/A | N/A | N/A |
| **Erase** | $O(N)$ | $O(1)$* | $O(\log N)$ | $O(1)$ avg | $O(\log N)$ |

*\* $O(1)$ for List only if iterator is already at position.*
"""

file_name = "STL_CheatSheet.md"

try:
    with open(file_name, "w", encoding="utf-8") as f:
        f.write(markdown_content)
    print(f"✅ Successfully created '{{file_name}}'!")
    print("   Open this file in VS Code (with Markdown Preview Mermaid Support) to see the colored chart.")
except Exception as e:
    print(f"❌ Error: {{e}}")