#include <iostream>
using namespace std;
/*

merge_sort([38, 27, 43, 3, 9, 82, 10, 1]) [0 - 7]
   |
   +--- merge_sort([38, 27, 43, 3]) [0 - 3]
   |      |
   |      +--- merge_sort([38, 27]) [0 - 1]
   |      |      |
   |      |      +--- merge_sort([38]) [0 - 0]
   |      |      |      return [38]  # Returned a sorted subarray
   |      |      |
   |      |      +--- merge_sort([27]) [1 - 1]
   |      |      |      return [27]  # Returned a sorted subarray
   |      |      |
   |      |      merge([38], [27])    # Merging two sorted subarrays
   |      |      return [27, 38]      # Returned a sorted subarray
   |      |
   |      +--- merge_sort([43, 3]) [2 - 3]
   |      |      |
   |      |      +--- merge_sort([43]) [2 - 2]
   |      |      |      return [43]  # Returned a sorted subarray
   |      |      |
   |      |      +--- merge_sort([3]) [3 - 3]
   |      |      |     return [3]  # Returned a sorted subarray
   |      |      |
   |      |     merge([43], [3])    # Merging two sorted subarrays
   |      |      return [3, 43]  # Returned a sorted subarray
   |      |
   |     merge( [27, 38] ,[3, 43] )    # Merging two sorted subarrays
   |      return [3, 27, 38, 43]       # Returned a sorted subarray
   |
   +--- merge_sort([9, 82, 10, 1]) [4 - 7]
   |     |
   |     +--- merge_sort([9, 82]) [4 - 5]
   |     |      |
   |     |      +--- merge_sort([9]) [4 - 4]
   |     |      |      return [9]  # Returned a sorted subarray
   |     |      |
   |     |      +--- merge_sort([82]) [5 - 5]
   |     |      |      return [82]  # Returned a sorted subarray
   |     |      |
   |     |      merge([9], [82])    # Merging two sorted subarrays
   |     |       return [9, 82]       # Returned a sorted subarray
   |     |
   |     +--- merge_sort([10, 1]) [6 - 7]
   |     |     |
   |     |     +--- merge_sort([10]) [6 - 6]
   |     |     |      return [10]  # Returned a sorted subarray
   |     |     |
   |     |     +--- merge_sort([1]) [7 - 7]
   |     |     |      return [1]  # Returned a sorted subarray
   |     |     |
   |     |     merge([10], [1])    # Merging two sorted subarrays
   |     |      return [1, 10]       # Returned a sorted subarray
   |     |
   |     merge([1, 10] , [9, 82])    # Merging two sorted subarrays
   |      return [1, 9, 10, 82]       # Returned a sorted subarray
   |
   merge([3, 27, 38, 43]  , [1, 9, 10, 82])    # Merging two sorted subarrays
    return [1, 3, 9, 10, 27, 38, 43, 82]       # Returned a sorted subarray

*/

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; ++i)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
