#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    freopen("alchemy_input.txt", "r", stdin);
    freopen("alchemy_output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {

        ll n;
        cin >> n;
        string c;
        cin >> c;
        ll countA = 0;
        ll countB = 0;
        for (ll i = 0; i < c.size(); i++) {
            if (c[i] == 'A') {
                countA += 1;
            } else {
                countB += 1;
            }
        }

        char ans;

        if (min(countA, countB) < n / 2) {
            ans = 'N';
        } else {
            ans = 'Y';
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}