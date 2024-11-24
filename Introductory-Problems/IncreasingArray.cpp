#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;

int vet[MAXV];

int main(){
  _ int n; cin >> n;
  ll ans = 0;

  for(int i = 0; i < n; i++){
    cin >> vet[i];
  }
  
  for(int i = 1; i < n; i++){
    if(vet[i] < vet[i-1]){
      ans += vet[i-1] - vet[i];
      vet[i] = vet[i-1];
    }
  }

  cout << ans << endl;

  return 0;
}
