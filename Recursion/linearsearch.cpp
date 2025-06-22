#include <bits/stdc++.h>
using namespace std;
string solve(vector<int> &arr, int tar, int i)
{
    if (i >= arr.size())
        return "NO";

    if (arr[i] == tar)
        return "YES";

    return solve(arr, tar, i + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    int tar;
    cin >> tar;

    cout << solve(arr, tar, 0);
}