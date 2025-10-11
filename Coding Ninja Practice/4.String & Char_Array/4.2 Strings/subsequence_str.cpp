#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string small_output = input.substr(1);
    int small_output_size = subs(small_output, output);
    for (int i = 0; i < small_output_size; i++)
    {
        output[i + small_output_size] = input[0] + output[i];
    }

    return 2 * small_output_size;
}

int main()
{

    string input;
    cin >> input;
    int n = input.size();
    int no_of_substr = pow(2, n);
    string *output = new string[no_of_substr];
    int count = subs(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}
