#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
typedef pair<int, int> P;
void dijkstr(int src, int n, vector<vector<P>> &edges, vector<int> &dist)
{
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    vector<bool> visited(n, 0);
    set<P> toexplore;
    toexplore.insert({0, src});

    while (!toexplore.empty())
    {
        auto top = *toexplore.begin();
        toexplore.erase(toexplore.begin());

        int popnode = top.second;
        int distsofar = top.first;

        visited[popnode] = 1;

        for (auto e : edges[popnode])
        {
            int node = e.second;
            int adddist = e.first;

            if (visited[node])
                continue;

            if (dist[node] > distsofar + adddist)
            {
                toexplore.erase({dist[node], node});
                dist[node] = distsofar + adddist;
                toexplore.insert({dist[node], node});
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