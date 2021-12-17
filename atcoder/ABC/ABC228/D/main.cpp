# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

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

int32_t main() {
   constexpr int n = 1 << 20;
   int Q;
   cin >> Q;
   vec<array<int, 2>> query(Q);
   cin >> query;

   vi a(n, -1);
   mexset<int> st;
   for (auto [t, x] : query) {
      if (t == 1) {
         int h = st.mex(x % n);
         if (a[h % n] != -1) h += 1;
         a[h % n] = x;
         st.insert(h % n);
      }
      else {
         cout << a[x % n] << endl;
      }
   }
}
