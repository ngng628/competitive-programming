# include <bits/stdc++.h>
# define rep(i, a, b) for (ll i = a; i < ll(b); i++)
# define all(v) std::begin(v), std::end(v)
# define len(v) ll(std::size(v))
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

template <class Type = int>
struct mexset {
   mexset() { 
      s.emplace(numeric_limits<Type>::min(), numeric_limits<Type>::min());
      s.emplace(numeric_limits<Type>::max(), numeric_limits<Type>::max());
   }
   mexset(Type inf, Type sup) { s.emplace(inf, inf), s.emplace(sup, sup); }

   bool contains(const Type x) const {
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      return l <= x && x <= u;
   }

   bool insert(const Type x) {
      auto nit = s.lower_bound({x + 1, x + 1});
      auto it = prev(nit);
      auto [l, u] = *it;
      auto [nl, nu] = *nit;
      if (l <= x && x <= u) {
         mset.insert(x);
         return false;
      }

      if (u == x - 1) {
         if (nl == x + 1) s.erase(it), s.erase(nit), s.emplace(l, nu);
         else s.erase(it), s.emplace(l, x);
      }
      else {
         if (nl == x + 1) s.erase(nit), s.emplace(x, nu);
         else s.emplace(x, x);
      }
      return true;
   }

   bool erase(const Type x) {
      auto it0 = mset.find(x);
      if (it0 != mset.end()) {
         mset.erase(it0);
         return true;
      }
      auto it = prev(s.lower_bound({x + 1, x + 1}));
      auto [l, u] = *it;
      if (x < l || u < x) return false;

      s.erase(it);
      if (x == l and l < u) s.emplace(l + 1, u);
      else if (x == u and l < u) s.emplace(l, u - 1);
      else s.emplace(l, x - 1), s.emplace(x + 1, u);
      return true;
   }

   Type mex(const Type inf = 0) const {
      auto [l, u] = *prev(s.lower_bound({inf + 1, inf + 1}));
      if (l <= inf && inf <= u) return u + 1;
      else return inf;
   }

private:
   set<pair<Type, Type>> s;
   multiset<Type> mset;
};

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   rep (i, 0, n) cin >> a[i];
   string s;
   cin >> s;

   map< char, vector<vector<int>> > mp;
   mp['M'] = vector(4, vector<int>(n + 1, 0));
   mp['E'] = vector(4, vector<int>(n + 1, 0));
   mp['X'] = vector(4, vector<int>(n + 1, 0));
   vector<int> sum_m(n + 1), sum_e(n + 1), sum_x(n + 1);
   for (char c : "MEX"s) {
      rep (i, 0, n) {
         rep (j, 0, 4) mp[c][j][i + 1] = mp[c][j][i];
         mp[c][a[i]][i + 1] += int(s[i] == c);
      }
   }

   // mex = 1 となるのは？
   // 0 を一つ選んでほかは 2 以上
   ll ans = 0;
   rep (i, 0, n) {
      if (s[i] != 'E') continue;
      int v = a[i];
      rep (m, 0, 4) rep (x, 0, 4) {
         ll num1 = mp['M'][m][i] - mp['M'][m][0];
         ll num2 = mp['X'][x][n] - mp['X'][x][i + 1];
         mexset mex;
         mex.insert(-1);
         mex.insert(v);
         mex.insert(m);
         mex.insert(x);
         ans += num1 * num2 * mex.mex();
      }
   }

   cout << ans << endl;
}