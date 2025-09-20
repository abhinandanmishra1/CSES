#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <sstream>
#include <functional>

using namespace std;

using ll = long long;

vector<ll> tree;
const ll NEUTRAL = 0; // neutral element for sum

inline ll operation(ll left, ll right) {
    return left + right;
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

ll query(ll qs, ll qe, ll start, ll end, ll node) {
    if (qe < start || qs > end) return NEUTRAL;       // no overlap
    if (qs <= start && end <= qe) return tree[node];    // complete overlap
    ll mid = (start + end) / 2;                         // partial overlap
    ll left = query(qs, qe, start, mid, 2 * node + 1);
    ll right = query(qs, qe, mid + 1, end, 2 * node + 2);
    return operation(left, right);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];

    tree.assign(4 * n, 0);
    build(arr, 0, 0, n - 1);

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--; // convert to 0-based
        cout << query(l, r, 0, n - 1, 0) << "\n";
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
