#include <iostream>
using namespace std;

int SmallLargeSum(int array[], int n)
{
    if (n <= 3)
    {
        return 0;
    }
}

int main()
{

    int n = 7;
    int arr[7] = {4, 0, 7, 9, 6, 4, 2};
    

    cout << SmallLargeSum(arr, n);
    return 0;
}