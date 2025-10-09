#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], int parent, vector<int> &level, vector<vector<int>> &dp, int l = 0)
{
    dp[node][0] = parent;
    level[node] = l;

    for (int i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, adj, node, level, dp, l + 1);
    }
}
int getkthpar(int node, int k, vector<vector<int>> &dp)
{
    int cnt = 0;
    while (k)
    {
        if (k & 1)
        {
            node = dp[node][cnt];
        }
        cnt++;
        k = k >> 1;
    }

    return node;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(17));
    vector<int> level(n + 1, 0);
    dfs(1, adj, 0, level, dp);

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (level[a] > level[b])
            swap(a, b);

        int k = level[b] - level[a];
        if (a == b)
        {
            cout << a << " ";
            continue;
        }

        b = getkthpar(b, k, dp);

        for (int i = 16; i >= 0; i--)
        {
            if (dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << " ";
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