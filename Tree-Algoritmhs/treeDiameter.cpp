#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;
vector<vector<int>> tree (MAXV);
int dist[MAXV];
 
void dfs(int v){
  for(auto w: tree[v]) if(dist[w] == -1){
    dist[w] = dist[v] + 1;
    dfs(w);
  }
}
 
int main(){
  _ int n; cin >> n;
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  memset(dist, -1, sizeof dist);
 
  dist[1] = 0;
  dfs(1);
 
  int pos = -1, distmax = -1;
  for(int i = 1; i <= n; i++){
    if(dist[i] > distmax){
      distmax = dist[i];
      pos = i;
    }
  }
 
  memset(dist, -1, sizeof dist);
  dist[pos] = 0;
  dfs(pos);
  
  int diametro = 0;
  for(int i = 1; i <= n; i++)
    diametro = max(diametro, dist[i]);
 
  cout << diametro << endl;
}
