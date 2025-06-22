#include <bits/stdc++.h>
using namespace std;
long long get_sum(long long start, long long element)
{
    // sum=(r-l+1)*(l+r)/2;
    long long sum = (element * start) + (element * (element - 1)) / 2;
    return sum;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}