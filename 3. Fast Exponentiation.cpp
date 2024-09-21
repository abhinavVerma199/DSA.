#include <iostream>

using namespace std;

int fastExponentiation(int x, int n)
{
    long long int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // n is odd.
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        n >>= 1;
    }
    return ans % M;
}

int slowExponentiation(int a, int b)
{
    int ans = 1;
    while (b--)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    int a = 5;
    int b = 4;

    cout << slowExponentiation(a, b) << endl;
    cout << fastExponentiation(a, b) << endl;
    return 0;
}