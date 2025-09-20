#include <iostream>;
#include <vector>;
using namespace std;

using ll = long long;

struct SegmentTree {
    vector<ll> tree;
    ll n;
    const ll UNDEFINED = 0; // neutral element for sum

    SegmentTree(ll size) {
        n = size;
        tree.assign(4 * n, UNDEFINED);
    }

    inline ll operation(ll left, ll right) {
        return left + right; // change to min/max/gcd if needed
    }

    void build(vector<ll>& arr, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        ll mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
    }

    ll query(ll rangeStart, ll rangeEnd, ll start, ll end, ll node) {
        if (rangeEnd < start || rangeStart > end) return UNDEFINED; // no overlap
        if (rangeStart <= start && end <= rangeEnd) return tree[node]; // complete overlap
        ll mid = (start + end) / 2;
        ll left = query(rangeStart, rangeEnd, start, mid, 2 * node + 1);
        ll right = query(rangeStart, rangeEnd, mid + 1, end, 2 * node + 2);
        return operation(left, right);
    }

    void update(ll idx, ll val, ll start, ll end, ll node) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        ll mid = (start + end) / 2;
        if (idx <= mid)
            update(idx, val, start, mid, 2 * node + 1);
        else
            update(idx, val, mid + 1, end, 2 * node + 2);
        tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(n);
    st.build(arr, 0, 0, n - 1);

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) { // query
            ll l, r;
            cin >> l >> r;
            l--, r--; // convert to 0-based
            cout << st.query(l, r, 0, n - 1, 0) << "\n";
        } else if (type == 2) { // update
            ll idx, val;
            cin >> idx >> val;
            idx--; // convert to 0-based
            st.update(idx, val, 0, n - 1, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
