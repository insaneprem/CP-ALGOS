#include <iostream>
#include <vector>
#include <algorithm>

// Use long long for competitive programming
#define int long long

// --- FOR YOU TO DEFINE ---
// Define your Node and Update structs based on the problem.
// Two examples are provided below the main template.

// Example 1: Range Sum with Range Add
struct Node1;
struct Update1;
// Example 2: Range Min with Range Set
struct Node2;
struct Update2;


// --- GENERIC LAZY SEGMENT TREE TEMPLATE (DO NOT MODIFY OFTEN) ---
template <typename Node, typename Update>
struct LazySegTree {
    int n;
    std::vector<Node> tree;
    std::vector<Update> lazy;
    std::vector<bool> hasLazy;
    std::vector<int>& arr_ref; // Reference to the initial array

    LazySegTree(int _n, std::vector<int>& arr) : arr_ref(arr) {
        n = _n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        hasLazy.assign(4 * n, false);
        build(1, 0, n - 1);
    }

    void build(int idx, int start, int end) {
        if (start == end) {
            tree[idx] = Node(arr_ref[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(idx * 2, start, mid);
        build(idx * 2 + 1, mid + 1, end);
        tree[idx].merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void applyUpdate(int idx, int start, int end, Update& u) {
        u.apply(tree[idx], start, end);
        if (start != end) {
            if (!hasLazy[idx]) {
                lazy[idx] = u;
                hasLazy[idx] = true;
            } else {
                lazy[idx].combine(u);
            }
        }
    }

    void pushdown(int idx, int start, int end) {
        if (hasLazy[idx]) {
            int mid = (start + end) / 2;
            applyUpdate(idx * 2, start, mid, lazy[idx]);
            applyUpdate(idx * 2 + 1, mid + 1, end, lazy[idx]);
            lazy[idx] = Update(); // Reset lazy value
            hasLazy[idx] = false;
        }
    }

    void update(int idx, int start, int end, int ql, int qr, Update& u) {
        if (start > qr || end < ql) return;
        if (start >= ql && end <= qr) {
            applyUpdate(idx, start, end, u);
            return;
        }

        pushdown(idx, start, end);
        int mid = (start + end) / 2;
        update(idx * 2, start, mid, ql, qr, u);
        update(idx * 2 + 1, mid + 1, end, ql, qr, u);
        tree[idx].merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    Node query(int idx, int start, int end, int ql, int qr) {
        if (start > qr || end < ql) return Node(); // Return identity node
        if (start >= ql && end <= qr) {
            return tree[idx];
        }

        pushdown(idx, start, end);
        int mid = (start + end) / 2;
        Node left = query(idx * 2, start, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, end, ql, qr);
        
        Node result;
        result.merge(left, right);
        return result;
    }

    // Public helper functions
    void make_update(int ql, int qr, Update u) {
        update(1, 0, n - 1, ql, qr, u);
    }

    Node make_query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

// --- USAGE EXAMPLES (COPY & PASTE THE ONE YOU NEED) ---

// 🎯 EXAMPLE 1: Range Sum with Range Add Updates
struct Node1 {
    int val;
    // Identity value for sum is 0
    Node1(int v = 0) : val(v) {}

    void merge(const Node1& left, const Node1& right) {
        val = left.val + right.val;
    }
};

struct Update1 {
    int val;
    // Identity value for addition is 0
    Update1(int v = 0) : val(v) {}

    // Apply update to a node
    void apply(Node1& node, int start, int end) {
        node.val += val * (end - start + 1);
    }

    // Combine this pending update with a new one
    void combine(const Update1& other) {
        val += other.val;
    }
};

// 🎯 EXAMPLE 2: Range Minimum with Range Set Updates
const int INF = 1e18;
struct Node2 {
    int val;
    // Identity value for min is infinity
    Node2(int v = INF) : val(v) {}

    void merge(const Node2& left, const Node2& right) {
        val = std::min(left.val, right.val);
    }
};

struct Update2 {
    int val;
    // Use a special value or flag for identity update
    bool is_set;
    Update2(int v = 0, bool set = false) : val(v), is_set(set) {}

    // Apply update to a node
    void apply(Node2& node, int start, int end) {
        if (is_set) {
            node.val = val;
        }
    }

    // Combine this pending update with a new one. The new 'set' overwrites the old one.
    void combine(const Update2& other) {
        if (other.is_set) {
            val = other.val;
            is_set = true;
        }
    }
};

// --- MAIN FUNCTION ---
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Example using Range Sum / Range Add
    LazySegTree<Node1, Update1> seg_tree(n, a);

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) { // Add val to range [l, r]
            int l, r, val;
            std::cin >> l >> r >> val;
            seg_tree.make_update(l - 1, r - 1, Update1(val));
        } else { // Get sum of range [l, r]
            int l, r;
            std::cin >> l >> r;
            Node1 result = seg_tree.make_query(l - 1, r - 1);
            std::cout << result.val << "\n";
        }
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}