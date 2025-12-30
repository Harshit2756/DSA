#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for sort, min, max
#include <climits>   // for INT_MAX, INT_MIN

using namespace std;

// Header Comment Block
// Problem: Sum of Highest and Lowest Frequencies.
// Input: Vector of integers.
// Output: Sum (int).
// Goal: O(N) Time | O(N) Space.

class Solution {
public:

    // ~ Approach 1: Sorting (Naive)
    // Analysis: Time O(N + U log U) | Space O(N)
    // Logic: Dump frequencies into a vector, sort it, pick ends.
    int sumHighLowSorting(vector<int>& arr) {
        if (arr.empty()) return 0;

        // - Step 1: Count Frequencies
        unordered_map<int, int> freqMap;
        for (int x : arr) {
            freqMap[x]++;
        }

        // - Step 2: Extract Frequencies into a Vector
        vector<int> frequencies;
        for (auto it : freqMap) {
            frequencies.push_back(it.second);
        }

        // - Step 3: Sort
        sort(frequencies.begin(), frequencies.end());

        // - Step 4: Sum First (Min) and Last (Max)
        return frequencies.front() + frequencies.back();
    }


    // ~ Approach 2: STL Algorithms (Clean One-Pass)
    // Analysis: Time O(N) | Space O(N)
    // Logic: Use std::min and std::max inside the loop implicitly.
    int sumHighLowSTL(vector<int>& arr) {
        if (arr.empty()) return 0;

        unordered_map<int, int> freqMap;
        for (int x : arr) freqMap[x]++;

        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;

        for (auto it : freqMap) {
            // it->second holds the frequency
            maxFreq = max(maxFreq, it.second);
            minFreq = min(minFreq, it.second);
        }

        return maxFreq + minFreq;
    }


    // ~ Approach 3: Manual Loop (The "Under the Hood" Way)
    // Analysis: Time O(N) | Space O(N)
    // Logic: Pure conditional checks, no helper functions.
    int sumHighLowManual(vector<int>& arr) {
        if (arr.empty()) return 0;

        // - Step 1: Count Frequencies
        unordered_map<int, int> freqMap;
        for (int x : arr) {
            freqMap[x]++;
        }

        // - Step 2: Initialize Extremes
        // Set min to MAX_INT so the first value is smaller
        // Set max to MIN_INT so the first value is larger
        int minFreq = INT_MAX;
        int maxFreq = INT_MIN;

        // - Step 3: Single Pass Loop
        // Iterate over the map entries
        for (auto it : freqMap) {
            int currentFreq = it.second;

            // Update Max
            if (currentFreq > maxFreq) {
                maxFreq = currentFreq;
            }

            // Update Min
            if (currentFreq < minFreq) {
                minFreq = currentFreq;
            }
        }

        return maxFreq + minFreq;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test Case 1: [1, 2, 2, 3, 3, 3]
    // Frequencies: {1:1, 2:2, 3:3} -> Min 1, Max 3 -> Sum 4
    vector<int> arr1 = {1, 2, 2, 3, 3, 3};

    // Test Case 2: [4, 4, 5, 5, 6]
    // Frequencies: {4:2, 5:2, 6:1} -> Min 1, Max 2 -> Sum 3
    vector<int> arr2 = {4, 4, 5, 5, 6};

    cout << "Sorting Approach (Arr1): " << sol.sumHighLowSorting(arr1) << endl;
    cout << "STL Approach (Arr1):     " << sol.sumHighLowSTL(arr1) << endl;
    cout << "Manual Approach (Arr2):  " << sol.sumHighLowManual(arr2) << endl;

    return 0;
}