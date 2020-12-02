#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll n, m;
vector<ll> cost;
vector<ll> dp;
deque<pair<ll, ll>> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> n >> m;
        cost.clear();
        cost.resize(n);
        dp.clear();
        dp.resize(n);
        dq.clear();
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }
        for (int i = 0; i < n; i++) {
            // 隊首超出範圍外
            while (!dq.empty() && dq.front().first < i - m) {
                dq.pop_front();
            }
            
            if (i <= m) {
                dp[i] = 0;
            } else {
                if (dq.empty()) {
                    dp[n - 1] = -1;
                    break;
                } else {
                    dp[i] = dq.front().second;
                }
            }
            if (cost[i]) {
                while (!dq.empty() && dq.back().second >= dp[i] + cost[i]) {
                    dq.pop_back();
                }
                dq.push_back({ i, dp[i] + cost[i] });
            }
        }
        cout << dp[n - 1] << endl;
    }

    return 0;
}