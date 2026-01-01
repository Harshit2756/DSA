#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // ~ Approach: Two Pointers (Optimal)
    // Analysis: Time O(N) | Space O(1)
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // - Logic: Compare ends
            if (s[left] != s[right]) {
                return false;
            }
            // - Step: Move inward
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    string s1 = "hannah";
    string s2 = "aabbaaa";

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1: " << sol.isPalindrome(s1) << endl;
    cout << "Test 2: " << sol.isPalindrome(s2) << endl;

    return 0;
}