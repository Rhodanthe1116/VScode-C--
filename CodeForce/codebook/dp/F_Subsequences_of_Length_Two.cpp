#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 1e9;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -INF)));
    dp[0][0][0] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll ck = 0; ck <= k; ck++) {
            for (ll cnt0 = 0; cnt0 <= n; cnt0++) {
                if (dp[i][ck][cnt0] == -INF) {
                    continue;
                }

                // don't change
                dp[i + 1][ck][cnt0 + (s[i] == t[0])] = max(dp[i + 1][ck][cnt0 + (s[i] == t[0])], dp[i][ck][cnt0] + (s[i] == t[1] ? cnt0 : 0));

                if (ck < k) {
                    // change to t[0]
                    dp[i + 1][ck + 1][cnt0 + 1] = max(dp[i + 1][ck + 1][cnt0 + 1], dp[i][ck][cnt0] + (t[0] == t[1] ? cnt0 : 0));
                    // change to t[1]
                    dp[i + 1][ck + 1][cnt0 + (t[0] == t[1])] = max(dp[i + 1][ck + 1][cnt0 + (t[0] == t[1])], dp[i][ck][cnt0] + cnt0);
                }
            }
        }
    }
    ll ans = -INF;
    for (ll ck = 0; ck <= k; ck++) {
        for (ll cnt0 = 0; cnt0 <= n; cnt0++) {
            ans = max(ans, dp[n][ck][cnt0]);
        }
    }
    cout << ans << endl;
}