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
    string s;
    cin >> s;
    ll a[n][3];
    ll ab[n][3];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 3; j++) {
            a[i][j] = 0;
            ab[i][j] = 0;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == 'a') {
                a[i][0] = 1;
            }
            continue;
        }

        if (s[i] == 'a') {
            a[i][0] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2] + 1;
        } else if (s[i] == 'b') {
            ab[i][1] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
        } else if (s[i] == 'c') {
            ans += ab[i - 1][0] + ab[i - 1][1] + ab[i - 1][2];
        } else {
            a[i][0] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2] + 1;
            ab[i][1] = a[i - 1][0] + a[i - 1][1] + a[i - 1][2];
            ans += ab[i - 1][0] + ab[i - 1][1] + ab[i - 1][2];
        }
        a[i][0] = a[i-1][0] + a[-]
    }

    cout << ans << endl;
}