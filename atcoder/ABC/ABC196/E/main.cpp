# include <bits/stdc++.h>
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
template<class T> constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
# endif  // ngng628_library

template <typename Func>
class adaptor {
public:
   adaptor(Func f) : f(f) { }

   template <typename T>
   auto operator()(T t) { return f(t); }

   Func f;
};

template <typename Adaptor1, typename Adaptor2>
class mix_adaptor {
public:
   mix_adaptor(Adaptor1 a1, Adaptor2 a2) : a1(a1), a2(a2) { }

   template <typename T>
   auto operator()(T t) { return a2(a1(t)); }

   template <typename ItsFunc>
   mix_adaptor<mix_adaptor, adaptor<ItsFunc>> operator>>(adaptor<ItsFunc> a) {
      return mix_adaptor<mix_adaptor, adaptor<ItsFunc>>(*this, a);
   }

   Adaptor1 a1;
   Adaptor2 a2;
};

template <typename Func>
adaptor<Func> make_adaptor(Func func) {
	return adaptor<Func>(func);
}

int32_t main() {
   int n;
   cin >> n;
   vi a(n), t(n);
   rep (i, n) cin >> a[i] >> t[i];
   int q;
   cin >> q;
   vi x(q);
   cin >> x;
   
   auto f_N = make_adaptor([&](int x){ return t[0] == 1 ? x + a[0] : (t[0] == 2 ? max(x, a[0]) : min(x, a[0]));});
   repr (i, 1, n) {
      switch (t[i]) {
         case 1: {
            auto f = make_adaptor([&](int x){ return x + a[i]; });
            f_N = f_N >> f;
         }
         case 2: {
            auto f = make_adaptor([&](int x){ return max(x, a[i]); });
            f_N = f_N >> f;
         }
         case 3: {
            auto f = make_adaptor([&](int x){ return min(x, a[i]); });
            f_N = f_N >> f;
         }
      }
   }
}
