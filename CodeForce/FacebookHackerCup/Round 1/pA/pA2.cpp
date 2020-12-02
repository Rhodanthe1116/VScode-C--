#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1e5 + 7;

const ll maxn = 5 * 1e5 + 5;
const ll MAXW = maxn;
ll a[maxn];
ll sum[maxn << 2], exc[maxn << 2];
void mallain(ll k)
{
    sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
void pushdown(ll lenl, ll lenr, ll k) //標記下放，並更細節點資訊
{
    if (exc[k]) {
        exc[k << 1] = exc[k];
        exc[k << 1 | 1] = exc[k];
        sum[k << 1] = exc[k] * lenl;
        sum[k << 1 | 1] = exc[k] * lenr;
        exc[k] = 0;
    }
}
void build(ll l, ll r, ll k)
{
    if (l > r)
        return;
    if (l == r) {
        sum[k] = a[l];
        exc[k] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, k << 1);
    build(mid + 1, r, k << 1 | 1);
    mallain(k);
}
void change(ll l, ll r, ll cl, ll cr, ll k, ll newp)
{
    if (l > r || cl > r || cr < l)
        return;
    if (l >= cl && r <= cr) {
        sum[k] = newp * (r - l + 1); //在發現現在區域小於需要更新區域時
        exc[k] = newp; //更新節點的結果，並增加延遲標記exc，用於之後的標記下放
        return;
    }
    ll mid = (l + r) >> 1;
    pushdown(mid - l + 1, r - mid, k);
    change(l, mid, cl, cr, k << 1, newp);
    change(mid + 1, r, cl, cr, k << 1 | 1, newp);
    mallain(k);
}
ll query(ll l, ll r, ll ql, ll qr, ll k)
{
    if (l > r || ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return sum[k];
    ll mid = (l + r) >> 1, ans = 0;
    pushdown(mid - l + 1, r - mid, k); //每一層詢問執行到這一步，為了下一次遞迴更新葉節點資訊
    if (mid >= l)
        ans += query(l, mid, ql, qr, k << 1);
    if (mid < r)
        ans += query(mid + 1, r, ql, qr, k << 1 | 1);
    return ans;
}

bool p[maxn];
ll sumP[maxn << 2], excP[maxn << 2];
void mallainP(ll k)
{
    sumP[k] = sumP[k << 1] + sumP[k << 1 | 1];
}
void pushdownP(ll lenl, ll lenr, ll k) //標記下放，並更細節點資訊
{
    if (excP[k]) {
        excP[k << 1] = excP[k];
        excP[k << 1 | 1] = excP[k];
        sumP[k << 1] = excP[k] * lenl;
        sumP[k << 1 | 1] = excP[k] * lenr;
        excP[k] = 0;
    }
}
void buildP(ll l, ll r, ll k)
{
    if (l > r)
        return;
    if (l == r) {
        sumP[k] = p[l];
        excP[k] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    buildP(l, mid, k << 1);
    buildP(mid + 1, r, k << 1 | 1);
    mallainP(k);
}
void changeP(ll l, ll r, ll cl, ll cr, ll k, ll newp)
{
    if (l > r || cl > r || cr < l)
        return;
    if (l >= cl && r <= cr) {
        sumP[k] = newp * (r - l + 1); //在發現現在區域小於需要更新區域時
        excP[k] = newp; //更新節點的結果，並增加延遲標記excP，用於之後的標記下放
        return;
    }
    ll mid = (l + r) >> 1;
    pushdownP(mid - l + 1, r - mid, k);
    changeP(l, mid, cl, cr, k << 1, newp);
    changeP(mid + 1, r, cl, cr, k << 1 | 1, newp);
    mallainP(k);
}
ll queryP(ll l, ll r, ll ql, ll qr, ll k)
{
    if (l > r || ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return sumP[k];
    ll mid = (l + r) >> 1, ans = 0;
    pushdownP(mid - l + 1, r - mid, k); //每一層詢問執行到這一步，為了下一次遞迴更新葉節點資訊
    if (mid >= l)
        ans += queryP(l, mid, ql, qr, k << 1);
    if (mid < r)
        ans += queryP(mid + 1, r, ql, qr, k << 1 | 1);
    return ans;
}

int main()
{
    freopen("perimetric_chapter_2_validation_input.txt", "r", stdin);
    freopen("perimetric_chapter_2_validation_output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {

        ll n, k;
        cin >> n >> k;

        vector<ll> l(n);
        for (ll i = 0; i < k; i++) {
            cin >> l[i];
        }

        ll al, bl, cl, dl;
        cin >> al >> bl >> cl >> dl;

        vector<ll> w(n);
        for (ll i = 0; i < k; i++) {
            cin >> w[i];
        }

        ll aw, bw, cw, dw;
        cin >> aw >> bw >> cw >> dw;

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
            w[i] = ((aw * w[i - 2] + bw * w[i - 1] + cw) % dw) + 1;
        }
        for (ll i = k; i < n; i++) {
            h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
        }

        build(1, MAXW, 0);
        buildP(1, MAXW, 0);
        vector<ll> P(n, 0);
        for (ll i = 0; i < n; i++) {
            if (i == 0) {
                P[i] = 0;
            } else {
                P[i] = P[i - 1];
            }

            ll left = l[i];
            ll right = l[i] + w[i];
            // find total edge
            ll totalEdge = query(1, MAXW, left, right, 1);
            ll All = query(1, MAXW, 1, n, 1);

            P[i] -= totalEdge * h[i];
            // delete edge
            change(1, MAXW, left, right, 1, 0);
            bool leftNotOverlap = queryP(1, MAXW, left - 1, left, 1) == 0;
            if (leftNotOverlap) {
                change(1, MAXW, left, left, 1, 1);
                if (totalEdge >= 1) {
                    P[i] += h[i];
                }
            }
            All = query(1, MAXW, 1, n, 1);

            bool rightNotOverlap = queryP(1, MAXW, right - 1, right, 1) == 0;
            if (rightNotOverlap) {
                change(1, MAXW, right, right, 1, 1);
                if (totalEdge >= 1) {
                    P[i] += h[i];
                }
            }
            All = query(1, MAXW, 1, MAXW, 1);

            if (leftNotOverlap && rightNotOverlap) {
                P[i] += h[i] * 2;
            }

            ll preLen = queryP(1, MAXW, left, right, 1);
            changeP(1, MAXW, left, right - 1, 1, 1);
            ll curLen = queryP(1, MAXW, left, right, 1);
            ll addLen = curLen - preLen;
            P[i] += addLen * 2;
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

        cout << "P: ";
        for (ll i = 0; i < n; i++) {
            cout << P[i] << " ";
        }
        cout << endl;

        ll ans = 1;
        for (ll i = 0; i < n; i++) {
            P[i] %= MOD;
            ans *= P[i];
            ans %= MOD;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}