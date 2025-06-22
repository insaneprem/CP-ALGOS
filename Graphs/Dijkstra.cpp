 #include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
void dijkstramine(int n, int src,vector<vector<pair<int,int>>> &edges,vector<int> &dist){
    fill(dist.begin(),dist.end(),LLONG_MAX>>1);
    dist[src]=0;
    vector<bool> visited(n,0);
    set<pair<int,int>> toexplore;
    toexplore.insert({0,src});

    while(!toexplore.empty()){
        auto top=*toexplore.begin();
        toexplore.erase(top);
        int popnode=top.second;
        int distsofar=top.first;
        visited[popnode]=1;

        for(auto i:edges[top.first]){
            int node=i.first;
            int addeddist=i.second;

            if(visited[node]) continue;
            
            if(dist[node]>distsofar + addeddist){
                toexplore.erase({dist[node],node});
                dist[node]=distsofar+addeddist;
                toexplore.insert({dist[node],node});
            }
        }
    }
}
// O(VlogV + ElogV)
// Single Source Shortest Path

void Dijkstra(int src, int n, vector<int> &dist, vector<int> &parent, vector<pair<int, int>> *adj) {
	    dist.assign(n, LLONG_MAX>>1);
     	parent.assign(n, -1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int distsofar=pq.top().first;
            int popnode=pq.top().second;
            pq.pop();
            
            if(distsofar != dist[popnode]) continue;
            
            for(auto i:adj[popnode]){
                int node=i.first;
                int distadd=i.second;
                
                if(dist[node]> distadd+distsofar){
                    dist[node]=distadd+distsofar;
				    parent[node] = popnode;
                    pq.push({dist[node],node});
                }
            }
        
        }
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

    int t=1;
    cin>>t;
    while(t--) {
        solve();
        cout<<"\n";
    }
}