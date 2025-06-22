#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
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
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto e : adj[node])
            {
                if (!visited[e])
                {
                    visited[e] = 1;
                    q.push(e);
                }
            }
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