#include <bits/stdc++.h>
using namespace std;
void solve(int i, int n)
{
    if (i > n)
        return;

    solve(i + 1, n);
    cout << i << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1, 10);
}