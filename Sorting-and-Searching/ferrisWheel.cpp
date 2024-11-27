#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;

vector<int> weights(MAXV);
 
int main(){_
  ll n, x; cin >> n >> x;
  ll ans = 0;
  weights.resize(n);
  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }
  sort(weights.begin(), weights.end());
  
  int l = 0, r = n-1;
  
  while(l <= r){
    if(weights[l] + weights[r] <= x)
      l++;
    r--;
    ans++;
  }
  
  cout << ans << endl;

  return 0;
}
