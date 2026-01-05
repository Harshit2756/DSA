#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        int end = -1;

        // Step 1: Find right-most odd digit
        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 != 0) {
                end = i;
                break;
            }
        }

        if (end == -1) return "";

        // Step 2: Skip leading zeros
        int start = 0;
        while (start < end && s[start] == '0') {
            start++;
        }

        // Step 3: Return substring
        // s.substr(start_index, length)
        // s.substr(start, length)
        // length = end - start + 1
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;
    cout << "Test: " << sol.largestOddNumber("0052") << endl; // Output: 5
    cout << "Test: " << sol.largestOddNumber("0010070") << endl; // Output: 1007
    return 0;
}