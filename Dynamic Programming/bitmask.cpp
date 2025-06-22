#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void solve()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = 4;
    int p = 1 << n;

    vector<int> dp(p, 0);

    for (int mask = 0; mask < p; mask++)
    {
        for (int bit = 0; bit < n; bit++)
        {
            if ((mask >> bit) & 1)
                dp[mask] += arr[bit];
        }
    }

    for (int mask = 1; mask < p; mask++)
    {
        dp[mask] = dp[mask & (mask - 1)] + arr[__builtin_ctz(mask)];
    }
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
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}