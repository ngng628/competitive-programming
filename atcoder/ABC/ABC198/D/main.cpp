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

int32_t main() {
   array<string, 3> S;
   rep (i, 3) cin >> S[i];

   set<char> st;
   rep (i, 3) for (char c : S[i]) st.insert(c);
   int n = len(st);
   if (n >= 11) drop("UNSOLVABLE");

   vec<char> chars;
   for (char e : st) chars.pb(e);

   for_perm(10, n, [&](int *idx) {
      map<char, int> mapping;
      rep (i, n) {
         mapping[chars[i]] = idx[i];
      }
      array<int, 3> a = {0, 0, 0};
      rep (i, 3) {
         int base = 1;
         int m = len(S[i]);
         rrep (j, m) {
            if (j == 0 and mapping[S[i][j]] == 0) goto DAME;
            a[i] += base*mapping[S[i][j]];
            base *= 10;
         }
      }

      if (a[0] + a[1] == a[2] and all_of(all(a), [](int e){ return e > 0; })) drop(a[0], a[1], a[2]);
      DAME:;
   });
   print("UNSOLVABLE");
}
