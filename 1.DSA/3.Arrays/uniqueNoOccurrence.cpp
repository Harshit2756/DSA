
#include <iostream>
using namespace std;

//Brutforce
void uniqueOccurrence(int *arr,int size)
{
    int temp[size];
    int count;
    for (int i = 0; i < size - 1; i++)
    {
        count = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        temp[i] = count;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }
        cout << findUnique(input, size) << endl;
    }
    return 0;
}