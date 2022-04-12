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

vector<int> result;
bool imp=false;
void bfs(vector<vector<int>> &graph,vector<bool>&visited,int curr){
    queue<int> q;
    q.push(curr);
    result[curr]=1;
    visited[curr]=true;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        int newTeam=result[k]==1?2:1;
        for(auto x:graph[k]){
            
            if(!visited[x]){
                visited[x]=true;
                result[x]=newTeam;
                q.push(x);
            }else if(result[x]==result[k]){
                // cout<<x<<" "<<k<<" "<<result[x]<<endl;
                imp=true;
                return;
            }
        }
    }
}
void solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<int>> graph(n+1);
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
  }
  result.resize(n+1);
  vector<bool> visited(n+1,false);
  for(int i=1;i<=n;i++){
      if(!visited[i]){
          bfs(graph,visited,i);
      }
      if(imp){
          cout<<"IMPOSSIBLE";
          return;
      }
  }

   for(int i=1;i<=n;i++){
       cout<<result[i]<<" ";
   }

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

/*
   Some Concepts :- 
   1. Number of divisors of N - Find divisors up to sqrt(N) using 
   prime division and If after that N>1 then double the number of divisor 

   2. If a prime number can be written as sum of two primes then one of them 
   must be 2.(because all primes are odd(odd+even=odd))

   3. In question of bit-manipulation .... Think of firstly O(32 x N) time 
   complexity.

   4. If you have to traverse for prime numbers then do operations for 2 
   separately and then for all odd numbers starting from 3(i+=2) (better t.c)

   5. First number >1 which divides N must be a prime.

   6. For maximizing the number of factors of a number we can multiply more primes
   in it.  like for (6-> (1+1)x(1+1)=4 facts,12-> 6x2=(6 factors) 
   but 30>6x5=(1+1)x(1+1)x(1+1)=8 factors)

   7. Fo better time complexities:
     i) Implement most part in main
     ii) Initialize things outside the main
     iii) Don't send big arrays or data structures in function( waste of time goes in copying)
     iv) If sending something in function - send as a reference
     v) Use iterative methods instead of recursive if possible 

   
*/