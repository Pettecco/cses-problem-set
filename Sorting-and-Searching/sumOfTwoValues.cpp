#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; i++)
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<ll> nums;

int main(){_
  
  int n, target; cin >> n >> target;
  nums.resize(n);
  for(int i = 0; i < n; i++)
    cin >> nums[i];

  vector<ll> sortedNums = nums;

  sort(sortedNums.begin(), sortedNums.end());
  int l = 0, r = n-1;
  int a = -1, b = -1;
  while(l < r){
    if(sortedNums[l] + sortedNums[r] == target){
      a = sortedNums[l];
      b = sortedNums[r];
      break;
    } else if((sortedNums[l] + sortedNums[r]) > target){
      r--;
    } else{
      l++;
    }
  }
  
  if(a == -1){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  bool flagA = true, flagB = true;;
  for(int i = 0; i < n; i++){
    if(nums[i] == a && flagA) {
      a = i;
      flagA = false;
    }
    else if(nums[i] == b && flagB){
      b = i;
      flagB = false;
    }
  }

  cout << a+1 << " " << b+1 << endl;
  return 0;
}
