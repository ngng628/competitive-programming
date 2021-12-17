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

namespace BitOperations {
   constexpr int popcount(int x) { return __builtin_popcountll(x); }
   constexpr int parity(int x) { return __builtin_parityll(x); }
   constexpr int ffs(int x) { return __builtin_ffsll(x); }
   constexpr int clz(int x) { return __builtin_clzll(x); }
   constexpr int ctz(int x) { return __builtin_ctzll(x); }

   constexpr int bit(int x) { return 1LL << x; }
   constexpr int isbit(int x) { return x and (x & -x) == x; }
   constexpr int msb(int x) { return x == 0 ? -1 : 63 - clz(x); }
   constexpr int lsb(int x) { return x == 0 ? 64 : ctz(x); }
   constexpr int allbit(int x) { return (1LL << (x + 1)) - 1;}
}
using namespace BitOperations;

int32_t main() {
   int N, L, R;
   cin >> N >> L >> R;

   int ml = msb(L);
   int mr = msb(R);
   auto f = [&](int i) -> int {
      if (i < ml or mr < i) return 0;
      else if (i == ml and ml == mr) return R - L + 1;
      else if (i == ml) return allbit(i) - L + 1;
      else if (i == mr) return R - bit(i) + 1;
      else return allbit(i) - bit(i) + 1;
   };

   int ans = 0;
   rep (i, 62) ans += f(i) * bool(N & bit(i));
   cout << ans << endl;
}