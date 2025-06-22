#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int g = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return g;
}
bool ldp(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(a, b, x0, y0);
    if (c % g != 0)
        return false;

    x0 *= c / g;
    y0 *= c / g;

    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;

    return true;

    // For all solution
    //  ax0 + by0 = c;
    //  a (x0+b/g) + b (y0-a/g) =c;
    //  x=x0+(b/g)*k
    //  y=y0-(a/g)*k
    // k- 0 to INF
}
void solve()
{
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