#include <iostream>
#include <algorithm>
using namespace std;

// O(nm) naive
void intersection(int a[], int b[], int m, int n)
{
    //. traversing the first array(not necc to be the largest length)
    for (int i = 0; i < m; i++)
    {
        //. since array is sorted the comparing if the element is same or not.
        if (i > 0 && a[i - 1] == a[i])
            continue;
        //. travesing 2nd array and checking for same values from the 1st arrray
        for (int j = 0; j < n; j++)
            if (a[i] == b[j])
            {
                cout << a[i] << " ";
                break;
            }
    }
}
// Optimal O(max(m*log(m), n*log(n)) + min(m, n) )
void intersectionop(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        if (a[i] > b[j])
        {
            j++;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{

    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    intersection(a, b, m, n);
    cout << "---------------\n";
    intersectionop(a, b, m, n);
}