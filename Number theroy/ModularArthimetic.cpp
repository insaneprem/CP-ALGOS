#include <bits/stdc++.h>
using namespace std;
// FERMAT LITTLE THEROM (X^(M-1))%M=1
//  (X^(M-1))=1 (MOD M)
//  (X^(m-2)) % M= 1/X ~ MOD INVERSE
int mod_add(int a, int b, int m)
{
    return (a % m + b % m) % m;
}
int mod_sub(int a, int b, int m)
{
    return (a % m - b % m + m) % m;
}
int mod_mul(int a, int b, int m)
{
    return (a % m * b % m) % m;
}
int mod_exp(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int res = mod_exp(a, b / 2, m);
    res = mod_mul(res, res, m);

    if (b % 2 == 1)
        res = mod_mul(res, a, m);

    return res;
}
int binexp(int base, int x, int mod)
{
    int ans = 1;
    while (x)
    {
        if (x % 2)
        {
            ans = (ans * base) % mod;
            x--;
        }
        else
        {
            base = (base * base) % mod;
            x /= 2;
        }
    }
    return ans;
}
// a^p - a is multiple of p : p is prime
// (a^p-a)%p = 0
// a^p-2  % p = a^-1 %p
int mod_inv(int a, int m)
{
    return mod_exp(a, m - 2, m);
}
// JUST USE (A/B) -> (A * (1/B));
// M IS PRIME
int mod_div(int a, int b, int m)
{
    return mod_mul(a, mod_inv(b, m), m);
}

vector<int> fact(100);
int ncr(int n, int r, int m)
{
    if (r < 0 or r > n)
        return 0;
    return mod_div(fact[n], mod_mul(fact[r], fact[n - r], m), m);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int m;
    // fact[0]=1;
    // for(int i=1;i<100;i++) fact[i]=mod_mul(fact[i-1],i,m);
}