#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<string> solve(int n){
  if(n == 1){
    return {"0", "1"};
  }

  vector<string> nextCode = solve(n-1);
  vector<string> reversedCode = nextCode;
  reverse(reversedCode.begin(), reversedCode.end());

  int nextSize = nextCode.size();
  int i = 0;
  while(i < nextSize){
    string appendZero = "0" + nextCode[i];
    nextCode[i] = "1" + reversedCode[i];
    nextCode.push_back(appendZero);
    i++;
  }
  return nextCode;
}

int main(){
  _ int n; cin >> n;
  vector<string> ans = solve(n);
  for(auto code : ans){
    cout << code << endl;
  }
  return 0;
}
