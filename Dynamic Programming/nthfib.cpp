#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int x = 0;
int fib(int n)
{
    x++;
    if (n == 1 || n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}
void solve()
{
    cout << fib(50) << " ";
    cout << x;
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    // t=1;
    while (t--)
        solve();
}