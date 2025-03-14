#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  _ int n;
  cin >> n;
  map<int, int> customers;
  while (n--) {
    int a, b;
    cin >> a >> b;
    customers[a] += 1;
    customers[b] -= 1;
  }
  int ans = 0;
  int currentCustomers = 0;
  for (auto it = customers.begin(); it != customers.end(); it++) {
    currentCustomers += it->second;
    ans = max(ans, currentCustomers);
  }

  cout << ans << endl;
  return 0;
}
