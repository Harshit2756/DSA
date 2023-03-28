/*You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
 Note:
Change in the input array/list itself. You don't need to return or print the elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.
Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
void rotate(int *input, int d, int n)
{	//copying starting elements in new arry
    int arr[d];
 	for(int k=0;k<d;k++){
        arr[k]=input[k];
    }
    
    //shifting the reaming elements
    int i=0;
    for(int j=d;j<n && i<n-d;j++,i++){
        
       input[i]=input[j]; 
    }
    
	//pasting starting elements in the last
    for(int x=0;i<n;x++,i++){
        input[i]=arr[x];
    }
}