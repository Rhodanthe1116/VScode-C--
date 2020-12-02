//

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
        ll n, k;
        cin >> n >> k;
        vector<ll> x(n);
        for (ll i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<ll> y(n);
        for (ll i = 0; i < n; i++) {
            cin >> y[i];
        }
        sort(x.begin(), x.end());
        vector<ll> d1(n, 0);
        vector<ll> d2(n, 0);
        for (ll i = 0, j = 0; i < n; i++) {
            while (x[j] < x[i] - k) {
                j += 1;
            }
            d1[i] = i - j + 1;
        }
        for (ll i = n - 1, j = n - 1; i >= 0; i--) {
            while (x[i] + k < x[j]) {
                j -= 1;
            }
            d2[i] = j - i + 1;
        }
        for (ll i = 1; i < n; i++) {
            d1[i] = max(d1[i], d1[i - 1]);
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (i == 0) {
                ans = d2[0];
                continue;
            }
            ans = max(ans, d1[i - 1] + d2[i]);
        }
        cout << ans << endl;
    }
}