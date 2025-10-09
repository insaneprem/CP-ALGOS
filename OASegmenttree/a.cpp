#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
template <typename Node, typename Update>
struct segTree
{
    int n;
    vector<Node> tree;

    segTree(int _n, vector<int> &arr)
    {
        n = _n;
        arr.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    inline void build(int index, int start, int end, vector<int> &arr)
    {
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }

        int mid = (start + end) / 2;

        build(index << 1, start, mid, arr);
        build(index << 1 | 1, mid + 1, end, arr);

        tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
    }

    inline void update(int index, int start, int end, int pos, const Update &u)
    {
        if (start == end)
        {
            u.apply(tree[index]);
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid)
            update(index << 1, start, mid, pos, u);
        else
            update(index << 1 |, mid + 1, pos, u);

        tree[index].merge(tree[index << 1], tree[index << 1 | 1]);
    }

    inline Node query(int index, int start, int end, int ql, int qr)
    {
        if (end < ql || start > qr)
            return Node();
        if (start >= ql && end <= qr)
            return tree[index];

        int mid = (start + end) / 2;

        Node left, right, ans;
        left = query(index << 1, start, mid, ql, qr);
        right = query(index << 1 | 1, mid + 1, end, ql, qr);
        ans.merge(left, right);

        return ans;
    }

    inline void make_update(int pos, int val)
    {
        Update(1, 0, n - 1, pos, Update(val));
    }
    inline Node make_query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

struct Node
{
    int val;

    Node(int v = 0)
    {
        val = v;
    }
    inline void merge(const Node &l, const Node &r)
    {
        val = l.val ^ r.val;
    }
};

struct Update
{
    int val;
    Update(int v = 0)
    {
        val = v;
    }

    inline void apply(Node &a){
        a.val = val;
    }
};
void solve()
{
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "end", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}