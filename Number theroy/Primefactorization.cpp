#include <bits/stdc++.h>
using namespace std;
void fact(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << n << endl;
            n = n / i;
        }
    }
    if (n != 1)
        cout << n;
}
int main()
{
    fact(12);
}