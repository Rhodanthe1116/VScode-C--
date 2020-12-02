#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a;
ll f(ll i)
{
    return a[i];
}
ll tortoise;
ll period = 1;

void floyd(int x)
{
    // 尋找循環長度的倍數。
    // tortoise是龜，hare是兔。龜一倍速，兔兩倍速。
    ll tortoise = f(x), hare = f(f(x));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // 尋找循環起點。
    // 龜退回起點。龜兔皆一倍速。
    hare = tortoise;
    tortoise = x;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
    }

    // 尋找循環長度。
    // 龜不動，兔一倍速。
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        period++;
    }
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // start
    ll n, k;
    cin >> n >> k;
    a.clear(), a.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    floyd(1);
    vector<ll> cy;

    ll i = tortoise;
    cy.push_back(i);
    while (a[i] != tortoise) {
        cy.push_back(i);
        i = a[i];
    }

    for (ll i = 1; i <= n; i++) {
        }
}
