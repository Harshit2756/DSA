#include <iostream>
#include <vector>
using namespace std;
class dynamicArray
{
    int *data;
    int nextIndex;
    int cappacity; // total size of the array

public:
    dynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        cappacity = 5;
    }

    void add(int element)
    {
        if (nextIndex == cappacity)
        {
            int *newData = new int[2 * cappacity];
            for (int i = 0; i < cappacity; i++)
            {
                newData[i] = data[i];
            }
            delete data;
            data = newData;
            cappacity *= cappacity;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
};

int main()
{

    int arr[10] = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    vector<int> a;

    return 0;
}


