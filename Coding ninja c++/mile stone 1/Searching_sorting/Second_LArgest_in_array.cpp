/*Second Largest in array
Send Feedback
You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the array/list.

The second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the second largest in the array/list if exists, -2147483648 otherwise.

Output for every test case will be printed in a separate line.*/

#include <iostream>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}

#include <limits.h>
int findSecondLargest(int *input, int n)
{
    int max=INT_MIN;
    int second_max=INT_MIN;
    
    for(int i=0;i<n;i++){
        if(input[i]>max){
            second_max=max;
            max=input[i];
        }else if(input[i]>second_max && input[i]!=max ){
            second_max=input[i];
        }
    }
    return second_max;
}
