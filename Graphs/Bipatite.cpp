#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], vector<int> &color)
{
    for (auto e : adj[node])
    {
        if (color[e] == 0)
        {
            color[e] = color[node] == 1 ? 2 : 1;
            dfs(e, adj, color);
        }
        else if (color[e] == color[node])
        {
            cout << "NOT BIPITITE" << " ";
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //    vector<bool> visited(n+1,0);
    vector<int> color(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            color[i] = 1;
            dfs(i, adj, color);
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