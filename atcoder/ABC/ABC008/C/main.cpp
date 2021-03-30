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
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
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
template<class T> T scan() { T ret; cin >> ret; return ret; }
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

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

int32_t main() {
   int N;
   cin >> N;
   vi C(N);
   cin >> C;

   vi S(N);
   rep (i, N) {
      rep (j, N) {
         if (i != j and C[i] % C[j] == 0) S[i]++;
      }
   }

   auto ceil = [](int a, int b) { return (a + b - 1) / b; };
   float ans = 0.0;
   rep (i, N) {
      ans += (float) (ceil(S[i]-1, 2) + 1) / (S[i] + 1);
   }

   print(ans);
}


// ────────────────────────────────────────────────────────────────────────────────
//   部分点解法
// ────────────────────────────────────────────────────────────────────────────────

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
   if (rest == 0) f(indexes);
   else {
      if (s < 0) return;
      recursive_comb(indexes, s - 1, rest, f);
      indexes[rest - 1] = s;
      recursive_comb(indexes, s - 1, rest - 1, f);
   }
}

void for_comb(int n, int k, std::function<void(int *)> f) {
   int indexes[k];
   recursive_comb(indexes, n - 1, k, f);
}

void for_perm(int n, std::function<void(int *)> f) {
   int indexes[n];
   rep (i, n) indexes[i] = i;
   do {
      f(indexes);
   } while (std::next_permutation(indexes, indexes + n));
}

void for_perm(int n, int k, std::function<void(int *)> f) {
   for_comb(n, k, [&](int *c_indexes) {
      for_perm(k, [&](int *p_indexes) {
         int indexes[k];
         rep (i, k) indexes[i] = c_indexes[p_indexes[i]];
         f(indexes);
      });
   });
}

void _main() {
   int n;
   cin >> n;
   vi c(n);
   cin >> c;

   int cnt = 0;
   int fact = 0;
   for_perm (n, [&](int* indices) {
      vi p(n);
      rep (i, n) p[i] = c[indices[i]];
      db table(n, true);
      rep (i, n) {
         repr (j, i + 1, n) {
            if (p[j] % p[i] == 0) table[j] ^= true;
         }
      }
      cnt += count(all(table), true);
      fact++;
   });

   print((float) cnt / fact);
}
