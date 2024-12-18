#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXV = 2*(1e5) + 10;

bool numbers[MAXV];

int main(){
  _ int n; cin >> n;
  for(int i = 1; i <= n-1; i++){
    int x; cin >> x;
    numbers[x] = true;
  }

  for(int i = 1; i <= n; i++){
    if(!numbers[i]){
      cout << i << endl;
      break;
    }
  }
  return 0;
}
