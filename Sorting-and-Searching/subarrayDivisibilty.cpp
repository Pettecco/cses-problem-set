#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;
int nums[MAXV];

int main() {_
  int n; cin >> n;
  ll prefixSum = 0;
  unordered_map<ll, ll> hashMap;

  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }
  ll ans = 0;
  hashMap[0] = 1;

  for(int i = 0; i < n; i++){
    
    prefixSum = (prefixSum + nums[i]) % n;
    if (prefixSum < 0) {
      prefixSum += n;
    }
    if(hashMap.find(prefixSum) != hashMap.end()){
      ans += hashMap[prefixSum];
    }
    
    hashMap[prefixSum]++;
  }

  cout << ans << endl;

  return 0;
}

