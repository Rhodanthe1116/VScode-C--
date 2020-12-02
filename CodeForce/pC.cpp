#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        a[0] = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }

        map<ll, ll> lastIndex;
        map<ll, ll> maxPeriod;
        for (ll i = 1; i <= n; i++) {
            if (lastIndex[a[i]] == 0) {
            }

            maxPeriod[a[i]] = max(maxPeriod[a[i]], i - lastIndex[a[i]]);
            lastIndex[a[i]] = i;
        }
        for (auto&& [num, period] : maxPeriod) {
            maxPeriod[num] = max(maxPeriod[num], n + 1 - lastIndex[num]);
        }

        ll INF = 1e9;
        vector<ll> ans(n + 1, INF);
        for (auto&& [num, period] : maxPeriod) {
            ans[period] = min(ans[period], num);
        }
        for (ll i = 1; i <= n; i++) {
            if (i > 1) {
                ans[i] = min(ans[i], ans[i - 1]);
            }

            if (ans[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << ans[i] << " ";
            }
        }
        cout << endl;
    }
}