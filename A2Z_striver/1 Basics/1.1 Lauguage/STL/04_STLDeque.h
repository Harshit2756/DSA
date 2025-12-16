// STLDeque.h
#ifndef STLDEQUE_H
#define STLDEQUE_H

#include <iostream>
#include <deque>
using namespace std;

// ==========================================
// 4. DEQUE (Double Ended Queue)
// ==========================================
class STLDeque
{
public:
    void explain()
    {
        cout << "\n\n --- DEQUE DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A sequence container with the ability to expand and contract on both ends efficiently.
        //   / HEADER: #include <deque>
        //   ~ WHY USE:
        //     ~ It supports fast insertions and deletions at both the beginning and the end.
        //     ~ It is more flexible than a vector or list in scenarios where elements are frequently added or removed from both ends.
        //     ~ Unlike Vector, it allows O(1) push_front.
        //     ~ Unlike List, it allows Random Access (dq[i]).
        //   ~ INTERNAL:
        //     ~ Maintains a map of pointers to different memory chunks.
        //     ~ Growing front just means allocating a new chunk, not shifting elements.
        // +─────────────┬─────────────────────┬──────────────────────+
        // │ Operation   │ Vector Cost         │ Deque Cost           │
        // +─────────────┼─────────────────────┼──────────────────────+
        // │ Push Front  │ O(N) (Shift all)    │ O(1) (New chunk)     │
        // │ Push Back   │ O(1)                │ O(1)                 │
        // │ Access [i]  │ O(1) (Fastest)      │ O(1) (Slightly slower│
        // +─────────────┴─────────────────────┴──────────────────────+
        //   ~ SYNTAX:
        //    . deque<int> dq;
        //   ~ CRITICAL FUNCTIONS:
        //    . .push_front(val) / .emplace_front(val) -> Adds to start.
        //    . .push_back(val) / .emplace_back(val)   -> Adds to end.
        //    . .pop_front()    -> Removes first element.
        //    . .pop_back()     -> Removes last element.
        //    . .front() / .back() -> Access ends.
        //    . .at(i) / [i]    -> Random Access.
        // ==========================================

        // --- 1. Basic Operations ---
        BasicOps();

        // --- 2. Access (Random Access!) ---
        AccessDemo();

        // --- 3. Deletion ---
        DeleteDemo();

        cout << "==========================================" << endl;
    }

    void PrintDeque(const deque<int> &dq)
    {
        for (auto ele : dq)
            cout << ele << " ";
        cout << endl;
    }

    void BasicOps()
    {

        deque<int> dq;
        dq.push_back(1);     // {1}
        dq.emplace_back(2);  // {1, 2}

        //. The Superpower: Fast Front Insertion like List
        dq.push_front(4);    // {4, 1, 2}
        dq.emplace_front(3); // {3, 4, 1, 2}

        cout << "Deque after insertions: ";
        PrintDeque(dq);
    }

    void AccessDemo()
    {
        deque<int> dq = {10, 20, 30, 40, 50};

        //. Using Iterator
        auto it = dq.begin();
        cout << "\nFirst Element using iterator: " << *(it) << endl;
        it++;
        cout << "Second Element using iterator: " << *(it) << endl;

        //. Unlike List, Deque has Random Access
        cout << "\nElement at index 2 (dq[2]): " << dq[2] << endl;
        cout << "Element at index 0 (dq.at(0)): " << dq.at(0) << endl;

        //. Front and Back Access
        cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    }

    void DeleteDemo()
    {
        deque<int> dq = {10, 20, 30, 40};
        cout << "\nOriginal Deque: ";
        PrintDeque(dq);

        dq.pop_back();  // Removes 40
        dq.pop_front(); // Removes 10

        cout << "After pop_front() & pop_back(): ";
        PrintDeque(dq);
        
        //. Erase works just like vector
        //. Note: Deleting from the middle is still O(N) because elements inside chunks might shift.
        dq.erase(dq.begin()); 
        cout << "After erase(begin): ";
        PrintDeque(dq);
    }
};

#endif // STLDEQUE_H