#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    // //Sum
    // int sum_of_N_2 = ((size - 1) * (size - 2)) / 2;
    // int sum = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     sum += arr[i];
    // }
    // int val = (sum - sum_of_N_2);
    // return val;

    // 2 iterrator approach
    //  for (int i = 0; i < size; i++)
    //  {
    //      int j = 0;
    //      for (; j < size; j++)
    //      {
    //          if (i != j && arr[i] == arr[j])
    //          {
    //              return arr[i];
    //          }
    //      }
    //  }

    // Optimal Using XOR
    int ans = 0;

    // XOR ing all array elements1
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
        cout << ans << " ";
    }
    cout << endl;

    // XOR [1, n-1]
    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
        cout << ans << " ";
    }
    cout << endl;

    return ans;
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << duplicateNumber(input, size) << endl;
    }

    return 0;
}