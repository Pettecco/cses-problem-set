#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<int> applicants;
vector<int> apartaments; 
int main(){_
  int n, m, k;
  cin >> n >> m >> k;
  applicants.resize(n);
  apartaments.resize(m);
  
  for(int i = 0; i < n; i++)
    cin >> applicants[i];

  for(int i = 0; i < m; i++)
    cin >> apartaments[i];

  sort(applicants.begin(), applicants.end());
  sort(apartaments.begin(), apartaments.end());
  int ans = 0;
  int pAppl = 0, pApart = 0;
  while(pAppl < n && pApart < m){
    if(abs(applicants[pAppl] - apartaments[pApart]) <= k){
      ans++;
      pAppl++;
      pApart++;
    } else if(applicants[pAppl] < apartaments[pApart]){
      pAppl++;
    } else{
      pApart++;
    }
  }
  
  cout << ans << endl;
  return 0;
}
