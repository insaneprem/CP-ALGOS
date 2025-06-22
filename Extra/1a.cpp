#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    cout << str;
}