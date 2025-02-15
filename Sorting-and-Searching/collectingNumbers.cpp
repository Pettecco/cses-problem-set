#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll solve(ll arr[], int n) {
  ll ans = 1;
  vector<ll> idx(n + 1);

  for (int i = 0; i < n; i++) {
    idx[arr[i]] = i;
  }

  for (int i = 1; i < n; i++) {
    if (idx[i + 1] < idx[i]) {
      ans++;
    }
  }

  return ans;
}

int main() {
  _

      int n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve(arr, n) << endl;
  return 0;
}
