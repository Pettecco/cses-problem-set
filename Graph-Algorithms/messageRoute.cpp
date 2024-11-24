#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;

vector<vector<int>> adj(MAXV);
int dist[MAXV];
int parent[MAXV];

void bfs(int source, int dest){
  memset(dist, -1, sizeof dist);
  memset(parent, -1, sizeof dist);

  queue<int> q;
  dist[source] = 0;
  q.push(source);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int w : adj[u]){
      if(dist[w] == -1){
        dist[w] = dist[u] + 1;
        parent[w] = u;
        q.push(w);
      }
    }
  }
}

void path(int n){
  if(dist[n] == -1){
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<int> path;
  for(int i = n; i != -1; i = parent[i]){
    path.push_back(i);
  }

  reverse(path.begin(), path.end());
  
  cout << path.size() << endl;
  for(int w : path){
    cout << w << " ";
  }
  
  cout << endl;
}

int main(){
  _ int n, m; cin >> n >> m;
  
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  bfs(1, n);
  path(n);

  return 0;
}
