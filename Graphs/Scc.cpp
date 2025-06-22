#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
stack<int> st;
vector<int> temp;
vector<vector<int>> scc;
void dfs(int node, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;

    for (auto e : adj[node])
    {
        if (visited[e] == 0)
        {
            dfs(e, visited, adj);
        }
    }

    st.push(node);
}
void sccdfs(int node, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    temp.push_back(node);

    for (auto e : adj[node])
    {
        if (visited[e] == 0)
        {
            dfs(e, visited, adj);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], tadj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        tadj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, adj);
        }
    }

    fill(visited.begin(), visited.end(), 0);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (visited[node] == 0)
        {
            sccdfs(node, visited, adj);
            scc.push_back(temp);
            temp.clear();
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