#include <bits/stdc++.h>
using namespace std;
string solve(string str, int i, int n)
{
    if (i == n / 2)
        return "YES";

    if (str[i] != str[n - i - 1])
        return "NO";

    return solve(str, i + 1, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve("aaaaa", 0, 5);
}