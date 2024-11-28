#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 1e5 + 10;

vector<vector<int>> adj(MAXV);
vector<bool> vis(MAXV);

void dfs(int v){
  vis[v] = true;

  for(auto w : adj[v]) if(!vis[w]){
    dfs(w);
  }
}

int main(){
  _ int n, m; cin >> n >> m;
  
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int roads = 1;
  dfs(1);
  vector<int> ans;
  ans.push_back(1);
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      roads++;
      ans.push_back(i);
      dfs(i);
    }
  }
  
  if(roads-1 == 0){
    cout << 0 << endl;
    return 0;
  }

  cout << roads - 1 << endl;
  for(int i = 0;  i < ans.size() - 1; i++){
    cout << ans[i] << " " << ans[i+1] << endl; 
  }

 return 0;
}
