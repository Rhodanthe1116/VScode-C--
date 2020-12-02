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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll len = 40;
    ll cnt[len][2];
    for (ll i = 0; i < len; i++) {
        for (ll j = 0; j < 2; j++) {
            cnt[i][j] = 0;
        }
    }

    for (ll i = 0; i < n; i++) {
        /* code */
        ll num = a[i];
        ll b = 0;
        while (num > 0) {
            
            cnt[b][num / 2];
            b += 1;
            num /= 2;
        }
        
    }
}