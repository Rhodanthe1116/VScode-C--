#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<ll> rrg(n, 0);
    vector<ll> rrl(n, 0);
    vector<ll> lrg(n, 0);
    vector<ll> lrl(n, 0);

    vector<pair<ll, ll>> stk;

    stk.clear();
    for (ll i = n - 1; i >= 0; i--) {
        while (!stk.empty() && h[i] > stk.back().first) {
            stk.pop_back();
        }
        if (stk.empty()) {
            rrg[i] = -1;
        } else {
            rrg[i] = stk.back().second;
        }
        stk.push_back({ h[i], i });
    }

    stk.clear();
    for (ll i = n - 1; i >= 0; i--) {
        while (!stk.empty() && h[i] < stk.back().first) {
            stk.pop_back();
        }
        if (stk.empty()) {
            rrl[i] = -1;
        } else {
            rrl[i] = stk.back().second;
        }
        stk.push_back({ h[i], i });
    }

    stk.clear();
    for (ll i = 0; i < n; i++) {
        while (!stk.empty() && stk.back().first < h[i]) {
            stk.pop_back();
        }
        if (stk.empty()) {
            lrg[i] = -1;
        } else {
            lrg[i] = stk.back().second;
        }
        stk.push_back({ h[i], i });
    }

    stk.clear();
    for (ll i = 0; i < n; i++) {
        while (!stk.empty() && stk.back().first > h[i]) {
            stk.pop_back();
        }
        if (stk.empty()) {
            lrl[i] = -1;
        } else {
            lrl[i] = stk.back().second;
        }
        stk.push_back({ h[i], i });
    }

    vector<vector<ll>> jumps(n);
    for (ll i = 0; i < n; i++) {
        if (rrg[i] != -1)
            jumps[i].push_back(rrg[i]);
        if (rrl[i] != -1)
            jumps[i].push_back(rrl[i]);
        if (lrg[i] != -1)
            jumps[lrg[i]].push_back(i);
        if (lrl[i] != -1)
            jumps[lrl[i]].push_back(i);
    }

    vector<ll> dp(n, 1e10);
    dp[0] = 0;
    for (ll i = 0; i < n; i++) {
        for (auto&& to : jumps[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }

    cout << dp[n-1] << endl;
}