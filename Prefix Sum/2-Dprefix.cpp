#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr[n + 1][m + 1];
    int p[n + 1][m + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            p[i][j] = arr[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << p[c][d] - p[a - 1][d] - p[b - 1][c] + p[a - 1][b - 1] << endl;
    }
}