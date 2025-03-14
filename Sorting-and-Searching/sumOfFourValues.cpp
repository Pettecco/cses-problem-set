#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  _ int n, x;
  cin >> n >> x;
  vector<int> values(n);

  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  map<int, pair<int, int>> valuesToPosition;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (valuesToPosition.count(x - values[i] - values[j])) {
        cout << i + 1 << " " << j + 1 << " "
             << valuesToPosition[x - values[i] - values[j]].first + 1 << " "
             << valuesToPosition[x - values[i] - values[j]].second + 1 << endl;
        return 0;
      }
    }
    for (int j = 0; j < i; j++) {
      valuesToPosition[values[i] + values[j]] = {i, j};
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
