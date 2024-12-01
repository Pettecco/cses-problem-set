#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;
 
vector<ll> arr(MAXV);
 
int main(){
  _ int n, target;
  cin >> n >> target;
  
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  
  int ans = 0;
  ll prefixSum = 0;
  unordered_map<ll, int> prefixCount;
  prefixCount[0] = 1;
 
  for(int i = 0; i < n; i++){
    prefixSum += arr[i];
  
    if(prefixCount.find(prefixSum - target) != prefixCount.end()){
      ans += prefixCount[prefixSum - target];
    }
 
    prefixCount[prefixSum] += 1;
  }
  cout << ans << endl;
  return 0;
}
