#include<bits/stdc++.h>
using namespace std;

vector<long long> tree;

long long query(int node, int node_left, int node_right, int query_left, int query_right ) {
    // if node is completely inside
    if(node_left>=query_left and node_right<=query_right) {
        return tree[node];
    }
    
    // if node is completed outside
    if(node_right<query_left or node_left>query_right) {
        // return default value that would not affect the answer
        return 0;
    }
    
    int mid = node_left + (node_right - node_left) / 2;
    
    return query(2*node, node_left, mid, query_left, query_right) + query(2*node+1, mid+1, node_right, query_left, query_right);
}

void build(vector<int>& nums) {
    int n = nums.size();
    
    while(__builtin_popcount(n) != 1) {
        n++;
        nums.push_back(0);
    }
    
    tree.resize(2*n);
    
    for(int i=0; i<n; i++) {
        tree[n+i] = nums[i];
    }
    
    for(int i = n-1; i>0; i--) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

int main() {
    int n, q;
    
    cin>>n>>q;
    
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin>>nums[i];
    build(nums);
    
    while(q--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        
        cout<<query(1, 0, n-1, a, b)<<"\n";
    }
}
