#include<bits/stdc++.h>
using namespace std;


vector<long long> tree;
int n;

int nearest_power_of_2(int n) {
    // Check if n is a power of 2.
    if ((n & (n - 1)) == 0) {
        return n;
    }

    // Find the nearest greater power of 2.
    int power_of_2 = 1;
    while (power_of_2 < n) {
        power_of_2 *= 2;
    }

    return power_of_2;
}

void build(vector<int> nums) {
    tree.resize(2*n);

    for(int i=0; i<nums.size(); i++) {
        tree[n+i] = nums[i];
    }

    for(int i = n-1; i>=0; i--) {
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

long long query(int node, int node_left, int node_right, int query_left, int query_right) {
    if(node_left>=query_left and node_right<=query_right) {
        return tree[node];
    }

    if(node_left>query_right or node_right<query_left) {
        return INT_MAX;
    }

    int left_tree_end = node_left + (node_right - node_left)/2;

    return min(query(2*node, node_left, left_tree_end, query_left, query_right), query(2*node+1, left_tree_end +1, node_right, query_left, query_right));
}

void update(int k, int u) {
    tree[n+k] = u;

    for(int i = (n+k)/2; i>=1; i/=2) {
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

int main() {
    int q;
    
    cin>>n>>q;
    vector<int> nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];

    n = nearest_power_of_2(n);

    build(nums);

    while(q--) {
        int type;
        cin>>type;

        if(type == 1) {
            int k, u;
            cin>>k>>u;
            k--;

            update(k, u);
        }else {
            int a, b;
            cin>>a>>b;

            a--;
            b--;

            cout<<query(1, 0, n-1, a, b)<<endl;
        }
    }
}
