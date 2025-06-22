#include <bits/stdc++.h>
using namespace std;
// log n
int power(int a, int b)
{
    if (b == 0)
        return 1;

    int half_pow = power(a, b / 2);

    if (b % 2 == 0)
        return half_pow * half_pow;
    else
        return half_pow * half_pow * a;
}
int main()
{
    cout << power(2, 3);
}