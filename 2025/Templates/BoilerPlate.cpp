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

// ------------------- Helpers ------------------- //

// Fast exponentiation (a^b % mod)
long long power(long long a, long long b, long long mod = LLONG_MAX) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Count set bits in an integer
int countBits(long long n) {
    return __builtin_popcountll(n);
}

// Check if nth bit is set
bool isBitSet(long long n, int pos) {
    return (n >> pos) & 1LL;
}

// Greatest Common Divisor
long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Least Common Multiple
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// ------------------- Solve ------------------- //

void solve() {
    // Your problem-specific code goes here
    int n;
    cin >> n;
    cout << "You entered: " << n << "\n";
}

// ------------------- Main ------------------- //

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  // Uncomment if multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
