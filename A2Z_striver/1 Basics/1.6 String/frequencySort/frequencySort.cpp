#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    /*
     * Problem: Unique chars sorted by Frequency (Desc) then Alphabetical (Asc).
     * Goal: Return vector<char>
     * Time: O(N) | Space: O(U) where U is unique chars (max 26/128)
     */

    // ~ Approach 1: STL Sort with Custom Comparator (Standard)
    vector<char> frequencySort(const string& s) {
        // 1. Count Frequencies using Hash Map
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        // 2. Move map elements to a vector of pairs for sorting
        //    Map elements cannot be sorted directly.
        vector<pair<char, int>> items;
        for (auto it : counts) {
            items.push_back(it);
        }

        // 3. Sort using a Lambda Comparator
        //    Capture nothing [], take two pairs (a, b)
        sort(items.begin(), items.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            // Primary Sort: Frequency Descending (High to Low)
            if (a.second != b.second) {
                return a.second > b.second;
            }
            // Secondary Sort: Alphabetical Ascending (Low to High)
            return a.first < b.first;
        });

        // 4. Extract just the characters
        vector<char> result;
        for (const auto& item : items) {
            result.push_back(item.first);
        }

        return result;
    }

    // ~ Approach 2: Priority Queue (Heap)
    // Analysis: Useful if we wanted "Top K" instead of "All unique sorted".
    //           Slightly more overhead than sorting for this specific problem but good to know.
    vector<char> frequencySortHeap(const string& s) {
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;

        // Define a custom comparator struct for the priority_queue
        struct Compare {
            bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
                // Priority Queue puts the "largest" element on top.
                // If we want Frequency Descending, we want larger freq on top.
                // However, if freqs match, we want Alphabetical Ascending (smallest char on top).
                // In C++ PQ, "true" means "a goes below b".
                
                if (a.second != b.second)
                    return a.second < b.second; // Lower freq goes below -> Higher freq floats up
                
                return a.first > b.first;       // Higher char goes below -> Lower char floats up ('a' before 'z')
            }
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

        for (auto& it : counts) {
            pq.push(it);
        }

        vector<char> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

// --- Driver Code ---
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "tree";
    vector<char> res1 = sol.frequencySort(s1);
    
    cout << "Input: " << s1 << "\nOutput: [ ";
    for (char c : res1) cout << "'" << c << "' ";
    cout << "]" << endl; // Expected: ['e', 'r', 't']

    // Test Case 2 (Tie Breaking)
    string s2 = "bbaacc";
    vector<char> res2 = sol.frequencySort(s2);
    
    cout << "\nInput: " << s2 << "\nOutput: [ ";
    for (char c : res2) cout << "'" << c << "' ";
    cout << "]" << endl; // Expected: ['a', 'b', 'c'] (Alphabetic order for ties)

    return 0;
}