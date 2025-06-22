#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Just l->+val r+1->-val for prefix sum
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int arr[n + 2] = {0};

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        arr[l] += k;
        arr[r + 1] -= k;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    cout << endl;
}