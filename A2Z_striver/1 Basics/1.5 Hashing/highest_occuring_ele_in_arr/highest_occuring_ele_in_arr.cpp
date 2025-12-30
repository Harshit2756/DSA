#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <unordered_map>



using namespace std;



// Header Comment Block

// Problem: Find the most frequent element (Smallest on tie).

// Approaches: Brute Force, Sorting, Hashing.



class Solution {

public:

    // ~ Approach 1: Brute Force (Nested Loops)

    // Analysis: Time O(N^2) | Space O(1)

    int mostFrequentBrute(vector<int>& arr) {

        int n = arr.size();

        int maxFreq = 0;

        int result = -1;



        for (int i = 0; i < n; i++) {

            int currentFreq = 0;

            

            // - Step 1: Count occurrences of arr[i]

            for (int j = 0; j < n; j++) {

                if (arr[j] == arr[i]) {

                    currentFreq++;

                }

            }



            // - Step 2: Update Max

            // - Logic: If freq is greater, update. If equal, pick smaller value.

            if (currentFreq > maxFreq) {

                maxFreq = currentFreq;

                result = arr[i];

            } else if (currentFreq == maxFreq) {

                result = min(result, arr[i]);

            }

        }

        return result;

    }



    // ~ Approach 2: Sorting (Linear Scan)

    // Analysis: Time O(N log N) | Space O(1) (ignoring recursion stack)

    // Logic: Once sorted (10, 10, 20, 20, 30), duplicates are neighbors.

    int mostFrequentSorting(vector<int>& arr) {

        if (arr.empty()) return -1;

        

        // - Step 1: Sort the array

        sort(arr.begin(), arr.end());



        int maxFreq = 0;

        int result = arr[0];

        

        int currentFreq = 1;

        

        // - Step 2: Single Pass

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] == arr[i - 1]) {

                currentFreq++;

            } else {

                // Sequence broke. Reset.

                currentFreq = 1;

            }



            // - Step 3: Check against max

            // - Logic: Since array is sorted, we process smaller numbers first.

            //   So if we find a tie, we don't update (keeping the smaller/earlier one).

            if (currentFreq > maxFreq) {

                maxFreq = currentFreq;

                result = arr[i];

            }

        }

        return result;

    }



    // ~ Approach 3: Hashing (Optimal)

    // Analysis: Time O(N) | Space O(N)

    int mostFrequentHashing(vector<int>& arr) {

        unordered_map<int, int> freqMap;

        

        // - Step 1: Populate Map

        for (int x : arr) freqMap[x]++;



        int maxFreq = 0;

        int result = -1;



        // - Step 2: Iterate Map

        for (auto it : freqMap) {

            int num = it.first;

            int count = it.second;



            if (count > maxFreq) {

                maxFreq = count;

                result = num;

            } 

            // - Logic: Explicit tie-breaker for unordered data

            else if (count == maxFreq) {

                result = min(result, num);

            }

        }

        return result;

    }

};



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    Solution sol;

    vector<int> arr = {30, 10, 20, 20, 30, 10, 20, 10}; 

    // 10 appears 3x, 20 appears 3x. 10 is smaller. Result should be 10.



    cout << "1. Brute Force: " << sol.mostFrequentBrute(arr) << endl;

    

    // Note: Sorting modifies the array order

    cout << "2. Sorting:     " << sol.mostFrequentSorting(arr) << endl;

    

    cout << "3. Hashing:     " << sol.mostFrequentHashing(arr) << endl;



    return 0;

}