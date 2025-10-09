#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
template <typename Node, typename Update>
struct LazysegTree
{
    int n;
    vector<Node> tree;
    vector<Update> lazy;
    vector<bool> hasLazy;

    LazysegTree(int _n, const vector<int> &arr)
    {
        n = _n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        hasLazy.assign(4 * n, false);
        build(1, 0, n - 1, arr);
    }

    inline void build(int idx, int start, int end, const vector<int> &arr)
    {
        if (start == end)
        {
            tree[idx] = Node(arr[start]);
            return;
        }

        int mid = (start + end) >> 1;
        build(idx << 1, start, mid, arr);
        build(idx << 1 | 1, mid + 1, end);

        tree[idx].merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    inline void applyUpdate(const Update &u, int idx, int l, int r)
    {
        u.apply(tree[idx], l, r);
        if (l != r)
        {
            if (!hasLazy[idx])
            {
                lazy[idx] = u;
                hasLazy[idx] = true;
            }
            else
                lazy[idx].combine(u);
        }
    }
    inline void pushdown(int idx, int start, int end)
    {
        if (hasLazy[idx])
        {
            int mid = (start + end) >> 1;
            applyUpdate(lazy[idx], idx << 1, start, mid);
            applyUpdate(lazy[idx], idx << 1 | 1, mid + 1, end);
            lazy[idx] = Update();
            hasLazy[idx] = false;
        }
    }
    inline void update(int idx, int start, int end, int l, int r, const Update &u)
    {
        if (start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            // complete
            applyUpdate(u, idx, l, r);
            return;
        }
        pushdown(idx, start, end);

        int mid = (start + end) >> 1;
        update(idx << 1, start, mid, l, r, u);
        update(idx << 1 | 1, mid + 1, end, l, r, u);

        tree[idx].merge(tree[idx << 1], tree[idx << 1 | 1]);
    }

    inline Node query(int idx, int start, int end, int ql, int qr)
    {
        if (start > qr || end < ql)
            return Node();
        if (start >= ql && end <= qr)
        {
            // complet
            return tree[idx];
        }

        pushdown(idx, start, end);

        int mid = (start + end) >> 1;
        Node left, right, ans;
        left = query(idx << 1, start, mid, ql, qr);
        right = query(idx << 1 | 1, mid + 1, end, ql, qr);
        ans.merge(left, right);

        return ans;
    }

    inline void make_update(int l, int r, int val)
    {
        update(1, 0, n - 1, l, r, Update(val));
    }
    inline Node make_query(int l, int r)
    {
        Node ans = query(1, 0, n - 1, l, r);
        return ans;
    }
};
struct Node
{
    int val;
    Node(int v = 0)
    {
        val = v;
    }

    void inline merge(const Node &a,const  Node &b)
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

    inline void combine(const Update &other)
    {
        if (other.isSet)
        {
            val = other.val;
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