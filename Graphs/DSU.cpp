#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
typedef pair<int, int> P;
class DSU
{
   vector<int> parent, size, rank;

public:
   DSU(int n)
   {
      for (int i = 0; i <= n; i++)
      {
         parent.push_back(i);
         size.push_back(1);
         rank.push_back(0);
      }
   }

   int findpar(int node)
   {
      if (parent[node] == node)
         return node;

      return parent[node] = (parent[node]);
   }

   void unionSize(int u, int v)
   {
      int pu = findpar(u);
      int pv = findpar(v);

      if (pu == pv)
         return;

      if (size[pu] < size[pv])
      {
         parent[pu] = pv;
         size[pv] += pu;
      }
      else
      {
         parent[pv] = pu;
         size[pu] += pv;
      }
   }

   void unionRank(int u, int v)
   {
      int pu = findpar(u);
      int pv = findpar(v);

      if (pu == pv)
         return;

      if (rank[pu] == rank[pv])
      {
         rank[pu]++;
         parent[pv] = pu;
      }
      else if (rank[pu] < rank[pv])
         parent[pu] = pv;
      else
         parent[pv] = pu;
   }
};
void solve()
{
   int n, m;
   cin >> n >> m;

   vector<pair<int, P>> adj;

   for (int i = 0; i < m; i++)
   {
      int u, v, wt;
      cin >> u >> v >> wt;

      adj.push_back({wt, {u, v}});
   }

   sort(adj.begin(), adj.end());
   DSU dsu(n);
   int sum = 0;
   for (auto it : adj)
   {
      int u = it.second.first;
      int v = it.second.second;
      int wt = it.first;

      if (dsu.findpar(u) == dsu.findpar(v))
         continue;

      sum += wt;
      dsu.unionRank(u, v);
   }

   cout << sum;
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