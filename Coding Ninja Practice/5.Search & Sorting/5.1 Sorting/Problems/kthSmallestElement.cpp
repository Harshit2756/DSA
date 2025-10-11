#include <bits/stdc++.h>
using namespace std;
//  naive sol
int kthSmallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return k - 1;
}

// optimised
int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int kthSmallestp(int arr[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = partition(arr, l, r);
        if (p == k - 1)
            return p;
        else if (p > k - 1)
            r = p - 1;
        else
            l = p + 1;
    }
    return -1;
}

int main()
{

    int a[] = {10, 4, 5, 8, 11, 6, 26};
    int b[] = {10, 4, 5, 8, 11, 6, 26};

    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;

    int index = kthSmallest(a, n, k);
    int indexp = kthSmallestp(b, n, k);

    cout << a[index] << endl;
    cout << b[indexp] << endl;
}
