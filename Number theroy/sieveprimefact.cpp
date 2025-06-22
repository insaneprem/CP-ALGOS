#include <bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> spf(105);
    for (int i = 0; i < 105; i++)
        spf[i] = i;

    for (int i = 2; i * i <= 100; i++)
    {
        if (spf[i] != i)
            continue;
        for (int j = i * i; j <= 100; j += i)
        {
            if (spf[j] == j)
            {
                spf[j] = i;
            }
        }
    }

    for (int i = 2; i <= 100; i++)
        cout << i << " -> " << spf[i] << "\n";

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        while (n != 1)
        {
            cout << spf[n] << " ";
            n = n / spf[n];
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}