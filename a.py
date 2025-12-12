import os

# C++ Code Content
cpp_content = r"""/* 🚀 MASTER STL STUDY DRIVER
   --------------------------
   How to use:
   1. Go to the specific class (e.g., STLVectors).
   2. Write your implementation code inside the explain() function.
   3. In main(), uncomment the function call you want to test.
*/

#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

// ==========================================
// 1. PAIRS (Utility)
// ==========================================
class STLPairs {
public:
    void explain() {
        cout << "--- PAIRS DEMO ---" << endl;
        // PASTE/WRITE CODE HERE
        pair<int, int> p = {1, 3};
        cout << p.first << " " << p.second << endl;
        
        pair<int, pair<int, int>> p2 = {1, {3, 4}};
        cout << p2.first << " " << p2.second.second << endl;
        
        pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
        cout << arr[1].second << endl;
        cout << "------------------" << endl;
    }
};

// ==========================================
// 2. VECTORS (Dynamic Arrays)
// ==========================================
class STLVectors {
public:
    void explain() {
        cout << "--- VECTORS DEMO ---" << endl;
        // PASTE/WRITE CODE HERE
        vector<int> v;
        v.push_back(1);
        v.emplace_back(2);
        
        // Iterators
        for(auto it : v) {
            cout << it << " ";
        }
        cout << endl << "--------------------" << endl;
    }
};

// ==========================================
// 3. LISTS (Doubly Linked List)
// ==========================================
class STLLists {
public:
    void explain() {
        cout << "--- LISTS DEMO ---" << endl;
        list<int> ls;
        ls.push_back(20);
        ls.push_front(10); // Cheap operation in List, costly in Vector
        
        for(auto it : ls) cout << it << " ";
        cout << endl << "------------------" << endl;
    }
};

// ==========================================
// 4. DEQUE (Double Ended Queue)
// ==========================================
class STLDeque {
public:
    void explain() {
        cout << "--- DEQUE DEMO ---" << endl;
        deque<int> dq;
        // Code here
    }
};

// ==========================================
// 5. STACK (LIFO)
// ==========================================
class STLStack {
public:
    void explain() {
        cout << "--- STACK DEMO ---" << endl;
        stack<int> st;
        // st.push(1);
        // st.top();
        // st.pop();
    }
};

// ==========================================
// 6. QUEUE (FIFO)
// ==========================================
class STLQueue {
public:
    void explain() {
        cout << "--- QUEUE DEMO ---" << endl;
        queue<int> q;
        // q.push(1);
        // q.front();
        // q.pop();
    }
};

// ==========================================
// 7. PRIORITY QUEUE (Heap)
// ==========================================
class STLPriorityQueue {
public:
    void explain() {
        cout << "--- PQ DEMO ---" << endl;
        priority_queue<int> pq; // Max Heap
        // priority_queue<int, vector<int>, greater<int>> min_pq; // Min Heap
    }
};

// ==========================================
// 8. SETS (Unique & Sorted)
// ==========================================
class STLSets {
public:
    void explain() {
        cout << "--- SET DEMO ---" << endl;
        set<int> st;
        // st.insert(1);
    }
};

// ==========================================
// 9. MAPS (Key-Value Pairs)
// ==========================================
class STLMaps {
public:
    void explain() {
        cout << "--- MAP DEMO ---" << endl;
        map<int, int> mp;
        // mp[1] = 2;
    }
};

// ==========================================
// 10. ALGORITHMS (Sort, Search, etc.)
// ==========================================
class STLAlgorithms {
public:
    void explain() {
        cout << "--- ALGOS DEMO ---" << endl;
        // sort(v.begin(), v.end());
        // __builtin_popcount();
        // next_permutation();
    }
};

// ==========================================
// MAIN DRIVER
// ==========================================
int main() {
    // UNCOMMENT the class you are currently studying to run it
    
    STLPairs p;
    p.explain();

    // STLVectors v;
    // v.explain();

    // STLLists l;
    // l.explain();

    // STLDeque d;
    // d.explain();
    
    // STLStack s;
    // s.explain();
    
    // STLQueue q;
    // q.explain();
    
    // STLPriorityQueue pq;
    // pq.explain();
    
    // STLSets setObj;
    // setObj.explain();
    
    // STLMaps mapObj;
    // mapObj.explain();

    // STLAlgorithms algos;
    // algos.explain();

    return 0;
}
"""

# File Creation Logic
file_name = "STL_Driver_Template.cpp"

try:
    with open(file_name, "w", encoding="utf-8") as f:
        f.write(cpp_content)
    print(f"✅ Successfully created '{file_name}'!")
    print("   Open this file in your IDE (VS Code/CLion).")
    print("   As you watch the videos, fill in the 'explain()' method for that topic.")
except Exception as e:
    print(f"❌ Error creating file: {e}")