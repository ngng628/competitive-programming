# include <bits/stdc++.h>
# include <atcoder/modint>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if(sizeof...(args))cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T&& b) { return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T&& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
# endif  // ngng628_library

using mint = atcoder::modint998244353;

template <class Type>
vec<Type> cumsum(vec<Type> a) {
   int n = len(a);
   vec<Type> sums(n+1);
   sums[0] = 0;
   reps (i, n) sums[i] = sums[i-1] + a[i-1];
   return sums;
}

int32_t main() {
   int n;
   cin >> n;
   vec<mint> a(n);
   rep (i, n) {
      int e;
      cin >> e;
      a[i] = e;
   }
   sort(all(a), [](mint x, mint y) {
      return x.val() < y.val();
   });

   mint Ans = 0;
   map<int, int> mp1;
   map<int, int> mp2;
   rep (bit, 1 << n) {
      if (!bit) continue;
      int mx = -INF, mn = INF;
      rep (i, n) {
         if ((bit >> i) & 1) {
            chmax(mx, (int)a[i].val());
            chmin(mn, (int)a[i].val());
         }
      }
      mp1[mx]++;
      mp2[mn]++;
      Ans += mx * mn;
   }

   eprint("===========================");
   rep (i, n) {
      print(i, "|", mp1[a[i].val()], mp2[a[i].val()]);
   }
   eprint("===========================");

   print("realans:", Ans.val());
   
   vec<mint> w(n);
   rep (i, n) {
      w[n - i - 1] = a[i] * mint(2).pow(i);
   }
   auto sums = cumsum<mint>(w);

   mint ans = 0;
   rep (i, n) {
      ans += a[i] * (sums[n - i - 1]);
   }

   // vec<mint> u(n);
   // rep (i, n) {
   //    u[n - i - 1] = a[i] * mint(2).pow(i);
   // }
   // auto sums2 = cumsum<mint>(u);

   // rep (i, n) {
   //    ans += a[i] * (sums2[n - i - 1]);
   // }

   print(ans.val());
}