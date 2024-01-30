#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
    cout << "after partition" << endl;
    for (int i = l; i <= h; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// int iPartition(int arr[], int l, int h)
// {
//     int pivot = arr[h];
//     int i = l - 1;
//     for (int j = l; j <= h - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[h]);
//     // cout << "after partition" << endl;
//     // for (int i = l; i <= h; i++)
//     //     cout << arr[i] << " ";
//     // cout << endl;
//     return i + 1;
// }
void qSort(int arr[], int l, int h)
{
    if (l < h)
    {
        cout << "before partition" << endl;
        for (int i = l; i <= h; i++)
            cout << arr[i] << " ";
        cout << endl;
        int p = partition(arr, l, h);
        cout << "p=" << arr[p] << endl;
        qSort(arr, l, p);
        qSort(arr, p + 1, h);
    }
    else
    {
        cout << "array sorted" << endl;
        for (int i = 0; i <= 6; i++)
            cout << arr[i] << " ";
        cout << endl
             << "-------" << endl;
        for (int i = l; i <= h; i++)
            cout << arr[i] << " ";
        cout << endl
             << "-------" << endl;
    }
}

// void qSort(int arr[], int l, int h)
// {
//     if (l < h)
//     {
//         // cout << "before partition" << endl;
//         // for (int i = l; i <= h; i++)
//         //     cout << arr[i] << " ";
//         // cout << endl;
//         int p = iPartition(arr, l, h);
//         // cout << "p=" << arr[p] << endl;
//         qSort(arr, l, p - 1);
//         qSort(arr, p + 1, h);
//     }
//     // else
//     // {
//     //     cout << "array sorted" << endl;
//     // }
// }

int main()
{

    int arr[] = {8, 4, 7, 9, 3, 10, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    qSort(arr, 0, n - 1);

    for (int x : arr)
        cout << x << " ";
}