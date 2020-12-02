#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1e10;
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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll dp[n + 1][2];
        for (ll i = 0; i <= n; i++) {
            dp[i][0] = INF;
            dp[i][1] = INF;
        }
        dp[0][1] = 0;
        for (ll i = 0; i <= n; i++) {
            // 1 to kill 1
            if (i + 1 > n) {
                continue;
            }
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 0);
            // 0 to kill 1
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (a[i + 1 - 1] == 1 ? 1 : 0));

            // 0 to kill 2
            if (i + 2 > n) {
                continue;
            }
            ll cost = 0;
            cost += (a[i + 1 - 1] == 1 ? 1 : 0);
            cost += (a[i + 2 - 1] == 1 ? 1 : 0);
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + cost);
            // 1 to kill 2
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + 0);
        }

        ll k = INF;
        k = min(dp[n][1], dp[n][0]);
        cout << k << endl;

        // for (ll i = 0; i <= n; i++) {
        //     cout << dp[i][0] << " ";
        // }
        // cout << endl;
        // for (ll i = 0; i <= n; i++) {
        //     cout << dp[i][1] << " ";
        // }
        // cout << endl;
    }
}