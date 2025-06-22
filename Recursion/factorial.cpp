#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n == 1 || n == 2)
        return n;

    return n * solve(n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve(29);
}