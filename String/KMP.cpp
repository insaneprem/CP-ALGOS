#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
vector<int> prefix_function(string s)
{
    // Calculation LPS
    int n = s.length();

    vector<int> LPS(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = LPS[i - 1];
        while (j > 0 && s[i] != s[j])
            j = LPS[j - 1];

        if (s[i] == s[j])
            j++;
        LPS[i] = j;
    }
    return LPS;
}

void solve()
{
    // STRING MATCHING
    //  COMUTE PREFIX FUNCTION FOR S+#+T ( FINDING OCCURANCE OF S IN T)
    //  WHERE LPS[I]== LEN OF S (N) THAT ANSWER OIF STARTING INDEX WILL BE (i-2N)
}

// Optimized KMP algorithm to find occurrences of pattern `s` in text `t`
void KMP(const string &s, const string &t)
{
    int n = s.size();
    int m = t.size();

    // Compute the prefix function for the pattern `s`
    vector<int> pi = prefix_function(s);

    int j = 0; // Number of characters matched

    // Iterate through the text `t`
    for (int i = 0; i < m; ++i)
    {
        // While characters mismatch, follow the prefix function to reduce `j`
        while (j > 0 && t[i] != s[j])
        {
            j = pi[j - 1];
        }

        // If characters match, move to the next character in `s`
        if (t[i] == s[j])
        {
            j++;
        }

        // If the whole pattern is matched
        if (j == n)
        {
            // Output the start position of the match
            cout << "Pattern found at index: " << (i - n + 1) << endl;
            // Use the prefix function to continue searching
            j = pi[j - 1];
        }
    }
}

void countprefix()
{
    int n = 1;
    vector<int> ans(n + 1), pi; // This will store how many times each prefix occurs

    // Count how many times each prefix of length pi[i] occurs
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;

    // For each prefix pi[i], add the counts of its smaller prefixes
    for (int i = n - 1; i > 0; i--)
        ans[pi[i - 1]] += ans[i];

    // Add 1 to each, because each prefix occurs at least once (itself)
    for (int i = 0; i <= n; i++)
        ans[i]++;
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
    cin >> t;
    // t=1;
    while (t--)
        solve();
}