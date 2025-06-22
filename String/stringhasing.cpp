#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long get_hash(string str)
{
    long long h = 0;

    for (auto ch : str)
    {
        h = (h * 31 + (ch - 'a' + 1)) % MOD;
        cout << h << " ";
    }

    return h;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << get_hash("kabc");
    // cout<<fixed<<setprecision(10);
    // cout<<1e9+7;
}