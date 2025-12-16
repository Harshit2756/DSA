// 10_UnorderedSet.h
#ifndef STLUNORDEREDSET_H
#define STLUNORDEREDSET_H

#include <iostream>
#include <unordered_set>
using namespace std;

// ==========================================
// 10. UNORDERED SET (Unique & Not Sorted)
// ==========================================
class STLUnorderedSet
{
public:
    void explain()
    {
        cout << "\n\n --- UNORDERED SET DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A container that stores unique elements but in NO specific order(insertion order is ).
        //   / HEADER: #include <unordered_set>
        //   ~ WHY USE:
        //     . Purely for speed. It is faster search operations compared to a set due to hashing.
        //     . Use this when the order of elements doesn't matter.
        //   ~ INTERNAL:
        //     . Implemented using a Hash Table.
        //   ~ COMPLEXITY:
        //     . Average Case: O(1) (Constant time) for Insert/Find/Erase.
        //     . Worst Case: O(N) (Rare, happens on Hash Collisions).
        //   ~ LIMITATIONS:
        //     . No .lower_bound() or .upper_bound().
        //     . Elements are printed in random order.
        // ==========================================

        // --- 1. Basic Operations & Random Order ---
        BasicOps();

        // --- 2. Collision / Worst Case Note ---
        ComplexityNote();

        cout << "==========================================" << endl;
    }

    void BasicOps()
    {
        unordered_set<int> ust;
        ust.insert(10);
        ust.insert(50);
        ust.insert(5);
        ust.insert(20);
        ust.insert(10); // Duplicate ignored

        //. Notice the output order is random (depends on hashing)
        cout << "\n[Unordered Set] Elements: ";
        for (auto val : ust)
            cout << val << " ";
        cout << endl;

        //. Search is O(1)
        int target = 50;
        if (ust.find(target) != ust.end())
        {
            cout << "[Find] Found " << target << " efficiently." << endl;
        }
    }

    void ComplexityNote()
    {
        //. Comparison Table
        // +─────────────┬─────────────────┬──────────────────────+
        // │ Feature     │ Set             │ Unordered Set        │
        // +─────────────┼─────────────────┼──────────────────────+
        // │ Internal    │ Red-Black Tree  │ Hash Table           │
        // │ Order       │ Sorted          │ Random               │
        // │ Avg Time    │ O(log N)        │ O(1)                 │
        // │ Worst Time  │ O(log N)        │ O(N) (Rare)          │
        // +─────────────┴─────────────────┴──────────────────────+

        cout << "\n[Note] Use Unordered Set unless you specifically need the data sorted." << endl;
    }
};

#endif // STLUNORDEREDSET_H