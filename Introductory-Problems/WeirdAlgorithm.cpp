#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
void weirdAlg(ll n){
  cout << n << " ";
  if(n == 1) return;
 
  if(n&1) weirdAlg(n*3 + 1);
  else weirdAlg(n/2);
}
 
int main(){
  _ ll n; cin >> n;
  weirdAlg(n);
  cout << endl;
  return 0;
}
