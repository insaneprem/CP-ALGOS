#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int N = 1e5;
bitset<N> mask[26];
void computeMask(string text)
{
    for (int i = 0; i < text.size(); i++)
    {
        int c = text[i] - 'a';
        mask[c].set(i);
    }
}
void solve()
{
    string str, pat;
    cin >> str >> pat;

    computeMask(str);

    if (str.size() < pat.size())
    {
        cout << 0;
        return;
    }

    bitset<N> startmask;
    startmask.set();

    for (int i = 0; i < pat.size(); i++)
    {
        int c = pat[i] - 'a';
        startmask &= (mask[c] >> i);
    }

    cout << (startmask.count()) << "\n";
    string s = startmask.to_string();
    cout << s.substr(s.size() - 15);
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
    while (t--)
    {
        solve();
        cout << "\n";
    }
}