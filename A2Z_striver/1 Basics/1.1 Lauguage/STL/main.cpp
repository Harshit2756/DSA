#include <bits/stdc++.h>
#include "1 Pairs.h"
using namespace std;



// ==========================================
// 2. VECTORS (Dynamic Arrays)
// ==========================================
class STLVectors
{
public:
    void explain()
    {
        cout << "--- VECTORS DEMO ---" << endl;
        // PASTE/WRITE CODE HERE
        vector<int> v;
        v.push_back(1);
        v.emplace_back(2);

        // Iterators
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl
             << "--------------------" << endl;
    }
};

// ==========================================
// 3. LISTS (Doubly Linked List)
// ==========================================
class STLLists
{
public:
    void explain()
    {
        cout << "--- LISTS DEMO ---" << endl;
        list<int> ls;
        ls.push_back(20);
        ls.push_front(10); // Cheap operation in List, costly in Vector

        for (auto it : ls)
            cout << it << " ";
        cout << endl
             << "------------------" << endl;
    }
};

// ==========================================
// 4. DEQUE (Double Ended Queue)
// ==========================================
class STLDeque
{
public:
    void explain()
    {
        cout << "--- DEQUE DEMO ---" << endl;
        deque<int> dq;
        // Code here
    }
};

// ==========================================
// 5. STACK (LIFO)
// ==========================================
class STLStack
{
public:
    void explain()
    {
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
class STLQueue
{
public:
    void explain()
    {
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
class STLPriorityQueue
{
public:
    void explain()
    {
        cout << "--- PQ DEMO ---" << endl;
        priority_queue<int> pq; // Max Heap
        // priority_queue<int, vector<int>, greater<int>> min_pq; // Min Heap
    }
};

// ==========================================
// 8. SETS (Unique & Sorted)
// ==========================================
class STLSets
{
public:
    void explain()
    {
        cout << "--- SET DEMO ---" << endl;
        set<int> st;
        // st.insert(1);
    }
};

// ==========================================
// 9. MAPS (Key-Value Pairs)
// ==========================================
class STLMaps
{
public:
    void explain()
    {
        cout << "--- MAP DEMO ---" << endl;
        map<int, int> mp;
        // mp[1] = 2;
    }
};

// ==========================================
// 10. ALGORITHMS (Sort, Search, etc.)
// ==========================================
class STLAlgorithms
{
public:
    void explain()
    {
        cout << "--- ALGOS DEMO ---" << endl;
        // sort(v.begin(), v.end());
        // __builtin_popcount();
        // next_permutation();
    }
};

// ==========================================
// MAIN DRIVER
// ==========================================
int main()
{
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
