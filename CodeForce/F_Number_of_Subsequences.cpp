
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a[n];
    ll ab[n];
    ll abc[n];
    for (ll i = 0; i < n; i++) {
        a[i] = 0;
        ab[i] = 0;
        abc[i] = 0;
    }

    ll ans = 0;
    ll qcnt = 0;
    ll term = 1;
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == 'a' || s[i] == '?') {
                a[i] = 1;
                if (s[i] == '?') {
                    term *= 3;
                }
            }
            continue;
        }

        if (s[i] == 'a') {
            a[i] = a[i - 1] + term;
            ab[i] = ab[i - 1];
            abc[i] = abc[i - 1];
        } else if (s[i] == 'b') {
            a[i] = a[i - 1];
            ab[i] = a[i - 1] + ab[i - 1];
            abc[i] = abc[i - 1];
        } else if (s[i] == 'c') {
            a[i] = a[i - 1];
            ab[i] = ab[i - 1];
            abc[i] = abc[i - 1] + ab[i - 1];
        } else {
            abc[i] = abc[i - 1] + abc[i - 1] + abc[i - 1] + ab[i - 1];
            ab[i] = ab[i - 1] + a[i - 1] + ab[i - 1] + ab[i - 1];
            a[i] = a[i - 1] * 3 + term;
            qcnt += 1;
            term *= 3;
        }
        a[i] %= MOD;
        ab[i] %= MOD;
        abc[i] %= MOD;
        term %= MOD;
    }

    // for (ll i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (ll i = 0; i < n; i++) {
    //     cout << ab[i] << " ";
    // }
    // cout << endl;
    // for (ll i = 0; i < n; i++) {
    //     cout << abc[i] << " ";
    // }
    // cout << endl;

    cout << abc[n - 1] << endl;
}