#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;
vector<int> apples(25);
 
void solve(){
  ll ans = INT_MAX;
  for(int mask = 0; mask < (1 << n); mask++){
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)){
        a += apples[i];
      } else{
        b += apples[i];
      }
    }
    ll sub = abs(a - b);
    ans = min(ans, sub);
  }
 
  cout << ans << endl;
}
 
int main(){
  _  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> apples[i];
 
  solve();
 
  return 0;
