#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;

ll prefixSum[MAXV];
ll vet[MAXV];
int main(){
  _ int n, q; cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> vet[i];
  }
  
  prefixSum[1] = vet[1];
  for(int i = 2; i <= n; i++){
    prefixSum[i] = vet[i] + prefixSum[i-1];
  }

  int l, r;
  while(q--){
    cin >> l >> r;
    if(l == 1){
      cout << prefixSum[r] << endl;
    } else{
      cout << prefixSum[r] - prefixSum[l-1] << endl;
    }
  }
  return 0;
}
