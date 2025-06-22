#include <bits/stdc++.h>
using namespace std;
#define int long long
int ternary_search(double x)
{
    // helps to find maxima and minima
    auto f = [](double x) -> double {

    };

    const double EPS = 1e-9;
    // Inc then dec

    double l = 0, r = 1e9;
    while (r - l > EPS)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        (f(m1) < f(m2)) ? l = m1 : r = m2;
    }
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}