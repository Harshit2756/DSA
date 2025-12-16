// 07_PriorityQueue.h
#ifndef STLPRIORITYQUEUE_H
#define STLPRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include <vector>
#include <functional> // Required for greater<int>
using namespace std;

// ==========================================
// 7. PRIORITY QUEUE (Heap)
// ==========================================
class STLPriorityQueue
{
public:
    void explain()
    {
        cout << "\n\n --- PRIORITY QUEUE DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A container adapter where the element with the "highest priority" (largest value by default) is always at the TOP.
        //     . Internally implemented as a Heap (Binary Tree).
        //   / HEADER: #include <queue>
        //   ~ WHY USE:
        //     . Essential for Dijkstra's Algorithm (Shortest Path).
        //     . Used to find the K-th largest/smallest element efficiently.
        //     . Used in Huffman Coding (Data Compression).
        //   ~ TYPES:
        //     1. Max Heap (Default): Largest element is at top.
        //     2. Min Heap: Smallest element is at top.
        //   ~ COMPLEXITY:
        //    . Push: O(log N) (Tree traversal)
        //    . Pop:  O(log N) (Tree traversal)
        //    . Top:  O(1)     (Root access)
        //   ~ CRITICAL FUNCTIONS:
        //    . .push(val)   -> Adds element and sorts it into position.
        //    . .pop()       -> Removes the TOP (Highest priority) element.
        //    . .top()       -> Returns the TOP element.
        // ==========================================

        // --- 1. Max Heap (Default Behavior) ---
        MaxHeapDemo();

        // --- 2. Min Heap (Smallest on Top) ---
        MinHeapDemo();

        // --- 3. Size & Empty ---
        StatusDemo();

        cout << "==========================================" << endl;
    }

    void MaxHeapDemo()
    {
        //. By default, C++ Priority Queue is a MAX HEAP.
        //. The largest integer will always be at .top()
        priority_queue<int> pq;

        pq.push(5);
        pq.push(1);
        pq.push(7);
        pq.emplace(30);

        cout << "\n[Max Heap] Elements added: 5, 1, 7, 30";
        cout << "\n[Max Heap] Top element: " << pq.top() << endl; // Expected: 30

        pq.pop();                                                     // Removes 30
        cout << "[Max Heap] New Top after pop: " << pq.top() << endl; // Expected: 7

        // . accessing all elements (not typical usage)
        cout << "[Max Heap] Remaining elements: ";
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    void MinHeapDemo()
    {
        //. To make a MIN HEAP (Smallest at top), we need a specific syntax:
        //. priority_queue <Type, Container, Comparator>
        priority_queue<int, vector<int>, greater<int>> min_pq;

        min_pq.push(5);
        min_pq.push(1);
        min_pq.push(7);
        min_pq.emplace(30);

        cout << "\n[Min Heap] Elements added: 5, 1, 7, 30";
        cout << "\n[Min Heap] Top element: " << min_pq.top() << endl; // Expected: 5

        min_pq.pop();                                                     // Removes 5
        cout << "[Min Heap] New Top after pop: " << min_pq.top() << endl; // Expected: 10
    
        // . accessing all elements (not typical usage)
        cout << "[Min Heap] Remaining elements: ";
        while (!min_pq.empty())
        {
            cout << min_pq.top() << " ";
            min_pq.pop();
        }
        cout << endl;
    }

    void StatusDemo()
    {
        priority_queue<int> pq;
        pq.push(1);
        pq.push(2);

        cout << "\n[Size] Current size: " << pq.size() << endl; // 2

        while (!pq.empty())
        {
            cout << "[Access] Popping: " << pq.top() << endl;
            pq.pop();
        }
        cout << endl;
    }
};

#endif // STLPRIORITYQUEUE_H