#include <iostream>
using namespace std;

void swapAleternate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        if (i + 1 < size - 1)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int printArr(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    int odd[5] = {11, 33, 9, 76, 43};

    swapAleternate(even, 8);
    printArr(even, 8);

    swapAleternate(odd, 5);
    printArr(odd, 5);

    return 0;
}