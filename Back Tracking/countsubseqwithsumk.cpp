#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int tar,int ind=0){
    if(ind == arr.size()){
       if(tar == 0){
         return 1;
       }
       return 0;
    }

    int npick=solve(arr,tar,ind+1);
    int pick=solve(arr,tar-arr[ind],ind+1);

    return npick+pick;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,tar;
    cin>>n>>tar;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    cout<<solve(arr,tar);
}