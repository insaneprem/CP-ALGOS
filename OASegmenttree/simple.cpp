#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
// Generic Segment Tree with Point Update + Range Query
// Optimized for CP

template<typename Node, typename Update>
struct SegTree {
    int n;
    vector<Node> tree;

    SegTree(int _n, const vector<int> &a) {
        n = _n;
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    inline void build(int index, int l, int r, const vector<int> &a) {
        if (l == r) {
            tree[index] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(index << 1, l, mid, a);
        build(index << 1 | 1, mid + 1, r, a);
        tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
    }

    inline void update(int index, int l, int r, int pos, const Update &u) {
        if (l == r) {
            u.apply(tree[index]);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(index << 1, l, mid, pos, u);
        else update(index << 1 | 1, mid + 1, r, pos, u);
        tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
    }

    inline Node query(int index, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node(); // identity element
        if (ql <= l && r <= qr) return tree[index];
        int mid = (l + r) >> 1;
        Node left = query(index << 1, l, mid, ql, qr);
        Node right = query(index << 1 | 1, mid + 1, r, ql, qr);
        Node ans; ans.merge(left, right);
        return ans;
    }

    // User-facing APIs
    inline void make_update(int pos, int val) {
        update(1, 0, n - 1, pos, Update(val));
    }
    inline Node make_query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

// Example Node & Update for XOR segment tree
struct Node1 {
    int val;
    Node1(int v = 0) : val(v) {} // identity = 0
    inline void merge(const Node1 &l, const Node1 &r) {
        val = l.val ^ r.val;
    }
};

struct Update1 {
    int val;
    Update1(int v = 0) : val(v) {}
    inline void apply(Node1 &a) const {
        a.val = val; // assignment
    }
};

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