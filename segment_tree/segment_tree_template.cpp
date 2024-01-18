int DEFAULT_VALUE = 0;
vector<long long> tree;
int n;

int nearest_power_of_2(int n) {
    if((n&(n-1) == 0)) return n;

    int power = 1;
    while(power<n) power<<=1;

    return power;
}

long long operation(long long num1, long long num2) {
    int result = ; // do some operation and return result
    return result;
}

long long query(int node, int node_left, int node_right, int query_left, int query_right) {
    if(node_left>=query_left and node_right<=query_right) return tree[node];

    if(node_left>query_right or node_right<query_left) return DEFAULT_VALUE;

    int left_tree_end = node_left + (node_right - node_left)/2;

    long long left_tree_ans = query(2*node, node_left, left_tree_end, query_left, query_right);
    long long right_tree_ans = query(2*node + 1, left_tree_end+1, node_right, query_left, query_right);

    return operation(left_tree_ans, right_tree_ans);
}

void build(vector<int>& a) {
    n = nearest_power_of_2(n);
    tree.resize(2*n);

    for(int i=0; i<a.size(); i++) {
        tree[n+i] = a[i];  // leaf nodes
    }

    for(int i=n-1; i>=1; i--) {
        tree[i] = operation(tree[2*i], tree[2*i+1]);
    }
}

void update(int k, int u) {
    tree[n+k] = u;

    for(int i=(n+k)/2; i>=1; i/=2) {
        tree[i] = operation(tree[2*i], tree[2*i+1]);
    }
}
