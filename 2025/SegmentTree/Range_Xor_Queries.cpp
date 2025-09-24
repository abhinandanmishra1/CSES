#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

ll NEUTRAL = 0; 

ll operation(ll a, ll b) {
    return a^b; 
}

vector<ll> tree;

void build(vector<ll>& arr, ll lo, ll hi, ll node) {
    if (lo == hi) {
        tree[node] = arr[lo];
        return;
    }
    ll mid = lo + (hi - lo) / 2;
    build(arr, lo, mid, 2 * node + 1);
    build(arr, mid + 1, hi, 2 * node + 2);
    tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
}

ll query(ll start, ll end, ll lo, ll hi, ll node) {
    if (hi < start || lo > end) return NEUTRAL;
    if (lo >= start && hi <= end) return tree[node];
    ll mid = lo + (hi - lo) / 2;
    return operation(
        query(start, end, lo, mid, 2 * node + 1),
        query(start, end, mid + 1, hi, 2 * node + 2)
    );
}

void update(ll idx, ll val, ll lo, ll hi, ll node) {
    if (lo == hi) {
        tree[node] = val;
        return;
    }
    ll mid = lo + (hi - lo) / 2;
    if (idx <= mid) update(idx, val, lo, mid, 2 * node + 1);
    else update(idx, val, mid + 1, hi, 2 * node + 2);
    tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    tree.resize(4 * n);
    build(arr, 0, n - 1, 0);

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r, 0, n - 1, 0) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) solve();

    return 0;
}