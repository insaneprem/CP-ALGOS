#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &parent)
{
    visited[node] = 1;
    cout << node << " ";

    for (auto e : adj[node])
    {
        if (!visited[e])
        {
            parent[e] = node;
            dfs(e, adj, visited, parent);
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
    vector<int> parent(n + 1, -1);
    int start, end;
    cin >> start >> end;

    dfs(start, adj, visited, parent);

    if (parent[end] == -1)
    {
        cout << "NO Path";
    }
    else
    {
        int curr = end;
        while (curr != -1)
        {
            cout << curr << " ";
            curr = parent[curr];
        }
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