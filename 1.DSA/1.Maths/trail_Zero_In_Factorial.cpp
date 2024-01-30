    #include <iostream>
    using namespace std;

    // brutforce
    // int trail_zero(int n)
    // {
    //     int fact = 1;
    //     for (int i = 1; i < n; i++)
    //     {
    //         fact = fact * i;
    //     }
    //     int count = 0;
    //     while (fact % 10 == 0)
    //     {
    //         fact /= 10;
    //         count++;
    //     }
    //     return count;
    // }

    // Optimal

    int trail_zero(int n){

        int count = 0;
        for (int i = 5; i <= n; i*=5)
        {
            count += (n / i);
        }
        return count;
    }
    int main(){

        int n = 251;
        cout << trail_zero(n);

        return 0;
    }