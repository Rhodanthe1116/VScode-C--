#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n, k;
    cin >> n >> k;
    vector<ll> time;
    vector<ll> a(n, 0);
    for (ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        a[l] += 1;
        a[r] -= 1;
        time.push_back(l);
        time.push_back(-r);
    }
    ll sum = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (sum >= k) {
            ans += 1;
        }
        sum += a[i];
        
    }

      cout << ans << endl;
}