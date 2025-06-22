#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
vector<int> segTree,Lazy;
int merge(int a,int b){
    return min(a,b);
}
void propogate(int start,int end,int index){
    if(start ==  end){
        Lazy[index]=0;
        return;
    }

    Lazy[2*index]+=Lazy[index];
    Lazy[2*index+1]+=Lazy[index];
    Lazy[index]=0;
}
void build(vector<int> &arr,int start,int end,int index){
    if(start == end){
        segTree[index]=arr[start];
        return;
    }

    int mid=(start+end)/2;
    int left=2*index;
    int right=2*index+1;

    build(arr,start,mid,left);
    build(arr,mid+1,end,right);

    segTree[index]=merge(segTree[left],segTree[right]);
}
void update(vector<int> &arr,int start,int end,int index,int l,int r,int val){
    if(Lazy[index] != 0){
        segTree[index]+=Lazy[index];
        propogate(start,end,index);
    }

    if(start>=l && end<=r){
        segTree[index]+=val;
        Lazy[index]=val;
        propogate(start,end,index);
        return;
    }

    if (l > end || r < start) return;
    
    int mid=(start+end)/2;
    int left=2*index;
    int right=2*index+1;

    update(arr,start,mid,left,l,r,val);
    update(arr,mid+1,end,right,l,r,val);
    
    segTree[index]=merge(segTree[left],segTree[right]);
}

int query(int start,int end,int index,int l,int r){
    if(Lazy[index] != 0){
        segTree[index]+=Lazy[index];
        propogate(start,end,index);
    }

    if(start>=l && end<=r){
        return segTree[index];
    }

    if (l > end || r < start) return INT_MAX;

    
    int mid=(start+end)/2;
    int left=2*index;
    int right=2*index+1;

    
    int leftans=query(start,mid,left,l,r);
    int rightans=query(mid+1,end,right,l,r);
    return merge(leftans,rightans);
    
}
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n, 0); // Initialize array with zeros
    segTree.resize(4 * n);
    Lazy.resize(4 * n, 0); // Initialize lazy array with zeros

    build(arr, 0, n - 1, 1); // Build the segment tree

    while (q--) {
        int a;
        cin >> a;

        if (a == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(arr,0, n - 1, 1, l, r - 1, val); // Update range
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, 1, l, r - 1) << "\n"; // Query range
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
    // cin>>t;
    while(t--) {
        solve();
        // cout<<"\n";
    }
}