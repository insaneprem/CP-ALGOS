#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<int> ans;
void solve(vector<int> &arr,int ind=0){
    if(ind == arr.size()){
        res.push_back(ans);
        return;
    }
    
    ans.push_back(arr[ind]);
    solve(arr,ind+1);
    ans.pop_back();
    solve(arr,ind+1);

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    solve(arr);

    for(auto i:res){
        for(auto j:i) cout<<j<<" ";

        cout<<endl;
    }
}