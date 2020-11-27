# include <bits/stdc++.h>
# define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

// 1-index
struct FenwickTree {
    ll n;
    vector<ll> bit;
    FenwickTree(ll _n) : n(_n), bit(n+1, 0) {}

    void add(ll i, ll x) {
        if (i == 0) return;
        for (ll k = i; k <= n; k += (k & -k)) bit[k]+=x;
    }

    ll sum(ll i) {
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k -= (k & -k)) s+=bit[k];
        return s;
    }

    ll lower_bound(ll x) {
        if (x <= 0) return 0;
        else {
            ll i = 0; ll r = 1;
            while (r < n) r <<= 1;
            for (ll dist = r; dist > 0; dist >>= 1) {
                if (i + dist < n and bit[i + dist] < x) {
                    x -= bit[i + dist];
                    i += dist;
                }
            }
            return i+1;
        }
    }
};

ll solve(int n, FenwickTree ft, bool sgn) {
    ll cost = 0;
    for (int i = 0, sign = sgn; i < n; ++i, sign ^= 1) {
        int sum = ft.sum(i+1);
        if (sign) {
            if (sum <= 0) {
                ft.add(i+1, -sum + 1);
                cost += abs(-sum + 1);
            }
        }
        else {
            if (sum >= 0) {
                ft.add(i+1, -sum - 1);
                cost += abs(-sum - 1);
            }
        }
    }
    return cost;
}

int main() {
    int n; cin >> n;
    vector<int> a(n); rep (i, n) cin >> a[i];

    FenwickTree ft(n);
    rep (i, n) ft.add(i+1, a[i]);

    cout << min(solve(n, ft, 0), solve(n, ft, 1)) << endl;

    return 0;
}

