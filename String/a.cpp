#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long get_hash(string str)
{
    long long ans = 0;
    for (auto i : str)
        ans = ans * 31 + (i - 'a' + 1);
    return ans;
}
vector<int> solve(string str, string pat)
{
    vector<int> ans;
    int n = str.size(), m = pat.size();

    long long hs = get_hash(str.substr(0, m));
    long long hp = get_hash(pat);

    if (hs == hp)
        ans.push_back(0);

    long long p = 1;
    for (int i = 0; i < m - 1; i++)
        p = (p * 31) % mod;

    for (int l = 1, r = m; r < n; l++, r++)
    {
        int del = ((str[l - 1] - 'a' + 1) * p) % mod;
        int add = str[r] - 'a' + 1;
        hs = ((hs - del + mod) * 31 + add) % mod;

        if (hs == hp)
            ans.push_back(l);
    }
    return ans;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans = solve("bcdabab", "ab");
    for (auto i : ans)
        cout << i << " ";
}