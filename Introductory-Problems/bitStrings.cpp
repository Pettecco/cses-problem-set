#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;
 
int n;
ll base = 2;
 
ll modularExponentiation(ll mod){
  ll ans = 1;
  base = base % mod;
  while(n > 0){
    if(n % 2 == 1){
      ans = (ans * base) % mod;
    }
    n = (n >> 1);
    base = (base * base) % mod;
  }
  return ans;
}
 
int main(){
  _ cin >> n;
  ll ans = modularExponentiation(MOD);
  cout << ans << endl;
  return 0;
}
