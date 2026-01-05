#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // ~ Approach 1: Generic Map (Good for any characters)
    // Analysis: Time O(N) | Space O(N)
    bool isIsomorphicMap(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> map_s_t;
        unordered_map<char, char> map_t_s;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check s -> t mapping
            if (map_s_t.count(c1) && map_s_t[c1] != c2) return false;
            
            // Check t -> s mapping
            if (map_t_s.count(c2) && map_t_s[c2] != c1) return false;

            // Create mapping if neither existed
            map_s_t[c1] = c2;
            map_t_s[c2] = c1;
        }
        return true;
    }

    // ~ Approach 2: ASCII Arrays (Fastest for Interview)
    // Analysis: Time O(N) | Space O(1) (Fixed size 256)
    bool isIsomorphicArray(string s, string t) {
        if (s.length() != t.length()) return false;
        
        // Use arrays to store the last seen position + 1 of each char
        int m1[256] = {0};
        int m2[256] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            // Logic: If 'e' in 's' was last seen at index 5, 
            // then 'a' in 't' must also have been last seen at index 5.
            if (m1[s[i]] != m2[t[i]]) return false;
            
            // Store index + 1 (to distinguish from default 0)
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "Test 1: " << sol.isIsomorphicArray("egg", "add") << endl;    // true
    cout << "Test 2: " << sol.isIsomorphicArray("foo", "bar") << endl;    // false
    return 0;
}