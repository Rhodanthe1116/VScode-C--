#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll req[1000][1000];
ll block[1000][1000];
ll vis[1000][1000];
struct Node {
    ll x, y;
    ll req;
    Node(ll x, ll y, ll req)
    {
        this->x = x;
        this->y = y;
        this->req = req;
    }
};

vector<pair<ll, ll>> ds = {
    { 1, 0 },
    { -1, 0 },
    { 0, 1 },
    { 0, -1 }
};
bool operator<(Node a, Node b)
{
    return a.req > b.req;
}

bool safe(ll a, ll b, ll n, ll m)
{
    if (0 <= a && a < n && 0 <= b && b < m) {
        return true;
    }
    return false;
}
ll INF = 1e18;
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n, m;
    cin >> n >> m;
    ll si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    ll area;
    cin >> area;

    req[si][sj] = 0;
    req[di][dj] = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            req[i][j] = -INF;
            block[i][j] = true;
            vis[i][j] = false;
        }
    }

    block[di][dj] = false;
    block[si][sj] = false;
    for (ll t = 0; t < area; t++) {
        ll i, j, w;
        cin >> i >> j >> w;
        req[i][j] = w;
        block[i][j] = false;
    }

    // cout << "start" << endl;

    ll ans = 0;
    priority_queue<Node> pq;
    pq.push(Node(si, sj, 0));
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        vis[node.x][node.y] = true;

        ans = max(ans, node.req);
        if (node.x == di && node.y == dj) {
            break;
        }

        // cout << "next" << endl;
        for (auto&& d : ds) {
            ll a = node.x + d.first;
            ll b = node.y + d.second;
            if (safe(a, b, n, m) && !vis[a][b] && !block[a][b]) {
                req[a][b] = max(req[a][b], req[node.x][node.y]);
                pq.push(Node(a, b, req[a][b]));
            }
        }
        // cout << "end next" << endl;
    }
    cout << ans << endl;
}