# include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
# define all(v) (v).begin(), (v).end()
using ll = long long;
using VI = vector<ll>;
bool chmax(ll& a, ll b) {
    if (a <= b) {
        a = b;
        return true;
    }
    return false;
}

void Main(ll m, ll n_min, ll n_max, VI& p) {
    if (m == n_max) {
        cout << m << endl;
        return;
    }
    sort(all(p), greater<>());
    ll ans = n_min;
    ll gap_max = -1;
    rep (i, m - 1) {
        if (not (n_min <= i+1 and i+1 <= n_max)) continue;
        ll gap = p[i] - p[i+1];
        if (chmax(gap_max, gap)) {
            ans = i+1;
        }
    }
    cout << ans << endl;
}

int main() {
    while (true) {
        ll m, n_min, n_max;
        cin >> m >> n_min >> n_max;
        if ((m | n_min | n_max) == 0) break;
        VI p(m);
        rep (i, m) cin >> p[i];
        Main(m, n_min, n_max, p);
    }
}
