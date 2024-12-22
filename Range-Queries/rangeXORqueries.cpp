#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5)+10;

int vet[MAXV];
int prefixXor[MAXV];

int main() {_
    
  int n, q; cin >> n >> q;
  
  for(int i = 1; i <= n; i++){
    cin >> vet[i];
  }
  
  vet[0] = 0, prefixXor[0] = 0;
  for(int i = 1; i <= n; i++){  
    prefixXor[i] = prefixXor[i-1] ^ vet[i];
  }

  while(q--){
    int a, b; cin >> a >> b;
    cout << (prefixXor[b] ^ prefixXor[a-1]) << endl;
  }

  return 0;
}

