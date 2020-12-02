#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;
vector<vector<ll>> edge;
vector<ll> color;
vector<ll> vis;
vector<ll> cnt(2, 0);
bool ok = true;
ll k;
void dfs(ll x, ll ans)
{
    vis[x] = true;
    color[x] = !color[ans];
    cnt[color[x]] += 1;
    for (auto&& child : edge[x]) {
        if (child == ans) {
            continue;
        }
        if (vis[child]) {

            if (color[child] == color[x]) {
                ok = false;
                return;
            } else {
                continue;
            }
        }

        dfs(child, x);
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    cin >> n >> m;
    k = 0;
    ok = true;
    edge.clear(), edge.resize(n);
    color.clear(), color.resize(n, 0);
    vis.clear(), vis.resize(n, false);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt.clear(), cnt.resize(2, 0);
            dfs(i, i);
            k += min(cnt[0], cnt[1]);
        }
    }

    if (ok) {
        cout << k << endl;
    } else {
        cout << 0 << endl;
    }
}