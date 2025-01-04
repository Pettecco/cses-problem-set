#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;
vector<vector<int>> tree (MAXV);
int subordinates[MAXV];
int bosses[MAXV];
 
void dfs(int v){
  for(auto w: tree[v]){
    dfs(w);
    subordinates[v] += subordinates[w] + 1;
  }
}

int main(){
  _ int n; cin >> n;

  for(int i = 0; i < n-1; i++){
    cin >> bosses[i]; // direct boss for each ith employee
  }
  
  for(int i = 0; i < n-1; i++){
    tree[bosses[i]].push_back(i+2);
  }

  dfs(1);
  
  for(int i = 1; i <= n; i++){
    cout << subordinates[i] << " ";
  }

  cout << endl;

  return 0;
}
