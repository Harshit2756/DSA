// 13_Multimap.h
#ifndef STLMULTIMAP_H
#define STLMULTIMAP_H

#include <iostream>
#include <map>
#include <string>
using namespace std;

// ==========================================
// 13. MULTIMAP (Sorted & Duplicate Keys)
// ==========================================
class STLMultimap
{
public:
    void explain()
    {
        cout << "\n\n --- MULTIMAP DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: An associative container that acts like a Map but allows DUPLICATE KEYS.
        //     . Keys are stored in sorted order.
        //   / HEADER: #include <map>
        //   ~ WHY USE:
        //     . When a single key needs to map to multiple values (e.g., Dictionary word -> Multiple definitions).
        //     . Graph adjacency lists (Node -> Neighbors).
        //   ~ RESTRICTIONS:
        //     . NO `[]` Operator: You cannot do mp[key]. You must use .insert().
        //   ~ CRITICAL FUNCTIONS:
        //     . .insert({k, v}) -> Adds a new key-value pair.
        //     . .count(key)     -> Returns number of entries with that key.
        //     . .erase(key)     -> Removes ALL entries with that key.
        //     . .erase(iter)    -> Removes ONE specific entry.
        //     . .find(key)      -> Returns iterator to the FIRST occurrence of key.
        //     . .equal_range(k) -> Returns pair of iterators (start, end) for that key.
        // ==========================================

        // --- 1. Basic Operations ---
        BasicOps();

        // --- 2. Erasing Logic (All vs One) ---
        EraseDemo();

        cout << "==========================================" << endl;
    }

    void PrintMultimap(const multimap<int, string> &mmp)
    {
        for (auto it : mmp)
            cout << "  Key: " << it.first << " -> Value: " << it.second << endl;
        cout << endl;
    }

    void BasicOps()
    {
        multimap<int, string> mmp;

        //. Insertion must use .insert()
        mmp.insert({1, "Alice"});
        mmp.insert({1, "Alice_Clone"}); // Duplicate Key! 
        mmp.insert({5, "Bob"});
        mmp.insert({2, "Charlie"});

        cout << "\n[Insert] Multimap contents (Sorted by Key):" << endl;
        PrintMultimap(mmp);

        //. Count how many items share a key
        cout << "[Count] Number of entries for Key 1: " << mmp.count(1) << endl; // 2

        //. Finding range of entries for a key
        auto range = mmp.equal_range(1);
        cout << "[Equal Range] Entries for Key 1:" << endl;
        for (auto it = range.first; it != range.second; ++it)
        {
            cout << "  Key: " << it->first << " -> Value: " << it->second << endl;
        }
        cout << endl;
    }

    void EraseDemo()
    {
        multimap<int, string> mmp;
        mmp.insert({10, "A"});
        mmp.insert({10, "B"});
        mmp.insert({10, "C"});
        mmp.insert({20, "D"});

        cout << "\n[Erase] Original Map:" << endl;
        PrintMultimap(mmp);

        //. TRAP: Erasing by Key removes EVERYTHING with that key
        // mmp.erase(10); // Would remove A, B, and C

        //. Deleting only ONE specific instance (e.g., the first '10')
        auto it = mmp.find(10); // Points to first 10
        if (it != mmp.end())
        {
            mmp.erase(it); // Only removes "A"
        }

        cout << "[Erase] After erasing single iterator for Key 10:" << endl;
        PrintMultimap(mmp);
    }
};

#endif // STLMULTIMAP_H