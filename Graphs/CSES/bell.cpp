#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
typedef pair<int, int> P;
void dijkstr(int src, int n, vector<vector<P>> &edges, vector<int> &dist)
{
    fill(dist.begin(), dist.end(), LLONG_MAX);
    dist[src] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, src});
    vector<int> parent(n, -1);

    while (!pq.empty())
    {
        int popnode = pq.top().second;
        int distsofar = pq.top().first;

        if (distsofar != dist[popnode])
            continue;

        for (auto e : edges[popnode])
        {
            int node = e.first;
            int disadd = e.second;

            if (dist[node] > distsofar + disadd)
            {
                dist[node] = distsofar + disadd;
                pq.push({dist[node], node});
                parent[node] = popnode;
            }
        }
    }
}
void solve()
{
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