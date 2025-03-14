#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  _

      int n,
      x;
  cin >> n >> x;
  vector<pair<ll, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    ll x2 = x - arr[i].first;
    for (int j = i + 1, k = n - 1; j < k; j++) {
      while (arr[j].first + arr[k].first > x2) {
        k--;
      }
      if (j < k && arr[j].first + arr[k].first == x2) {
        cout << arr[i].second << " " << arr[j].second << " " << arr[k].second
             << endl;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
