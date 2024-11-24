#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){
  _ string s; cin >> s;
  
  int currentAns = 0;
  int ans = 0;

  for(int i = 0; i < (int)s.size(); i++){
    if(s[i] == s[i+1]){
      currentAns++;
    } else{
      currentAns++;
      ans = max(ans, currentAns);
      currentAns = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
