#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e3 + 5;
ll maze[N][N];
ll n;
ll dx, dy;
ll vis[N][N];
vector<pair<ll, ll>> ds = {
    { 0, 1 },
    { 0, -1 },
    { -1, 0 },
    { 1, 0 }
};
bool safe(ll x, ll y, ll n, ll m)
{
    if (0 <= x && x < n && 0 <= y && y <= m) {
        return true;
    }
    return false;
};

ll sum;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    sum = 0;
    cin >> n;
    cin >> dx >> dy;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> maze[i][j];
            vis[i][j] = false;
        }
    }

    queue<pair<ll, ll>> q;
    vis[dx][dy] = true;
    q.push({ dx, dy });
    while (!q.empty()) {
        pair<ll, ll> cur = q.front();
        ll x = cur.first;
        ll y = cur.second;
        // cout << x << " " << y << endl;
        q.pop();

        sum += 1;
        for (auto&& d : ds) {
            ll tox = x + d.first;
            ll toy = y + d.second;
            if (safe(tox, toy, n, n) && !vis[tox][toy] && abs(maze[tox][toy] - maze[x][y]) <= 2) {
                vis[tox][toy] = true;
                q.push({ tox, toy });
            }
        }
    }
    cout << sum << endl;
}