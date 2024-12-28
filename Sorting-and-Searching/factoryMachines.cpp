#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int MAXV = 2*(1e5) + 10;

ll machines[MAXV];
int n, t;

bool bs (ll mid, int t) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (mid / machines[i]);
        if(sum >= t) return true;
    }
    return false;
}

int main() {
    _
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    ll l = 1;
    ll r = (*min_element(machines, machines + n)) * t;
    ll ans;

    while (l <= r) {
        ll mid = (l + r) / 2;
        if (bs(mid, t)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}


