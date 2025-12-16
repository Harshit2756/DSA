// 08_Set.h
#ifndef STLSET_H
#define STLSET_H

#include <iostream>
#include <set>
using namespace std;

// ==========================================
// 8. SET (Sorted & Unique)
// ==========================================
class STLSets
{
public:
    void explain()
    {
        cout << "\n\n --- SET DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: An associative container that stores unique elements following a specific order (Sorted).
        //   / HEADER: #include <set>
        //   ~ WHY USE:
        //     . When you need a list of unique items (Removing duplicates).
        //     . When you need to check if an item exists efficiently (O(log N)).
        //     . When you need the data to stay sorted automatically.
        //   ~ INTERNAL:
        //     . Implemented as a Red-Black Tree (Balanced BST).
        //   ~ COMPLEXITY:
        //     . Insert/Find/Erase: O(log N)
        //   ~ CRITICAL FUNCTIONS:
        //     . .insert(val)    -> Adds element (Ignored if duplicate).
        //     . .emplace(val)   -> Faster insertion.
        //     . .find(val)      -> Returns iterator to element (or .end() if not found).
        //     . .count(val)     -> Returns 1 if present, 0 if not (Since unique).
        //     . .erase(val/it)  -> Removes element.
        //     . .lower_bound()  -> Returns iterator to first element >= val.
        //     . .upper_bound()  -> Returns iterator to first element > val.
        // ==========================================

        // --- 1. Insertion & Unique Property ---
        BasicOps();

        // --- 2. Searching (Find & Count) ---
        SearchDemo();

        // --- 3. Deletion ---
        DeleteDemo();

        // --- 4. Lower & Upper Bound (Crucial) ---
        BoundDemo();

        cout << "==========================================" << endl;
    }

    void PrintSet(const set<int> &st)
    {
        //. Sets do not support Random Access (st[i] is invalid).
        //. Must use traversal.
        for (auto val : st)
            cout << val << " ";
        cout << endl;
    }

    void BasicOps()
    {
        //. Elements are stored in sorted order.
        //. Duplicates are ignored.
        set<int> st;
        st.insert(10);
        st.emplace(20);
        st.insert(10); // Duplicate - Ignored
        st.insert(5);  // Will be placed at the start
        st.insert(15);

        cout << "\n[Insert] Set Elements (Auto-sorted): ";
        PrintSet(st); // Expected: 5 10 15 20
    }

    void SearchDemo()
    {
        set<int> st = {1, 2, 3, 4, 5};

        //. find(val) returns an iterator to the element or st.end() if not found.
        auto it = st.find(3);

        if (it != st.end())
        {
            cout << "\n[Find] Found element: " << *(it) << endl;
        }
        else
        {
            cout << "\n[Find] Element not found." << endl;
        }

        //. count(val) returns 1 or 0 (easier for simple checks).
        if (st.count(3))
        {
            cout << "[Count] Element 3 exists." << endl;
        }
    }

    void DeleteDemo()
    {
        set<int> st = {10, 20, 30, 40};

        //. Erase by Value
        st.erase(20); // Removes 20

        //. Erase by Iterator
        auto it = st.find(30);
        if (it != st.end())
            st.erase(it); // Removes 30

        //. Erase by Range [start, end)
        st.erase(st.begin(), st.find(40)); // Removes all elements before 40

        cout << "\n[Delete] After erasing 20 & 30: ";
        PrintSet(st);
    }

    void BoundDemo()
    {
        //. Very important for competitive programming!
        //. lower_bound(x): First element >= x
        //. upper_bound(x): First element > x

        set<int> st = {10, 20, 30, 40, 50};

        auto lb = st.lower_bound(30); // Points to 30 (because 30 >= 30)
        auto ub = st.upper_bound(30); // Points to 40 (because 40 > 30)

        cout << "\n[Bounds] For value 30:" << endl;
        cout << "  Lower Bound (>=): " << *lb << endl;
        cout << "  Upper Bound (>):  " << *ub << endl;
    }
};

#endif // STLSET_H