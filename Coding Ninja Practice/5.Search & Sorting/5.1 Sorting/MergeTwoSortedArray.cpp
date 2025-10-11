#include <iostream>
using namespace std;
void merge(int a[], int b[], int n, int m)
{
    int ab[m + n];
    for (int i = 0; i < m; i++)
    {
        ab[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ab[m + i] = b[i];
    }

    sort(ab, ab + m + n);
}
void mergeOptimised(int a[], int b[], int n, int m)
{
    int ab[m + n];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= B[j])
        {
            ab[k] = a[i];
            i++;
            k++;
        }
        else
        {
            ab[k] = b[j];
            j++;
            k++;
        }
    }

    while (j < m)
    {
        ab[k] = b[j];
        k++;
        j++;
    }

    while (i < n)
    {
        ab[k] = a[i];
        k++;
        i++;
    }
}

int main()
{

    int a;

    return 0;
}