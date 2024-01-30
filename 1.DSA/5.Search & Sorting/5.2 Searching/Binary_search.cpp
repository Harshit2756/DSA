#include <iostream>
using namespace std;

int binarySearch(int *arr, int &n, int &key)
{
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid = ((start + end) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int binarySearchRecursive(int *arr, int start, int end, int key)
{

    if (start <= end)
    {
        return -1;
    }
    int mid = ((start + end) / 2);
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        binarySearchRecursive(arr, mid + 1, end, key);
    }
    else
    {
        binarySearchRecursive(arr, start, mid - 1, key);
    }
}

int main()
{
    int n, key;
    cin >> n >> key;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << binarySearch(arr, n, key);
    cout << binarySearchRecursive(arr, 0, n - 1, key);

    return 0;
}