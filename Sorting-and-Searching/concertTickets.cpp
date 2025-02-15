#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<int> prices;
vector<int> pay;

void solve() {
  multiset<int> maxPrice;

  for (int i = 0; i < prices.size(); i++) {
    maxPrice.insert(prices[i]);
  }

  vector<int> ans(pay.size());

  for (int i = 0; i < pay.size(); i++) {
    multiset<int>::iterator it = maxPrice.upper_bound(pay[i]);

    if (it == maxPrice.begin()) {
      ans[i] = -1;
    } else {
      it--;
      ans[i] = *it;
      maxPrice.erase(it);
    }
  }

  for (auto i : ans) {
    cout << i << endl;
  }
}

int main() {
  _

      int n,
      m;
  cin >> n >> m;

  prices.resize(n);
  pay.resize(m);

  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> pay[i];
  }
  solve();
  return 0;
}
