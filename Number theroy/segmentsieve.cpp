#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void solve()
{
    vector<int> sieve(1e5 + 7, 1);

    for (int i = 2; i * i <= 1e5; i++)
    {
        if (sieve[i] == 0)
            continue;
        for (int j = i * i; j <= 1e5; j += i)
        {
            sieve[j] = 0;
        }
    }

    int l, r;
    cin >> l >> r;

    int size = r - l + 1;
    int dummy[size];

    for (int i = 0; i < size; i++)
        dummy[i] = 1;

    for (int i = 2; i * i <= r; i++)
    {
        if (sieve[i] == 1)
        {
            int initial = (l / i) * i;
            if (initial < l)
            {
                initial += i;
            }
            initial = max(i * i, initial);
            for (int j = initial - l; j < size; j += i)
            {
                dummy[j] = 0;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < size; i++)
        if (dummy[i])
            cnt++;

    cout << cnt << " ";
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t=1;
    while (t--)
        solve();
}