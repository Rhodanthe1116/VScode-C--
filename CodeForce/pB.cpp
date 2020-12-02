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
        ll n, T;
        cin >> n >> T;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> c;
        vector<ll> d;
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == T - a[i]) {
                cnt += 1;
                if (cnt % 2 == 0) {
                    a[i] = 0;
                } else {
                    a[i] = 1;
                }
                continue;
            }

            if (a[i] > T - a[i]) {
                a[i] = 0;
            } else {
                a[i] = 1;
            }
        }
        for (ll i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}