/*You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.

Output for every test case will be printed in a separate line.*/

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size1;
		cin >> size1;

		int *arr1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> arr1[i];
		}

		int size2;
		cin >> size2;

		int *arr2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> arr2[i];
		}

		int *ans = new int[size1 + size2];

		merge(arr1, size1, arr2, size2, ans);

		for (int i = 0; i < size1 + size2; i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
		delete[] arr1;
		delete[] arr2;
		delete[] ans;
	}
}

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{	int i=0,j=0,count=0;
    while(i<size1&&j<size2){
        if(arr1[i]<arr2[j]){
            ans[count]=arr1[i];
            i++;
        }else if(arr1[i]>arr2[j]){
            ans[count]=arr2[j];
            j++;
        }else{
            ans[count]=arr2[j];
            count++;
            ans[count]=arr1[i];
            j++;
            i++;
        }
        count++;
    } 
 	if(j==size2){
        while(i<size1){
            ans[count]=arr1[i];
            count++;
            i++;
        }      
    }else if(i==size1){
        while(j<size2){
            ans[count]=arr2[j];
            count++;
            j++;
        }
    }
}