#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define mod 998244353LL
#define eps 1e-8

using namespace std;

ll powi(ll a, ll b)
{
    ll ret = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ret = ret * a % mod;
    }
    return ret;
}

ll inv(ll a)
{
    return powi(a, mod - 2);
}

ll f[300005], invf[300005];

ll C(int n, int m)
{
    if (n < m)
        return 0;
    return f[n] * invf[m] % mod * invf[n - m] % mod;
}

pair<ll, ll> a[300005];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    f[0] = invf[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % mod;
    invf[n] = inv(f[n]);
    for (int i = n - 1; i; i--)
        invf[i] = invf[i + 1] * (i + 1) % mod;

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() < a[i].first)
            pq.pop();
        ans = (ans + C(pq.size(), k - 1)) % mod;
        pq.push(a[i].second);
    }
    cout << ans << "\n";
    return 0;
}