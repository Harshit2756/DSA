#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;

// Header Comment Block
// Problem: Reverse String.
// Constraint: In-place O(1) memory.

class Solution {
public:
    // ~ Approach: Two Pointers
    // Analysis: Time O(N) | Space O(1)
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        // - Step: Iterate until pointers meet
        while (left < right) {
            
            // - Logic: Swap values at pointers
            // Manual swap: char temp = s[left]; s[left] = s[right]; s[right] = temp;
            swap(s[left], s[right]);

            // - Step: Move pointers
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    sol.reverseString(s);
    
    cout << "Reversed: ";
    for(char c : s) cout << c << " ";
    cout << endl;

    return 0;
}