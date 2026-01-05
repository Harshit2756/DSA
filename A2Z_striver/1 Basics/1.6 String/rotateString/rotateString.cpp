#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // ~ Approach 1: Concatenation (The Interview Winner)
    // Analysis: Time O(N) | Space O(N)
    bool rotateStringSimple(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        string doubled = s + s;
        // string::npos means "not found"
        return doubled.find(goal) != string::npos;
    }


    // ~ Approach 2: Brute Force Simulation
    // Analysis: Time O(N^2) | Space O(N)
    bool rotateStringSimulation(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // Rotate: append first char to end, take substring from 1
            s = s.substr(1) + s[0];
            if (s == goal) return true;
        }
        return false;
    }


    // ~ Approach 3: KMP Algorithm
    // Analysis: Time O(N) | Space O(N)
    bool rotateStringKMP(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string text = s + s;
        return kmpSearch(text, goal);
    }

private:
    vector<int> computeLPS(string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else { lps[i] = 0; i++; }
            }
        }
        return lps;
    }

    bool kmpSearch(string& text, string& pattern) {
        int n = text.length();
        int m = pattern.length();
        if (m == 0) return true;
        
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) { i++; j++; }
            
            if (j == m) return true;
            else if (i < n && pattern[j] != text[i]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "abcde"; 
    string goal = "cdeab";

    cout << "Concatenation: " << sol.rotateStringSimple(s, goal) << endl;
    cout << "Simulation:    " << sol.rotateStringSimulation(s, goal) << endl;
    cout << "KMP:           " << sol.rotateStringKMP(s, goal) << endl;
    return 0;
}