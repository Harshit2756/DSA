// STLLists.h
#ifndef STLLISTS_H
#define STLLISTS_H

#include <iostream>
#include <list>
#include <algorithm> // For std::find
using namespace std;

// ==========================================
// 3. LISTS (Doubly Linked List)
// ==========================================
class STLLists
{
public:
    void explain()
    {
        cout << "\n\n --- LISTS DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A Doubly Linked List (Non-contiguous memory). Each node stores data + 2 pointers (prev, next).
        //   / HEADER: #include <list>
        //   ~ WHY USE:
        //     ~ O(1) Insert/Delete at the FRONT (push_front). In vectors, this is O(N).
        //     ~ O(1) Insert/Delete at the BACK (push_back).
        //     ~ O(1) Insert/Delete anywhere if the iterator is known.
        //   ~ CONS:
        //     ~ No Random Access: You cannot do ls[2] or ls.at(2).
        //     ~ Traversal is O(N) (Must jump pointer to pointer).
        //     ~ Higher memory usage due to storing pointers.
        // +──────────────┬─────────────────────┬──────────────────────+
        // │ Operation    │ Vector Cost         │ List Cost            │
        // +──────────────┼─────────────────────┼──────────────────────+
        // │ Insert Front │ O(N) (Shifting)     │ O(1) (Ptr change)    │
        // │ Insert Back  │ O(1)                │ O(1)                 │
        // │ Random Access| O(1)                │ NA (Invalid)         │
        // +──────────────┴─────────────────────┴──────────────────────+
        //   ~ CRITICAL FUNCTIONS:
        //    . .push_front(val) / .emplace_front(val) -> Adds to start.
        //    . .push_back(val) / .emplace_back(val)   -> Adds to end.
        //    . .pop_front()  -> Removes first element.
        //    . .pop_back()   -> Removes last element.
        //    . .remove(val)  -> Removes all occurrences of 'val'.
        //    . .reverse()    -> Reverses the list in O(N).
        //    . .sort()       -> Sorts the list (N log N). Note: std::sort() doesn't work!
        // ==========================================

        // --- 1. Basic Operations ---
        BasicOps();

        // --- 2. Access & Iteration ---
        AccessDemo();

        // --- 3. Deletion ---
        DeleteDemo();

        // --- 4. Sorting & Reversing ---
        SortingDemo();

        cout << "==========================================" << endl;
    }

    void PrintList(const list<int> &ls)
    {
        for (auto ele : ls)
            cout << ele << " ";
        cout << endl;
    }

    void BasicOps()
    {

        list<int> ls;
        ls.push_back(20);    // {20}
        ls.emplace_back(30); // {20, 30}

        //. The major advantage over vector:
        ls.push_front(10);   // {10, 20, 30}
        ls.emplace_front(5); // {5, 10, 20, 30}

        cout << "List after insertions: ";
        PrintList(ls);
    }

    void AccessDemo()
    {
        list<int> ls = {10, 20, 30, 40};

        //. Iterators
        auto it = ls.begin(); // Iterator to first element
        cout << "\nFirst Element using iterator: " << *(it) << endl;
        it++;
        cout << "Second Element using iterator: " << *(it) << endl;

        //. Direct Access (Front/Back)
        cout << "\nFront: " << ls.front();
        cout << " Back: " << ls.back() << endl;

        //. NO INDEXING: ls[2] is INVALID.
        //. We must use iterators to traverse.
        cout << "Traversal: ";
        for (auto it = ls.begin(); it != ls.end(); it++)
        {
            cout << *(it) << " ";
        }
        cout << endl;
    }

    void DeleteDemo()
    {
        list<int> ls = {5, 10, 20, 30, 15, 15};
        cout << "\nOriginal List for Deletion: ";
        PrintList(ls);

        //. Pop Operations
        ls.pop_front(); // Removes 5
        ls.pop_back();  // Removes last 15
        cout << "After pop_front() & pop_back(): ";
        PrintList(ls);

        //. Value-based Removal (Unique to List)
        ls.remove(15); // Removes ALL instances of 15
        cout << "After remove(15): ";
        PrintList(ls);
    }

    void SortingDemo()
    {
        //. Special Case: std::sort(ls.begin(), ls.end()) FAILS.
        //. Why? std::sort requires Random Access Iterators. List has Bidirectional Iterators.

        list<int> ls = {10, 50, 30, 20, 40};

        cout << "\nUnsorted List: ";
        PrintList(ls);

        ls.sort(); // Member function sort
        cout << "Sorted List (.sort()): ";
        PrintList(ls);

        ls.reverse();
        cout << "Reversed List (.reverse()): ";
        PrintList(ls);
    }
};

#endif // STLLISTS_H