#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[node] = true;
    cout << node << " ";

    for (auto e : adj[node])
    {
        if (e == parent)
            continue;

        if (!visited[e])
        {
            dfs(e, adj, visited, node);
        }
        else
        {
            cout << "\nCycle Present:";
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

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, -1);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
