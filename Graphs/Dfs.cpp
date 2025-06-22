#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;
    cout << node << " ";

    for (auto e : adj[node])
    {
        if (!visited[e])
        {
            dfs(e, adj, visited);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, 0);
    dfs(1, adj, visited);
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