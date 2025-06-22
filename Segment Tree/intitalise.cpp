#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
vector<int> segTree;
void build(vector<int> &arr,int start,int end,int index){ //Build the segment tree
   if(start == end){
      segTree[index]=arr[start];
      return;
   }

   int mid=(start+end)/2;
   int left=2*index;
   int right=2*index+1;
   build(arr,start,mid,left);
   build(arr,mid+1,end,right);

   segTree[index]=segTree[left]+segTree[right];
}
void update(vector<int> &arr,int start,int end,int index,int pos,int val){ //Update at given point in the segment tree
     if(start == end){
        arr[pos]=val;
        segTree[index]=arr[pos];
        return;
     }

     int mid=(start+end)/2;
     int left=2*index;
     int right=2*index+1;
     if(pos<=mid)
        update(arr,start,mid,left,pos,val);
     else
        update(arr,mid+1,end,right,pos,val);

    segTree[index]=segTree[left]+segTree[right];
} 

int query(int start,int end,int index,int l,int r){ //give sum from l to r
    //Complete overlap
    //[l...start...end...r]
    if(start>=l && end<=r)
      return segTree[index];

    //Disjoint
    //[end...l || r...start]
    if(l>end || r<start) return 0;

    //Partial over lap
    int mid=(start+end)/2;
    int left=2*index;
    int right=2*index+1;
    int leftans=query(start,mid,left,l,r);
    int rigthans=query(mid+1,end,right,l,r);

    return leftans+rigthans;
}
void solve(){ 
    int n;
    cin>>n;

    segTree.resize(2*n +1);
     
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;

    build(arr,0,n-1,1);
    cout<<query(0,n-1,1,1,3)<<endl;
    update(arr,0,n-1,1,1,10);
    cout<<query(0,n-1,1,1,3)<<endl;
}
signed main(){
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while(t--) {
        solve();
        cout<<"\n";
    }
}