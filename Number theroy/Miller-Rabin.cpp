#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(const string &t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }

template <class T, class V> void _print(const pair<T, V> &p);
template <class T> void _print(const vector<T> &v);
template <class T> void _print(const vector<vector<T>> &v);
template <class T> void _print(const set<T> &v);
template <class T> void _print(const multiset<T> &v);
template <class T, class V> void _print(const map<T, V> &v);
template <typename... Args> void _print(const tuple<Args...> &t);


template <class T, class V> void _print(const pair<T, V> &p) {cerr << "{"; _print(p.first); cerr << ",";
_print(p.second); cerr << "}";}
template <class T> void _print(const vector<T> &v) {cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";}
cerr << "]";}
template <class T> void _print(const vector<vector<T>> &v) {cerr << "[\n"; for (const auto &row : v) {cerr << "  [ ";
for (const auto &x : row) {_print(x); cerr << " ";} cerr << "]\n";} cerr << "]";}
template <class T> void _print(const set<T> &v) {cerr << "[ "; for (const auto &i : v) { _print(i); cerr << " ";}
cerr << "]";}
template <class T> void _print(const multiset<T> &v) {cerr << "[ "; for (const auto &i : v) { _print(i); cerr << " ";}
cerr << "]";}
template <class T, class V> void _print(const map<T, V> &v) {cerr << "[ "; for (const auto &i : v) { _print(i);
cerr << " "; } cerr << "]";}
template <size_t idx = 0, typename... T> typename enable_if<idx == sizeof...(T)>::type _print_tuple(const tuple<T...> &t) {}
template <size_t idx = 0, typename... T>
typename enable_if<idx < sizeof...(T)>::type
_print_tuple(const tuple<T...> &t) {
    if(idx > 0) cerr << ",";
    _print(get<idx>(t));
    _print_tuple<idx+1>(t);
}
template <typename... Args> void _print(const tuple<Args...> &t) {cerr << "{"; _print_tuple(t); cerr << "}";}

// ----------------------------------------------------------------------------------------------------------------->

int mod_mul(int a, int b, int MOD)
{
    return (unsigned __int128)a * b % MOD;
}
int mod_exp(int base, int exp, int MOD)
{
    base %= MOD;
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
            ans = mod_mul(ans, base, MOD);
        base = mod_mul(base, base, MOD);
        exp >>= 1;
    }

    return ans;
}
bool is_composite(int n, int a, int s, int d)
{
    int x = mod_exp(a, d, n);

    if (x == 1 || x == n - 1)
        return false;

    for (int i = 1; i < s; i++)
    {
        x = mod_mul(x, x, n);
        if (x == n - 1)
            return false;
        if (x == 1)
            return true;
    }

    return true;
}
bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int s = 0;
    int d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    static const int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (auto &a : bases)
    {
        if (n == a)
            return true;
        if (is_composite(n, a, s, d))
            return false;
    }

    return true;
}
void solve()
{

    int n;
    cin >> n;

    while (n++)
    {
        if (isprime(n))
        {
            cout << n;
            break;
        }
    }
}

signed main() {
    fastio();
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
