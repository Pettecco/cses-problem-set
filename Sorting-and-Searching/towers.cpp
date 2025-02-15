#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int solve(int arr[], int n) {

  multiset<int> maxCubes;

  int ans = 0;

  for (int i = 0; i < n; i++) {

    multiset<int>::iterator it = maxCubes.upper_bound(arr[i]);

    if (it == maxCubes.end()) {
      ans++;
      maxCubes.insert(arr[i]);
    } else {
      maxCubes.erase(it);
      maxCubes.insert(arr[i]);
    }
  }

  return ans;
}

int main() {
  _ int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve(arr, n) << endl;

  return 0;
}
