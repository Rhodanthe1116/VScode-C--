#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{

    freopen("travel_restrictions_input.txt", "r", stdin);
    freopen("travel_restrictions_output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    // start
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n;
        cin >> n;
        string in, out;
        cin >> in >> out;
        bool p[n][n];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                p[i][j] = false;
            }
        }

        for (ll i = 0; i < n; i++) {
            for (ll j = i; j < n; j++) {
                if (i == j) {
                    p[i][i] = true;
                } else {
                    if (p[i][j - 1] && out[j - 1] == 'Y' && in[j] == 'Y') {
                        p[i][j] = true;
                    } else {
                        p[i][j] = false;
                        break;
                    }
                }
            }
            for (ll j = i; j >= 0; j--) {
                if (i == j) {
                    p[i][i] = true;
                } else {
                    if (p[i][j + 1] && out[j + 1] == 'Y' && in[j] == 'Y') {
                        p[i][j] = true;
                    } else {
                        p[i][j] = false;
                        break;
                    }
                }
            }
        }

        cout << "Case #" << t << ":" << endl;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (p[i][j]) {
                    cout << 'Y';
                } else {
                    cout << 'N';
                }
            }
            cout << endl;
        }
    }
}