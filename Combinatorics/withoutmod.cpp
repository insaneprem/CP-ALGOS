#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
int nomod(int n,int r){
    int ans=1;
    for(int i=1;i<=min(r,n-r);i++){
        ans=(ans*(n-i+1))/i;
    }
    return ans;
}
void solve(){
    
}
signed main(){
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    // t=1;
    while(t--) solve();
}