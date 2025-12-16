// STLVectors.h
#ifndef STLVECTORS_H
#define STLVECTORS_H

#include <iostream>
#include <vector>
using namespace std;

// ==========================================
// 2. VECTORS (Dynamic Arrays)
// ==========================================
class STLVectors
{
public:
    void explain()
    {
        cout << "\n\n --- VECTORS DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A dynamic array that allows elements to be added or removed. It resizes automatically.
        //   / HEADER: #include <vector>
        //   ~ WHY USE:
        //     ~ Unlike int arr[100], size is not fixed.
        //     ~ Random Access is O(1) (e.g., v[i]).
        //     ~ Insertion/Deletion at the end is O(1).
        //     ~ Elements are stored in contiguous memory locations.
        //   ~ SYNTAX:
        //    . vector<int> v;                  // Empty vector
        //    . vector<int> v(5, 100);          // Size 5, all elements 100 ({100, 100, 100, 100, 100})
        //    . vector<int> v(5);               // Size 5, default values (0 for int)
        //    . vector<int> v2(v1);             // Copy of v1
        //   ~ CRITICAL FUNCTIONS:
        //    . .insert(iter, val)  -> Inserts val at iterator position.
        //    . .push_back(val)   -> Adds element to the end.
        //    . .emplace_back(val)-> Faster than push_back (constructs in-place).
        //  ------------------------------------------
        //    . .begin()         -> Returns iterator to first element.
        //    . .end()           -> Returns iterator to position after last element.
        //    . .rbegin()        -> Returns reverse iterator to last element.
        //    . .rend()          -> Returns reverse iterator to position before first element.
        //    . .front()          -> Returns the first element.
        //    . .back()           -> Returns the last element.
        //    . .pop_back()       -> Removes the last element.
        //    . .size()           -> Returns current size.
        //    . .erase(iter)      -> Deletes element at iterator position.
        //    . .clear()          -> Erases all elements.
        // ==========================================

        // --- 1. Basic Operations ---

        // --- 2. Initialization Variations ---
        InitializationDemo();

        // --- 3. Access ---
        AccessDemo();

        // --- 4. Deletion ---
        DeleteDemo();

        // --- 5. Insertion ---
        InsertionDemo();

        cout << "==========================================" << endl;
    }

    void PrintVector(const vector<int> &v)
    {
        for (auto ele : v)
            cout << ele << " ";
        cout << endl;
    }

    void InitializationDemo()
    {
        vector<int> v1;                       // Empty vector
        vector<int> v2(5, 100);               // Size 5, all elements 100
        vector<int> v3(5);                    // Size 5, default values (0 for int)
        vector<int> v4(v2);                   // Copy of v2
        vector<int> v5(v1.begin(), v1.end()); // Range from another vector
    }

    void AccessDemo()
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};

        //. v.begin() points to the first element.
        //. v.end() points to the position AFTER the last element.
        vector<int>::iterator it = v.begin();
        cout << "Element at index 0 using iterator: " << *(it) << endl;
        it++;
        cout << "Element at index 1 using iterator: " << *(it) << endl;
        cout << endl;
        //. v.rbegin() points to the last element.
        //. v.rend() points to the position BEFORE the first element.
        vector<int>::reverse_iterator rit = v.rbegin();
        cout << "Last Element using reverse iterator: " << *(rit) << endl;
        rit++;
        cout << "Second Last Element using reverse iterator: " << *(rit) << endl;
        cout << endl;

        //. accessing through array indexing
        cout << "Printing v using Indexing: " << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " "; // or v[i]
            // cout << v[i] << " ";
        }
        cout << endl;

        //. using normal loop with iterator
        cout << "Printing v using Loop: " << endl;
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *(it) << " ";
        }
        cout << "\n\n";

        //. Syntactic Sugar: 'auto' keyword (Interview Standard)
        cout << "Printing v using auto: " << endl;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *(it) << " ";
        }
        cout << "\n\n";

        //. For-Each Loop (Cleanest)
        cout << "Printing v using for-each: ";
        for (auto element : v)
        {
            cout << element << " ";
        }
        cout << "\n\n";
    }
    void InsertionDemo()
    {
        //. v = {}
        // +───────────┬───────────────────────────┬─────────────────────────────────+
        // │ Feature   │ push_back                 │emplace_back                     │
        // +───────────┼───────────────────────────┼─────────────────────────────────+
        // │ Input     │ An object of type T       │Constructor arguments for type T │
        // │ Operation │ Construct → Copy → Destroy│Construct In-Place               │
        // │ Efficiency│ Slower (copy overhead)    │Faster (saves copy)              │
        // │ Syntax    │ v.push_back({1, 2})       │v.emplace_back(1, 2)             │
        // +───────────┴───────────────────────────┴─────────────────────────────────+

        vector<int> v = {1, 2, 3, 4, 5};
        v.push_back(1);
        v.emplace_back(2); // {1, 2, 3, 4, 5, 1, 2}

        cout << "Current Vector: " << v[0] << " " << v[1] << endl;

        vector<int> v_ins(2, 100);              // {100, 100}
        v_ins.insert(v_ins.begin(), 300);       // {300, 100, 100}
        v_ins.insert(v_ins.begin() + 1, 2, 10); // Insert two 10s at index 1 -> {300, 10, 10, 100, 100}

        cout << "Size: " << v_ins.size() << endl; // 5
        v_ins.pop_back();                         // Removes last element
    }

    void DeleteDemo()
    {
        //. v = {10, 20, 12, 23}
        vector<int> v_del = {10, 20, 12, 23};
        cout << "Original Vector for Deletion: ";
        PrintVector(v_del);

        //. Single Erase
        v_del.erase(v_del.begin() + 1); // Removes 20 -> {10, 12, 23}
        cout << "After Erasing index 1: ";
        PrintVector(v_del);
        cout << "\n\n";

        //. Range Erase [start, end)
        //. Deletes start inclusive, but end exclusive.
        vector<int> v_range = {10, 20, 12, 23, 35};
        cout << "Original Vector for Range Deletion: ";
        PrintVector(v_range);

        v_range.erase(v_range.begin() + 2, v_range.begin() + 4); // Removes 12, 23 -> {10, 20, 35}
        cout << "After Range Erasing index 2 to 3: ";
        PrintVector(v_range);
        cout << "\n\n";

        //. Clear the entire vector
        cout << "Clearing the entire vector." << v_range.size() << endl;
        v_range.clear(); // v_range becomes empty
        cout << "After Clearing, size of v_range: " << v_range.size() << endl;
    }
};

#endif // STLVECTORS_H