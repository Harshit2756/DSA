/*You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.*/

#include <iostream>
using namespace std;


int duplicateNumber(int *arr, int size)
{	
    int sum_of_N_2=((size-1)*(size-2))/2;
    int sum =0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int val =(sum - sum_of_N_2);
    return val;
    
    
    /*for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                continue;
            }
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }*/
    
    
    /*for(int i=0;i<size;i++){
        int j=0;
        for(;j<size;j++){
            if(i!=j && arr[i]==arr[j] ){
                return arr[i];
            }
        }
    }*/
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << duplicateNumber(input, size) << endl;
	}

	return 0;
}