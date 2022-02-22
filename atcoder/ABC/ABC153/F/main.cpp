# include <bits/stdc++.h>
# include <atcoder/lazysegtree>
# define rep(i, n) for (int i = 0; i < int(n); ++i)
# define all(v) std::begin(v), std::end(v)
using namespace std;
using ll = long long;
constexpr int ceil(int a, int b) { return (a + b - 1) / b; }

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return -8e18; }
ll mapping(ll f, ll x){ return f + x; }
ll composition(ll f, ll g){ return f + g; }
ll id(){ return 0; }
using SegmentTree = atcoder::lazy_segtree<ll, op, e, ll, mapping, composition, id>;

int main() {
   int n, D, A;
   cin >> n >> D >> A;
   vector<pair<int, int>> monsters(n);
   for (auto& [x, h] : monsters) cin >> x >> h;
   sort(all(monsters));
   vector<ll> x(n), h(n);
   rep (i, n) {
      x[i] = monsters[i].first;
      h[i] = monsters[i].second;
   }
   SegmentTree seg(h);

   ll ans = 0;
   int p = 0;
   while (p < n) {
      while (p < n and seg.get(p) <= 0) p += 1;
      if (p >= n) break;

      int left = p;
      int right = distance(begin(x), upper_bound(all(x), x[p] + 2*D));
      int cnt = ceil(seg.get(p), A);
      seg.apply(left, right, -A*cnt);
      ans += cnt;
   }

   cout << ans << '\n';
}