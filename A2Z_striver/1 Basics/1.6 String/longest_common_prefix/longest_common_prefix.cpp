#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    // ~ Approach: Sorting
    // Analysis: Time O(N log N * L) | Space O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // - Step 1: Sort
        // This arranges strings lexicographically.
        // The strings with the least commonality will end up at ends (0 and n-1).
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        int i = 0;
        // - Step 2: Compare First vs Last
        while (i < first.length() && i < last.length()) {
            if (first[i] == last[i]) {
                i++;
            } else {
                break;
            }
        }

        // - Step 3: Return substring
        return first.substr(0, i);
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"flower", "flow", "flight"};
    cout << "Prefix: " << sol.longestCommonPrefix(arr) << endl; // Output: "fl"
    return 0;
}