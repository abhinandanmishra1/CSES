#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fast     ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0); 
void solve(){
  ll n,m;
  cin>>n>>m;
  pair<int,int> start={0,0};
  vector<vector<char>> graph(n,vector<char>(m));
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin>>graph[i][j];
          if(graph[i][j]=='A'){
              start={i,j};
              graph[i][j]='#';
            //   cout<<i<<" "<<j<<endl;
          }
      }
  }
  queue<pair<int,int>> q;
  vector<int> dir1={0,0,-1,1};
  vector<int> dir2={-1,1,0,0};
  // 0 -1 L
  // 0 +1 R
  // -1 0 U
  // +1 0 d
  vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
  q.push(start);
  parent[start.first][start.second]={-1,-1};
  while(!q.empty()){
      auto currPos=q.front();
      int x=currPos.first;
      int y=currPos.second;      
      q.pop();
      for(int i=0;i<4;i++){
          int newX=x+dir1[i];
          int newY=y+dir2[i];
          
          if(newX<0 or newY<0 or newX>=n or newY>=m){
              continue;
          }else{
              if(graph[newX][newY]=='B'){
                  cout<<"YES\n";
                  string path="";
                  ll row=newX,col=newY;
                  parent[newX][newY]={x,y};
                  while(parent[row][col].first!=-1){
                      auto p=parent[row][col];
                      ll prow=p.first;
                      ll pcol=p.second;
                      if(prow>row){
                          path+="U";
                      }else if(prow<row){
                          path+="D";
                      }
                      else if(pcol>col){
                          path+="L";
                      }else{
                          path+="R";
                      }
                      row=prow;
                      col=pcol;
                  }
                  cout<<path.length()<<endl;
                  reverse(path.begin(),path.end());
                  cout<<path;
                  return;
              }else if(graph[newX][newY]=='.'){
                  q.push({newX,newY});
                  graph[newX][newY]='#';
                  parent[newX][newY]={x,y};   
              }
          }
      }
  }
  cout<<"NO\n";

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
