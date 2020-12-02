#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1e18;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n, m, q;
    cin >> n >> m >> q;

    ll dp[n][n];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v;
        w = 1;
        dp[u][v] = w;
    }

    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (ll i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        if (dp[u][v] < INF) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}