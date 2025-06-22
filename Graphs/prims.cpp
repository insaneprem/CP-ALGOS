#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
typedef pair<int, int> P;
typedef pair<int, P> T;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<P> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<bool> visited(n + 1, 0);
    vector<P> mst;
    int mstcost = 0;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, {1, -1}});

    while (!pq.empty())
    {
        int popnode = pq.top().second.first;
        int parent = pq.top().second.second;
        int wt = pq.top().first;

        pq.pop();

        if (visited[popnode] == 1)
            continue;
        visited[popnode] = 1;

        if (parent != -1)
            mst.push_back({popnode, parent});
        mstcost += wt;

        for (auto e : adj[popnode])
        {
            if (!visited[e.first])
            {
                pq.push({e.second, {e.first, popnode}});
            }
        }
    }

    cout << mstcost << '\n';
    for (auto e : mst)
        cout << e.first << " " << e.second << " ";
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