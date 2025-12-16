// STLPairs.h
#ifndef STLPAIRS_H
#define STLPAIRS_H

#include <iostream>
#include <string>
#include <utility> // Where std::pair is officially defined, though <bits/stdc++.h> works in some environments.
using namespace std;

// ==========================================
// 1. PAIRS (Utility)
// ==========================================
class STLPairs
{
public:
    void explain()
    {
        cout << "\n\n --- PAIRS DEMO --- \n";
        // NOTES:
        // ==========================================
        //   ! WHAT: A utility container to store two heterogeneous objects (different types) as a single unit.
        //   / HEADER: #include <utility> (or <bits/stdc++.h>)
        //   ~ WHY USE:
        //     ~ To treat two values as one unit (e.g., Key-Value pairs).
        //     ~ Essential for Graphs (Node, Weight) or returning multiple values from a function.
        //     ~ Used internally by 'std::map'.
        //   ~ SYNTAX:
        //    . pair<dataType1, dataType2> pairName;
        //    . pair<dataType1, dataType2> pairName = {value1, value2};
        //    . pair<dataType1, dataType2> pairName = make_pair(value1, value2);
        //   ~ ACCESS:
        //     . pairName.first  -> Access 1st element
        //     . pairName.second -> Access 2nd element
        // ==========================================

        // --- 1. Basic Declaration & Initialization ---
        pair<int, string> student;
        student.first = 1; // Manual assignment
        student.second = "Alice";

        cout << "Simple Pair -> Roll No: " << student.first << ", Name: " << student.second << endl;

        // --- 2. Nested Pairs (Complex Structure) ---
        //.  Storing: {{RollNo, Section}, Marks}
        pair<pair<int, char>, int> complexPair = {{2, 'B'}, 20};

        cout << "Nested Pair -> Roll No: " << complexPair.first.first
             << ", Section: " << complexPair.first.second
             << ", Marks: " << complexPair.second << endl;

        // --- 3. Array of Pairs (Common in Competitive Programming) ---
        //. Useful for sorting items while keeping their original index or metadata
        pair<int, int> arr[] = {{1, 10}, {2, 20}, {3, 30}};
        cout << "Array of Pairs -> Index 1 Value: " << arr[1].second << endl;

        cout << "==========================================" << endl;
    }
};

#endif // STLPAIRS_H
