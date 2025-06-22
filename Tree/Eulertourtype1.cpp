#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
// genrate level for each node then run segment tree query
vector<int> flat;
map<int, int> mpp; // first occurance of every node in flat vector
int idx = 0;
void dfs(int node, int parent, vector<int> adj[])
{
    if (mpp.find(node) == mpp.end())
        mpp[node] = idx;
    flat.push_back(node);
    idx++;

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, adj);
        flat.push_back(node);
        idx++;
    }
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