#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
stack<int> st;

void dfs(int node,vector<int> &visited,vector<int> adj[]){
    visited[node]=1;

    for(auto e:adj[node]){
        if(!visited[e]) dfs(e,visited,adj);
        else if(visited[e] == 1) return; // cycle found
    }

    visited[node]=2;
    st.push(node);
}
void solve(){
    int n,m;
    cin>>n>>m;

    vector <int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<int> visited(n+1,0);

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i,visited,adj);
        }
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