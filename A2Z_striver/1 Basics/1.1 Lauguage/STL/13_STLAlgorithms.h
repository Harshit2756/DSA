// 12_Algorithms.h
#ifndef STLALGORITHMS_H
#define STLALGORITHMS_H

#include <iostream>
#include <vector>
#include <algorithm> // Sort, Find, Count, Reverse, etc.
#include <numeric>   // Accumulate
#include <cmath>     // Pow
using namespace std;

// ==========================================
// 12. ALGORITHMS (Sorting, Searching, Math)
// ==========================================
class STLAlgorithms
{
public:
    void explain()
    {
        cout << "\n\n --- ALGORITHMS DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A collection of optimized functions to process ranges of data.
        //   / HEADERS: <algorithm>, <numeric>, <cmath>
        //   ~ WHY USE:
        //     . Cleaner code (replaces manual for-loops).
        //     . Highly optimized (usually faster than manual implementation).
        //   ~ CRITICAL FUNCTIONS:
        //     . sort(start, end)        -> Sorts range (O(N log N)).
        //     . accumulate(start, end, init) -> Sums up range (O(N)).
        //     . count(start, end, val)  -> Counts occurrences (O(N)).
        //     . find(start, end, val)   -> Returns iterator to first occurrence (O(N)).
        //     . reverse(start, end)     -> Reverses range in-place (O(N)).
        //     . max_element(start, end) -> Returns iterator to max val (O(N)).
        //     . next_permutation()      -> Reorders to next lexicographical state.
        // ==========================================

        // --- 1. Sorting & Custom Comparator ---
        SortDemo();

        // --- 2. Math Operations (Accumulate, Pow) ---
        MathDemo();

        // --- 3. Search & Count ---
        SearchCountDemo();

        // --- 4. Permutations ---
        PermutationDemo();

        // --- 5. Min/Max & Reverse ---
        UtilsDemo();

        cout << "==========================================" << endl;
    }

    //. Custom Comparator for Sorting (Descending)
    static bool comp(int a, int b)
    {
        return a > b; // Returns true if 'a' should come before 'b'
    }
    //. Custom Comparator for Sorting Pairs
    static bool comp_pair(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first; // Ascending order of first element if second elements are equal
        return a.second > b.second; // Descending order of second element
    }

    void SortDemo()
    {
        vector<int> v = {3, 1, 4, 1, 5, 0};

        //. Default Sort (Ascending)
        sort(v.begin() + 1, v.begin() + 5); // Sort from index 1 to 4
        cout << "\n[Sort] Ascending for custom range (1 to 4): ";
        for (int x : v)
            cout << x << " "; // 3 1 4 1 5 0

        //. Custom Comparator Sort (Descending)
        sort(v.begin(), v.end(), comp);
        // Or use lambda: sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
        cout << "\n[Sort] Descending (Comparator): ";
        for (int x : v)
            cout << x << " "; // 9 5 4 3 1 1

        //. Complex example using custom comparator for pairs
        vector<pair<int, int>> vp = {{1, 3}, {2, 2}, {1, 2}, {2, 3}};

        // Default Sort (Ascending by first element, then second)
        // sort(vp.begin(), vp.end());
        cout << "\n[Sort] Pairs Ascending (Default): ";
        for (auto p : vp)
            cout << "(" << p.first << "," << p.second << ") "; // (1,2) (1,3) (2,2) (2,3)
        // so we want to sort according to the second value increasingly and if tie then according to first value decreasingly
        sort(vp.begin(), vp.end(), comp_pair);
        cout << "\n[Sort] Pairs Descending (Comparator): ";
        for (auto p : vp)
            cout << "(" << p.first << "," << p.second << ") "; // (1,3) (2,3) (1,2) (2,2)

    }



    void MathDemo()
    {
        //. ACCUMULATE (Sum) - Requires <numeric>
        vector<int> v = {1, 2, 3, 4, 5};
        // 0 is the initial sum value
        int sum = accumulate(v.begin(), v.end(), 0);
        cout << "\n\n[Accumulate] Sum of vector: " << sum; // 15

        //. POW (Power) - Requires <cmath>
        double base = 2.0, exp = 3.0;
        cout << "\n[Pow] 2^3 = " << pow(base, exp); // 8
    }

    void SearchCountDemo()
    {
        vector<int> v = {1, 2, 3, 1, 2, 1};

        //. COUNT: Frequency of a value
        int cnt = count(v.begin(), v.end(), 1);
        cout << "\n\n[Count] Frequency of 1: " << cnt; // 3

        //. FIND: Returns iterator to first occurrence
        auto it = find(v.begin(), v.end(), 3);
        if (it != v.end())
            cout << "\n[Find] Found 3 at index: " << (it - v.begin());
        else
            cout << "\n[Find] Not Found";
    }

    void PermutationDemo()
    {
        //. Rearranges range into next lexicographically greater permutation
        vector<int> v = {1, 2, 3};

        cout << "\n[Permutation] ";
        do
        {
            cout << "\nCurrent permutation: ";
            for (int x : v)
                cout << x << " ";
        } while (next_permutation(v.begin(), v.end()));
    }

    void UtilsDemo()
    {
        vector<int> v = {1, 5, 3, 9, 7};

        //. MAX ELEMENT: Returns iterator
        auto it = max_element(v.begin(), v.end());
        cout << "\n\n[Max Element] Max value is: " << *it; // 9

        //. MIN ELEMENT: Returns iterator
        it = min_element(v.begin(), v.end());
        cout << "\n[Min Element] Min value is: " << *it; // 1

        //. REVERSE: In-place reversal
        vector<int> v_rev = {1, 3, 2, 6, 5};
        reverse(v_rev.begin(), v_rev.end());

        cout << "\n[Reverse] Reversed vector: ";
        for (int x : v_rev)
            cout << x << " "; // 5 6 2 3 1
        cout << endl;
    }
};

#endif // STLALGORITHMS_H