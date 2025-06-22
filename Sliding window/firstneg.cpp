#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n), ans;
    for (auto &i : arr)
        cin >> i;

    queue<int> q;

    // Handle the first window
    for (int i = 0; i < k; i++)
        if (arr[i] < 0)
            q.push(i);

    // Push the result for the first window
    if (!q.empty())
        ans.push_back(arr[q.front()]);
    else
        ans.push_back(0);

    // Sliding the window from index k to n-1
    for (int i = k; i < n; i++)
    {
        // Remove the elements that are out of the current window
        if (!q.empty() && q.front() <= i - k)
            q.pop();

        // Add the new element if it's negative
        if (arr[i] < 0)
            q.push(i);

        // Store the result for this window
        if (!q.empty())
            ans.push_back(arr[q.front()]);
        else
            ans.push_back(0);
    }

    // Output the result
    for (auto &i : ans)
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