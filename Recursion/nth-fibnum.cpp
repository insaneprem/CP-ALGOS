#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if (n <= 1)
        return n;

    return solve(n - 1) + solve(n - 2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve(4);
}