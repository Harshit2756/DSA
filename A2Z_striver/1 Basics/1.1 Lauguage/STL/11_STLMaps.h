// 11_Map.h
#ifndef STLMAP_H
#define STLMAP_H

#include <iostream>
#include <map>
using namespace std;

// ==========================================
// 11. MAP (Key-Value Pairs)
// ==========================================
class STLMaps
{
public:
    void explain()
    {
        cout << "\n\n --- MAP DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: An associative container that stores elements as Key-Value pairs.
        //     . Keys are UNIQUE and SORTED.
        //     . Values can be duplicates and are not sorted.
        //   / HEADER: #include <map>
        //   ~ WHY USE:
        //     . Frequency counting (e.g., Count how many times a number appears).
        //     . Dictionary lookups (Name -> Phone Number).
        //   ~ INTERNAL:
        //     . Red-Black Tree (Balanced BST).
        //   ~ COMPLEXITY:
        //     . Insert/Access/Find: O(log N).
        //   ~ CRITICAL FUNCTIONS:
        //     . mp[key] = val   -> Inserts or Updates value.
        //     . .insert({k, v}) -> Inserts pair.
        //     . .find(key)      -> Returns iterator to pair.
        //     . .erase(key)     -> Removes key-value pair.
        // ==========================================

        // --- 1. Basic Operations ---
        BasicOps();

        // --- 2. Accessing & Modifying ---
        AccessDemo();

        // --- 3. Iterating through a Map ---
        IterateDemo();

        cout << "==========================================" << endl;
    }

    void BasicOps()
    {
        // Syntax: map<KeyType, ValueType> name;
        map<int, string> mp;

        //. Insertion Method 1: Array Syntax (Most Common)
        mp[1] = "Alice";
        mp[5] = "Bob";
        mp[3] = "Charlie"; // Automatically sorted by Key: {1, 3, 5}

        //. Insertion Method 2: insert() function
        mp.insert({2, "David"});

        //. Duplicate Keys are overwritten or ignored depending on method
        mp[1] = "Alice Updated"; // Updates the value for Key 1

        cout << "\n[Basic] Map created with Keys: 1, 2, 3, 5" << endl;
    }

    void AccessDemo()
    {
        map<int, int> scores;

        //. Accessing
        scores[10] = 100;

        cout << "\n[Access] Score for ID 10: " << scores[10] << endl;

        //. TRAP: accessing a key that doesn't exist CREATES it with default value (0).
        cout << "[Trap] Accessing non-existent key 99: " << scores[99] << endl;
        cout << "      (Key 99 was just created with value 0)" << endl;

        //. Check existence safely using find()
        if (scores.find(50) == scores.end())
        {
            cout << "[Safe Check] Key 50 does not exist." << endl;
        }
    }

    void IterateDemo()
    {
        map<int, string> mp;
        mp[1] = "A";
        mp[2] = "B";
        mp[3] = "C";

        cout << "\n[Iterate] Key -> Value:" << endl;
        for (auto it : mp)
        {
            // it is a pair: {first: Key, second: Value}
            cout << "  " << it.first << " -> " << it.second << endl;
        }
    }
};

#endif // STLMAP_H