#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(ll i=0;i<n;i++)
#define umll unordered_map<ll,ll>
#define usll unordered_set<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define all(a) a.begin(),a.end()
#define ucll unordered_map<char,ll>
#define inputarr(arr,n) for(int i=0;i<n;i++){cin>>arr[i];}
#define printarr(arr,n) for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
#define sortall(arr) sort(arr.begin(),arr.end()) 
#define arrsum(arr,sum,n) rep(i,n){sum+=arr[i];}
#define fast     ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0); 
 
 
ll getcount( ll n,  ll k){ 
    // get count of numbers upto n whose kth bit is set in O(1)
    ll res = (n >> (k + 1)) << k;
    if ((n >> k) & 1)
        res += n & ((1LL << k) - 1);
    return res;
}
 
ll power(ll a,ll b){
    ll ans=1;
    while(b){
    if(b&1){
            ans=ans*a;
            b--;
        }
        a=a*a;
        b/=2;
    }
   return ans;
}
 
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
unordered_map<int,bool> visited;
vector<int> res;
unordered_map<int,int> parent;
bool dfs(int i,unordered_map<int,vector<int>>&graph,int p=0){
    parent[i]=p;
    visited[i]=true;

    bool ans=false;
    for(int j=0;j<graph[i].size();j++){
        if(visited[graph[i][j]] ){   
            if(graph[i][j]!=p and p!=0){
            
                int x=graph[i][j];
                res.push_back(x);
            
                while(i!=x){
                    res.push_back(i);
                    i=parent[i];
                
                }
                cout<<endl;
                res.push_back(x);
                return true;
            }   
        }else{
            // return dfs(graph[i][j],graph,i); --> Wrong
           if(dfs(graph[i][j],graph,i)) return true;
        }
    }
    
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
   
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,graph)){
                 cout<<res.size()<<endl;
                for(auto x:res){
                    cout<<x<<" ";
                }
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";    
}
 
int main(){
    fast
    ll t;
    // cin>>t;
    t=1;
    ll i=1;
    while(t--){
        //cout<<"Case #"<<(i++)<<": ";
        solve();
        //cout<<endl;
    }
}