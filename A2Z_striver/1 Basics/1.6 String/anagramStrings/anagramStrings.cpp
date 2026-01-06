#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort
#include <unordered_map>

using namespace std;

class Solution {
public:
    // ~ Approach 1: Sorting
    // Analysis: Time O(N log N) | Space O(1) (in-place sort allowed)
    bool isAnagramSorting(string s, string t) {
        if (s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }


    // ~ Approach 2: Hash Map
    // Analysis: Time O(N) | Space O(N) (or O(1) if limited to ASCII)
    bool isAnagramHashMap(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> count;
        
        // Count chars in s
        for (char c : s) count[c]++;
        
        // Decrement chars for t
        for (char c : t) {
            count[c]--;
            // Optimization: If count goes negative, we have an extra char
            if (count[c] < 0) return false;
        }
        
        return true;
    }


    // ~ Approach 3: Fixed-Size Array (Best Performance)
    // Analysis: Time O(N) | Space O(1) (Fixed 26 integers)
    // Logic: Same as Python Approach 3 but using vector or raw array.
    bool isAnagramArray(string s, string t) {
        if (s.length() != t.length()) return false;
        
        // Initialize vector of size 26 with zeros
        vector<int> freq(26, 0);
        
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++; // Increment for s
            freq[t[i] - 'a']--; // Decrement for t
        }
        
        for (int count : freq) {
            if (count != 0) return false;
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "Sorting: " << sol.isAnagramSorting("anagram", "nagaram") << endl;
    cout << "HashMap: " << sol.isAnagramHashMap("rat", "car") << endl;
    cout << "Array:   " << sol.isAnagramArray("anagram", "nagaram") << endl;
    return 0;
}