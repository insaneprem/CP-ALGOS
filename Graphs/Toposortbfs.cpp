#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &indegree, vector<int> &topo)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        topo.push_back(x);

        for (auto e : adj[x])
        {
            indegree[e]--;
            if (indegree[e] == 0)
            {
                q.push(e);
                visited[e] = 1;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], indegree(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> visited(n + 1, 0);
    vector<int> topo;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0 && visited[i] == 0)
        {
            dfs(i, adj, visited, indegree, topo);
        }
    }

    for (auto i : topo)
        cout << i << " ";
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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