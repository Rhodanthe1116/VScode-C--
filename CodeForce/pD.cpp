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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += a[i];
        }
        bool ok = true;
        double avg = sum / n;
        if (avg != ll(avg)) {
            ok = false;
            cout << -1 << endl;
            continue;
        }

        ll k = 0;
        a[i] = a[i] - x * i;
        a[j] = a[j] + x * i;

        a[i] = a[j];
    }
}