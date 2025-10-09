#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
template <typename Node, typename Update>
struct LazySegTree
{
    int n;
    vector<Node> tree;
    vector<Update> Lazy;
    vector<bool> hasLazy;

    LazySegTree(int _n, vector<int> &arr)
    {
        n = _n;
        tree.resize(4 * n);
        Lazy.resize(4 * n);
        hasLazy.assign(4 * n, false);
        build(1, 0, n - 1, arr);
    }

    inline void build(int idx, int start, int end, vector<int> &arr)
    {
        if (start == end)
        {
            tree[idx] = Node(arr[start]);
            return;
        }

        int mid = (start + end) >> 1;
        build(idx << 1, start, mid, arr);
        build(idx << 1 | 1, mid + 1, end, arr);

        tree[idx].merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    inline void applyUpdate(int idx, int l, int r, Update &u)
    {
        u.apply(tree[idx], l, r);

        if (l != r)
        {
            if (!hasLazy[idx])
            {
                hasLazy[idx] = true;
                Lazy[idx] = u;
            }
            else
                Lazy[idx].combine(u);
        }
    }

    inline void pushdown(int idx, int start, int end)
    {
        if (hasLazy[idx])
        {
            int mid = (start + end) >> 1;

            applyUpdate(idx << 1, start, mid , lazy[idx]);
            applyUpdate(idx << 1 | 1, mid + 1, end , lazy[idx]);
            hasLazy[idx] = false;
            Lazy[idx] = Update();
        }
    }

    inline void update(int idx, int start, int end, int ql, int qr, Update &u)
    {
        if (start > qr || end < ql)
            return;

        if (start >= ql && end <= qr)
        {
            applyUpdate(idx, start, end, u);
            return;
        }

        pushdown(idx, start, end);
        int mid = (start + end) >> 1;

        update(idx << 1, start, mid, ql, qr, u);
        update(idx << 1 | 1, mid + 1, end, ql, qr, u);

        tree[idx].merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    inline Node query(int idx, int start, int end, int ql, int qr)
    {
        if (start > qr || end < ql)
            return Node();

        if (start >= ql && end <= qr)
        {

            return tree[idx];
        }

        pushdown(idx, start, end);
        int mid = (start + end) >> 1;

        Node left = query(idx << 1, start, mid, ql, qr);
        Node right = query(idx << 1 | 1, mid + 1, end, ql, qr);

        Node ans;
        ans.merge(left, right);
        return ans;
    }

    inline void make_update(int ql, int qr, int val)
    {
        Update u = Update(val, true);
        update(1, 0, n - 1, ql, qr, u);
    }

    inline Node make_query(int ql, int qr)
    {
        return query(1, 0, n - 1, ql, qr);
    }
};

struct Node
{
    int val;

    Node(int v = 0)
    {
        val = v;
    }

    inline void merge(const Node &a,const Node &b)
    {
        val = a.val + b.val;
    }
};

struct Update
{
    int val;
    bool isSet;
    Update(int v = 0, bool set = false)
    {
        val = v;
        isSet = set;
    }

    inline void apply(Node &a, int l, int r)
    {
        if (isSet)
            a.val = val * (r - l + 1);
    }

    inline void combine(Update &other)
    {
        if (other.isSet)
        {
            val += other.val;
            isSet = true;
        }
    }
};
void solve()
{
  
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}