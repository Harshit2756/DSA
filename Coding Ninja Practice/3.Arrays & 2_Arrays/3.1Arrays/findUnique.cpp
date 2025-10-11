/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.*/

#include <iostream>
using namespace std;
// //Optimised
// int findUnique(int *arr, int size)
// {
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }

// Brutforce
int findUnique(int *arr, int size)
{
    for (int i = 0; i <= size; i++)
    {
        bool isunique = true;
        for (int j = 0; j <= size; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                isunique = false;
            }
        }
        if (isunique)
        {
            return arr[i];
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }
        cout << findUnique(input, size) << endl;
    }
    return 0;
}



