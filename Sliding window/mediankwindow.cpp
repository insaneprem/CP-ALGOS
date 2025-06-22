#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; // less_equal(multiset )
#define int long long
#define ld long double
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n), ans;
    for (auto &i : arr)
        cin >> i;

    pbds A;
    for (int i = 0; i < k; i++)
        A.insert({arr[i], i});
    ans.push_back((*A.find_by_order(k / 2)).first);

    for (int i = 1; i <= n - k; i++)
    {
        A.insert({arr[i + k - 1], i + k - 1});
        A.erase({arr[i - 1], i - 1});
        ans.push_back((*A.find_by_order(k / 2)).first);
    }

    for (auto i : ans)
        cout << i << " ";
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;
    while (t--)
        solve();
}