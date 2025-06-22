#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
typedef pair<int,int> P;
void BellmanFord(int n, int src, vector<P> *edges, vector<int>& dist, set<int>& negCycle) {
	fill(dist.begin(),dist.end(), LLONG_MAX);
	dist[src] = 0;

	vector<pair<int, P>> e;
    vector<int> parent(n,-1);
	for (int i = 0; i < n; i++) {

		for (auto j : edges[i]) {
            //{weight ,{i,j)}}
			e.push_back({j.second, {i, j.first}});
		}

	}
    bool change=true;
	for (int i = 0; i < n - 1; i++) {
        change=false;
		for (auto j : e) {
            if(dist[j.second.second]>dist[j.second.first]+j.first){
               change=true;
               parent[j.second.second]=j.second.first;
            }
			dist[j.second.second] = min(dist[j.second.second], dist[j.second.first] + j.first);
            if(!change) break;
		}
	}
	
	for (auto j : e) {
		if (dist[j.second.second] > dist[j.second.first] + j.first) {
			dist[j.second.second] = dist[j.second.first] + j.first;
			negCycle.insert(j.second.second);
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