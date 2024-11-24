#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){
  _ int n; cin >> n;

  if(n == 1) cout << 1 << endl;
  else if(n <= 3) cout << "NO SOLUTION" << endl;
  else if(n == 4){
    cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
  }
  else{
    for(int i = n; i >= 1; i--){
      if(!(i&1)){
        cout << i << " ";
      }
    }

    for(int i = n; i >= 1; i--){
      if(i&1){
        cout << i << " ";
      }
    }
    
    cout << endl;

  }
  return 0;
}
