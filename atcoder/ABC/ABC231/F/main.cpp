# include <bits/stdc++.h>
# define int ll
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define rrep(i, n) for(int i = int(n) - 1; i >= 0; --i)
# define all(v) std::begin(v), std::end(v)
# define len(v) std::size(v)
using namespace std;
using ll = long long;

//─────────────────────────────────────────────────────────────────
// 座標圧縮
//─────────────────────────────────────────────────────────────────
vector<int> compressed(const vector<int>& a) {
   vector<int> b = a;
   sort(all(b));
   b.erase(unique(all(b)), b.end());
   vector<int> res(len(a));
   rep (i, len(a)) {
      res[i] = distance(b.begin(), lower_bound(all(b), a[i]));
   }
   return res;
}

//─────────────────────────────────────────────────────────────────
// セグメント木
//─────────────────────────────────────────────────────────────────
template <class Monoid, class Mapping>
struct SegmentTree {
   SegmentTree() = default;
   SegmentTree(int n) : SegmentTree(vector<Monoid>(n, Monoid::e())) {}
   SegmentTree(const vector<Monoid>& v) : _n(len(v)) {
      n_leafs = 1;
      while (_n > n_leafs) n_leafs <<= 1;
      val.resize(2*n_leafs, Monoid::e());
      lazy.resize(2*n_leafs, Mapping::id());
      rep (i, _n) val[i + n_leafs - 1] = v[i];
      rrep (p, n_leafs - 1) update(p);
   }
 
   void apply(int l, int r, Mapping f) {
      assert(0 <= l and l < r and r <= _n);
      apply_rec(l, r, f, 0, 0, n_leafs);
   }
 
   Monoid prod(int l, int r) {
      assert(0 <= l and l < r and r <= _n);
      return prod_rec(l, r, 0, 0, n_leafs);
   }
 
private:
   int _n, n_leafs;
   vector<Monoid> val;
   vector<Mapping> lazy;
 
   void update(int p) {
      val[p] = val[2*p + 1] * val[2*p + 2];
   }
 
   void eval(int p) {
      if (lazy[p].is_id()) return;
 
      if (p < n_leafs - 1) {
         lazy[2*p + 1] = lazy[2*p + 1] * lazy[p];
         lazy[2*p + 2] = lazy[2*p + 2] * lazy[p];
      }
 
      val[p] = lazy[p] * val[p];
      lazy[p] = Mapping::id();
   }
 
   void apply_rec(int a, int b, Mapping f, int p, int l, int r) {
      eval(p);
      if (a <= l and r <= b) {
         lazy[p] = f;
         eval(p);
      }
      else if (b > l and r > a) {
         apply_rec(a, b, f, 2*p + 1, l, (l + r) / 2);
         apply_rec(a, b, f, 2*p + 2, (l + r) / 2, r);
         update(p);
      }
   }
 
   Monoid prod_rec(int a, int b, int p, int l, int r) {
      eval(p);
      if (b <= l or r <= a) {
         return Monoid::e();
      }
      else if (a <= l and r <= b) {
         return val[p];
      }
      else {
         Monoid vl = prod_rec(a, b, 2*p + 1, l, (l + r) / 2);
         Monoid vr = prod_rec(a, b, 2*p + 2, (l + r) / 2, r);
         return vl * vr;
      }
   }
};
 
struct Monoid {
   ll val;
   int size;
   static Monoid e() { return Monoid{ 0ll, 0 }; }
};
Monoid operator *(const Monoid& a, const Monoid& b) { return Monoid{ a.val + b.val, a.size + b.size }; }
struct Mapping {
   ll val;
   static Mapping id() { return Mapping{ 0ll }; }
   bool is_id() { return val == id().val; }
};
Mapping operator *(const Mapping& f, const Mapping& g) { return Mapping{ f.val + g.val }; }
Monoid operator *(const Mapping& f, const Monoid& x) { return Monoid{ x.val + x.size * f.val, x.size }; }
 
int32_t main() {
   //─────────────────────────────────────────────────────────────────
   // 1. 入力
   //─────────────────────────────────────────────────────────────────
   int n;
   cin >> n;
   vector<int> a(n), _b(n);
   for (auto& item : a) cin >> item;
   for (auto& item : _b) cin >> item;
 
   //─────────────────────────────────────────────────────────────────
   // 2. 座標圧縮
   //─────────────────────────────────────────────────────────────────
   auto b = compressed(_b);
 
   //─────────────────────────────────────────────────────────────────
   // 3. セグ木の初期化
   //─────────────────────────────────────────────────────────────────
   vector<Monoid> ini(n, {0, 1});
   SegmentTree<Monoid, Mapping> seg(ini);
 
   //─────────────────────────────────────────────────────────────────
   // 4. プレゼントをソートする
   //─────────────────────────────────────────────────────────────────
   vector<int> order(n);
   iota(all(order), 0);
   sort(all(order), [&a, &b](int i, int j){ return a[i] == a[j] ? b[i] < b[j] : a[i] > a[j]; });
 
   //─────────────────────────────────────────────────────────────────
   // 5. 解く
   //─────────────────────────────────────────────────────────────────
   ll ans = 0;
   for (auto i = order.begin(); i != order.end(); ++i) {
      int cnt = 1;
      while (next(i) != order.end() and a[*i] == a[*next(i)] and b[*i] == b[*next(i)]) {
         cnt += 1;
         ++i;
      }
 
      // 自分自身以外で条件を満たす点の数
      ll s = seg.prod(0, b[*i] + 1).val ;
      s *= cnt; // それが cnt 回重複してカウントされる
 
      // 自分自身は「i と i を選ぶことを許して」カウント
      // card([0..cnt] x [0..cnt]) = cnt**2
      ll t = cnt * cnt;
 
      ans += s + t;
      seg.apply(b[*i], b[*i] + 1, Mapping{ cnt });
   }
 
   //─────────────────────────────────────────────────────────────────
   // 6. 出力
   //─────────────────────────────────────────────────────────────────
   cout << ans << '\n';
}
