// 09_Multiset.h
#ifndef STLMULTISET_H
#define STLMULTISET_H

#include <iostream>
#include <set> // Multiset is also in <set>
using namespace std;

// ==========================================
// 9. MULTISET (Sorted & Duplicates Allowed)
// ==========================================
class STLMultiset
{
public:
    void explain()
    {
        cout << "\n\n --- MULTISET DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: An associative container that acts like a Set but allows DUPLICATE elements.
        //     . Elements are still stored in sorted order.
        //   / HEADER: #include <set>
        //   ~ WHY USE:
        //     . When you need a sorted list but expect repeats (e.g., Test scores, Ages).
        //     . When you need to count the frequency of elements dynamically.
        //     . Implemented as Red-Black Tree.
        //   ~ CRITICAL DIFFERENCES FROM SET:
        //     . .insert(val) -> Always inserts, even if it exists.
        //     . .count(val)  -> Returns the actual count (frequency), not just 0/1.
        //     . .erase(val)  -> Removes ALL instances of that value.
        //     . .erase(it)   -> Removes ONLY the single instance at that iterator.
        //     . .find(val)   -> Returns iterator to the FIRST occurrence.
        // ==========================================

        // --- 1. Basic Operations ---
        BasicOps();

        // --- 2. Erasing Logic (Crucial) ---
        EraseDemo();

        cout << "==========================================" << endl;
    }

    void PrintMultiset(const multiset<int> &ms)
    {
        for (auto val : ms)
            cout << val << " ";
        cout << endl;
    }

    void BasicOps()
    {
        multiset<int> ms;
        ms.insert(10);
        ms.insert(10); // Allowed!
        ms.insert(10);
        ms.insert(20);
        ms.insert(5);

        cout << "\n[Insert] Multiset Elements (Sorted & Duplicates): ";
        PrintMultiset(ms); // {5, 10, 10, 10, 20}

        //. Count returns the frequency
        cout << "[Count] Number of 10s: " << ms.count(10) << endl; // 3
    }

    void EraseDemo()
    {
        //. TRAP: There are two ways to delete in multiset.

        multiset<int> ms = {1, 1, 1, 2, 2, 3};
        cout << "\n[Erase] Original: ";
        PrintMultiset(ms);

        //. Method 1: Erase by Value -> Removes ALL occurrences
        multiset<int> ms1 = ms;
        ms1.erase(2); // Removes both 2s
        cout << "  -> After erase(2) (By Value): ";
        PrintMultiset(ms1);

        //. Method 2: Erase by Iterator -> Removes ONE occurrence
        multiset<int> ms2 = ms;

        // ms2.find(1) returns iterator to the FIRST '1'
        ms2.erase(ms2.find(1));

        cout << "  -> After erase(find(1)) (By Iterator): ";
        PrintMultiset(ms2); // {1, 1, 2, 2, 3} -> Only one '1' removed
    }
};

#endif // STLMULTISET_H