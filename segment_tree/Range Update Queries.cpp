#include<bits/stdc++.h>
using namespace std;

int DEFAULT_VALUE = 0;
vector<long long> tree;
int n;

int nearest_power_of_2(int n) {
    if((n&(n-1) == 0)) return n;

    int power = 1;
    while(power<n) power<<=1;

    return power;
}

// long long operation(long long num1, long long num2) {
//     return num1 + num2;
// }

// long long update(int curr, int p) {
//     return curr + p;
// }

// long long query(int node, int node_left, int node_right, int query_left, int query_right) {
//     if(node_left>=query_left and node_right<=query_right) {
//         cout<<"Node"<<tree[node]<<endl;
//         return tree[node];
//     }

//     if(node_left>query_right or node_right<query_left) return DEFAULT_VALUE;

//     int left_tree_end = node_left + (node_right - node_left)/2;
    
//     long long left_tree_ans = query(2*node, node_left, left_tree_end, query_left, query_right);
//     long long right_tree_ans = query(2*node + 1, left_tree_end+1, node_right, query_left, query_right);

//     int sum = left_tree_ans + right_tree_ans;
//     cout<<node<<" "<<sum<<endl;
//     return sum + tree[node];
// }

long long query_lazy(int pos) {
    long long ans = 0;
    for(int i = (n+pos); i>=1; i/=2) {
        ans += tree[i];
    }
    
    return ans;
}

void update_recur(int node, int node_left, int node_right, int query_left, int query_right, int val) {
    if(node_left>=query_left and node_right<=query_right) {
        tree[node] += val;
        return;
    }

    if(node_left>query_right or node_right<query_left) return;

    int left_tree_end = node_left + (node_right - node_left)/2;

    update_recur(2*node, node_left, left_tree_end, query_left, query_right, val);
    update_recur(2*node + 1, left_tree_end+1, node_right, query_left, query_right, val);
}

// void update_iter(int k, int u) {
//     tree[n+k] = u;

//     for(int i=(n+k)/2; i>=1; i/=2) {
//         tree[i] = operation(tree[2*i], tree[2*i+1]);
//     }
// }

void build(vector<int>& a) {
    n = nearest_power_of_2(n);
    tree.resize(2*n);

    for(int i=0; i<a.size(); i++) {
        tree[n+i] = a[i];  // leaf nodes
    }

//     for(int i=n-1; i>=1; i--) {
//         tree[i] = tree[2*i] + tree[2*i+1];
//     }
}


int main() {
    int q;
    cin>>n>>q;

    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];

    build(a);

    while(q--) {
        int type;
        cin>>type;

        if(type == 1) {
            int i, j, u;
            cin>>i>>j>>u;

            i--, j--;
            
            update_recur(1, 0, n-1, i, j, u);
        }else {
            int i;
            cin>>i;

            i--;

            cout<<query_lazy(i)<<endl;
        }
    }
}
