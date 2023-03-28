/*You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.
Output Format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}

void sort012(int *arr, int n)
{	int zero=0;
 	int two = n-1;
	int i=0;	
 	while(i<=two){
    	if(arr[i]==0){
            swap(arr[i],arr[zero]);
            zero++;
            i++;
        }else if(arr[i]==2){
            swap(arr[i],arr[two]);
            two--;
        }else if(arr[i]==1){
            i++;
        }
    }
    
    /*int zero = 0;
    int two = n - 1;
    int i = 0;
 
    // Iterate till all the elements
    // are sorted
    while (i <= two) {
        switch (arr[i]) {
 
        // If the element is 0
        case 0:
            swap(arr[zero++], arr[i++]);
            break;
 
        // If the element is 1 .
        case 1:
            i++;
            break;
 
        // If the element is 2
        case 2:
            swap(arr[i], arr[two--]);
            break;
        }
    }*/
}