#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for sort, min
#include <climits>   // for INT_MAX

using namespace std;

// Header Comment Block
// Problem: Find Second Highest Occurring Element (Strictly lower frequency).
// Rules: 
//   1. Frequency must be strictly less than Max Frequency.
//   2. If multiple elements share this frequency, return Smallest Value.
//   3. If no strictly lower frequency exists, return -1.

class Solution {
public:

    // ~ Approach 1: Sorting (The Mental Model)
    // Analysis: Time O(N + U log U) | Space O(N)
    int secondMostFrequentSorting(vector<int>& arr) {
        if (arr.empty()) return -1;

        // - Step 1: Count Frequencies
        unordered_map<int, int> freqMap;
        for (int x : arr) freqMap[x]++;

        // - Step 2: Get Unique Frequencies
        // We need to find the distinct frequency values (e.g., 3, 2, 1)
        vector<int> freqs;
        for (auto it : freqMap) {
            freqs.push_back(it.second);
        }

        // Sort Descending (Greater -> Smaller)
        sort(freqs.begin(), freqs.end(), greater<int>());

        // Remove duplicates to find strict ranks
        // (std::unique moves duplicates to end, erase removes them)
        auto last = unique(freqs.begin(), freqs.end());
        freqs.erase(last, freqs.end());

        // - Logic: If fewer than 2 distinct frequencies, no second place exists.
        if (freqs.size() < 2) return -1;

        int targetFreq = freqs[1]; // The second highest frequency

        // - Step 3: Find smallest element with targetFreq
        int minEle = INT_MAX;
        bool found = false;

        for (auto it : freqMap) {
            int num = it.first;
            int count = it.second;

            if (count == targetFreq) {
                minEle = min(minEle, num);
                found = true;
            }
        }

        return found ? minEle : -1;
    }


    // ~ Approach 2: One-Pass Traversal (Optimal Logic)
    // Analysis: Time O(N) | Space O(N)
    // Logic: Tracks Max and Second Max dynamically.
    int secondMostFrequentTraversal(vector<int>& arr) {
        if (arr.empty()) return -1;

        unordered_map<int, int> freqMap;
        for (int x : arr) freqMap[x]++;

        int maxFr = 0;
        int secFr = 0;
        
        // Use -1 as "Not Found" flag
        int maxEle = -1;
        int secEle = -1; 

        for (auto it : freqMap) {
            int ele = it.first;
            int fr = it.second;

            // - Case 1: New Max Found
            // The old Max becomes the new "Best Second Place Candidate"
            if (fr > maxFr) {
                secFr = maxFr;
                secEle = maxEle;

                maxFr = fr;
                maxEle = ele;
            }
            // - Case 2: Tie for Max
            // Logic: Update MaxEle to smallest, but DO NOT update secEle
            // because this element is a "Winner", not a "Runner Up".
            else if (fr == maxFr) {
                maxEle = min(maxEle, ele);
            }
            // - Case 3: New Second Max Found
            // Strictly less than maxFr, but better than current secFr
            else if (fr > secFr) {
                secFr = fr;
                secEle = ele;
            }
            // - Case 4: Tie for Second Max
            // Tie-breaker: Pick smallest value
            else if (fr == secFr) {
                if (secEle == -1) {
                    secEle = ele;
                } else {
                    secEle = min(secEle, ele);
                }
            }
        }

        return secEle;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Ex 1: [1, 2, 2, 3, 3, 3] -> Max(3) is 3, Sec(2) is 2.
    vector<int> arr1 = {1, 2, 2, 3, 3, 3};

    // Ex 2: [4, 4, 5, 5, 6, 7] -> Max(2) is 4/5. Sec(1) is 6/7. Smallest is 6.
    vector<int> arr2 = {4, 4, 5, 5, 6, 7};

    // Ex 3: [10, 9, 7, 7] -> Max(2) is 7. Sec(1) is 10/9. Smallest is 9.
    vector<int> arr3 = {10, 9, 7, 7};

    cout << "Test 1 (Expected 2): " << sol.secondMostFrequentTraversal(arr1) << endl;
    cout << "Test 2 (Expected 6): " << sol.secondMostFrequentTraversal(arr2) << endl;
    cout << "Test 3 (Expected 9): " << sol.secondMostFrequentTraversal(arr3) << endl;

    return 0;
}