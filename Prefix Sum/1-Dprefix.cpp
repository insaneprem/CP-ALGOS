#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Use :Sum of Range{l,R};

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n + 1] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i - 1] + arr[i];
    }

    cout << arr[3];
}