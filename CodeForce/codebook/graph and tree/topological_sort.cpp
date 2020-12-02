#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> order;
vector<vector<ll>> g;
vector<bool> vis;

void dfs(ll node)
{
    vis[node] = true;
    for (auto&& child : g[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
    order.push_back(node);
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> edges;
        g.clear(), g.resize(n);
        vis.clear(), vis.resize(n, false);
        order.clear();
        for (ll i = 0; i < m; i++) {
            ll type, x, y;
            cin >> type >> x >> y;
            x -= 1;
            y -= 1;
            if (type == 1) {
                g[x].push_back(y);
            }
            edges.push_back({ x, y });
        }

        for (ll i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        vector<ll> pos(n);
        for (ll i = 0; i < n; i++) {
            pos[order[i]] = i;
        }

        bool cyclic = false;
        for (ll x = 0; x < n; x++) {
            for (auto&& child : g[x]) {
                if (pos[child] < pos[x]) {
                    cyclic = true;
                }
            }
        }

        if (!cyclic) {
            cout << "YES" << endl;
            for (auto [x, y] : edges) {
                if (pos[x] < pos[y]) {
                    cout << x + 1 << " " << y + 1 << endl;
                } else {
                    cout << y + 1 << " " << x + 1 << endl;
                }
            }

        } else {
            cout << "NO" << endl;
        }
    }
}