#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
void dfs(int node,vector<int> adj[],int parent,vector<vector<int>> &dp){
    dp[node][0]=parent;

    for(int i=1;i<=16;i++){
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }

    for(auto child:adj[node]){
        if(child == parent) continue;
        dfs(child,adj,node,dp);
    }

}
int kthparent(int node,int k,vector<vector<int>> &dp){
    int cnt=0;
    while(k){
        if(k&1){
            node=dp[node][cnt];
        }
        cnt++;
        k=k>>1;
    }
}
void solve(){
    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n+1,vector<int> (17));

    int q;
    cin>>q;

    while(q--){
        int node,k;
        cin>>node>>k;
        
        for(int i=16;i>=0;i--){
            if((k>>1) & 1){
                node=dp[node][i];
            }
        }

        cout<<node;

    }
}
signed main(){
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--) {
        solve();
        cout<<"\n";
    }
}