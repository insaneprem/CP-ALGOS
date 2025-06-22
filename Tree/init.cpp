#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
map<int, pair<int, int>> mpp;
// label->{in_time,out_time}
int t = 0;
void dfs(int node, vector<int> adj[], int parent, vector<int> &level, int l = 0)
{
    mpp[node].first = t;
    t++;

    level[node] = l;
    cout << node << " ";

    for (auto child : adj[node])
    {
        if (parent == child)
            continue;
        dfs(child, adj, parent, level, l + 1);
    }

    mpp[node].second = t;
    t++;
}

void bfs(int root, vector<int> adj[])
{
    queue<pair<int, int>> q;
    // {child,parent}

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
        }
        level++;
    }
}
void dp_on_trees(int node, vector<int> adj[], int parent, vector<int> &dp)
{
    dp[node] = 1;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dp_on_trees(child, adj, node, dp);
        dp[node] += dp[child];
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    // for (int i = 0; i < n - 1; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;

    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    for (int i = 0; i < n - 1; i++)
    {
        int u;
        cin >> u;

        adj[i + 2].push_back(u);
        adj[u].push_back(i + 2);
    }
    vector<int> level;
    // dfs(1, adj, 0, level);
    vector<int> dp(n + 1);
    dp_on_trees(1, adj, 0, dp);
    for (int i = 1; i <= n; i++)
        cout << dp[i] - 1 << " ";
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