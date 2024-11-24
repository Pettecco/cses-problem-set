#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 1010;
vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char grid[MAXV][MAXV];
bool vis[MAXV][MAXV];
int n, m;
 
bool val(pair<int, int> u){
  return u.first >= 0 && u.first < n && u.second >= 0 && u.second < m && !vis[u.first][u.second] && grid[u.first][u.second] != '#';
}
 
void bfs(pair<int, int> s){
  queue<pair<int, int>> q; q.push(s);
  vis[s.first][s.second] = true;
  
  while(!q.empty()){
    pair<int, int> v = q.front();
    q.pop();
 
    for(auto u : mov){
      u.first += v.first;
      u.second += v.second;
 
      if(val(u)){
        vis[u.first][u.second] = true;
        q.push(u);
      }
    }
  }
}
 
int main(){
  _ cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> grid[i][j];
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == '.' && !vis[i][j]){
        pair<int, int> s = {i, j};
        ans++;
        bfs(s);
      }
    }
  }
 
  cout << ans << endl;
  return 0;
}
