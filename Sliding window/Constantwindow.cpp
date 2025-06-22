#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;

    vector<int> arr(n);

    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    maxi = max(maxi, sum);

    for (int i = k; i < n; i++)
    {
        int add_index = i;
        int remove_index = i - k;
        sum = sum + arr[add_index] - arr[remove_index];
        maxi = max(maxi, sum);
    }

    cout << maxi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}