#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9 + 7;

ll n, k, w;

bool isOverlap(ll li, ll lj)
{
    if (li + w >= lj) {
        return true;
    } else {
        return false;
    }
};
int main()
{

    freopen("perimetric_chapter_1_input.txt", "r", stdin);
    freopen("perimetric_chapter_1_output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    // start
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        cin >> n >> k >> w;
        vector<ll> l(n);
        for (ll i = 0; i < k; i++) {
            cin >> l[i];
        }
        ll al, bl, cl, dl;
        cin >> al >> bl >> cl >> dl;
        vector<ll> h(n);
        for (ll i = 0; i < k; i++) {
            cin >> h[i];
        }
        ll ah, bh, ch, dh;
        cin >> ah >> bh >> ch >> dh;

        // TODO calculate l, h
        for (ll i = k; i < n; i++) {
            l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
        }
        for (ll i = k; i < n; i++) {
            h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
        }

        vector<ll> p(n, 0);

        ll preMaxH = 0;
        for (ll i = 0; i < n; i++) {
            if (i == 0) {
                p[i] += w * 2 + h[i] * 2;
            } else {
                p[i] = p[i - 1];
                bool overlap = isOverlap(l[i - 1], l[i]);

                // debug
                // cout << "is overlap: " << overlap << endl;
                if (overlap) {
                    ll maxOverlapedRectangleH = 0;
                    ll j = i - 1;
                    while (0 <= j && isOverlap(l[j], l[i])) {
                        maxOverlapedRectangleH = max(maxOverlapedRectangleH, h[j]);
                        j--;
                    }

                    if (h[i] >= maxOverlapedRectangleH && preMaxH >= maxOverlapedRectangleH) {
                        p[i] += ((min(h[i], preMaxH) - maxOverlapedRectangleH) * 2);
                    }
                    // h
                    if (h[i] >= preMaxH) {
                        p[i] += ((h[i] - preMaxH) * 2);
                    }
                    // l
                    p[i] += ((l[i] - l[i - 1]) * 2);
                } else if (!overlap) {
                    p[i] += (w * 2 + h[i] * 2);
                    preMaxH = h[i];
                }
            }

            preMaxH = max(preMaxH, h[i]);
        }

        // debug
        // cout << "L: ";
        // for (ll i = 0; i < n; i++) {
        //     cout << l[i] << " ";
        // }
        // cout << endl;
        // cout << "H: ";
        // for (ll i = 0; i < n; i++) {
        //     cout << h[i] << " ";
        // }
        // cout << endl;

        // cout << "P: ";
        // for (ll i = 0; i < n; i++) {
        //     cout << p[i] << " ";
        // }
        // cout << endl;

        ll ans = 1;
        for (ll i = 0; i < n; i++) {
            p[i] %= MOD;
            ans *= p[i];
            ans %= MOD;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}