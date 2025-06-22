#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
map<int, pair<int, int>> mpp;
// node {in_time,out_time};
int t = 0;
void dfs(int node, int parent, vector<int> adj[], vector<int> &level, int l = 0)
{
    mpp[node].first = t;
    t++;
    level[node] = l;
    cout << node << " ";

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node, adj, level, l + 1);
    }

    mpp[node].second = t;
    t++;
}
void bfs(int root, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({root, 0});
    int level = 0;
    while (!q.empty())
    {
        int k = q.size();

        for (int i = 0; i < k; i++)
        {
            int node = q.front().first;
            cout << node << " ";
            int parent = q.front().second;

            q.pop();

            for (auto child : adj[node])
            {
                if (child == parent)
                    continue;
                q.push({child, node});
            }
            level++;
        }
        cout << level;
    }
}
void bindfs(int node, int parent, vector<int> adj[], vector<vector<int>> &dp)
{
    dp[node][0] = parent;

    for (int i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        bindfs(child, node, adj, dp);
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

    //    vector<int> level(n+1);
    //    dfs(1,0,adj,level);
    //    bfs(1,adj);

    vector<vector<int>> dp(n + 1, vector<int>(17, 0));
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
    // cin>>t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}