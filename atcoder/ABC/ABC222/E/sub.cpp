# include <bits/stdc++.h>
# include <atcoder/modint>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
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
void drop(){ cout << '\n'; exit(0); }
template<class T, class... A> void drop(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << ' '; drop(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

using Fp = atcoder::modint998244353;
istream& operator >>(istream& is, Fp& r){ int t; is >> t; r = t; return is; }
ostream& operator <<(ostream& os, const Fp& r){ return os << r.val(); }

int32_t main() {
   // ────────────────────────────────
   //  1. 入力
   // ────────────────────────────────
   int N, M, K;
   cin >> N >> M >> K;
   vi A(M);
   cin >> A;
   rep (i, M) A[i]--;
   vec<vec<pii>> graph(N);
   rep (i, N - 1) {
      int U, V;
      cin >> U >> V;
      U--, V--;
      graph[U].eb(V, i);
      graph[V].eb(U, i);
   }

   // ────────────────────────────────
   //  2. ある辺を何回通るかを調べる
   // ────────────────────────────────
   vi C(N - 1, 0);
   auto dfs = [&](auto&& self, int root, int pre, int goal) -> bool {
      if (root == goal) return true;
      for (auto [child, i] : graph[root]) {
         if (child == pre) continue;
         if (bool in_route = self(self, child, root, goal)) {
            C[i]++;
            return true;
         }
      }
      return false;
   };
   rep (i, M - 1) dfs(dfs, A[i], -1, A[i + 1]);

   // ────────────────────────────────
   //  3. C を何個か選んで X にできるかを調べる
   // ────────────────────────────────
   constexpr int K_MAX = 100000;
   vec<Fp> dp(K_MAX + 1, 0);
   dp[0] = 1;
   for (const auto& e : C) {
      for (int k = K_MAX; k >= e; --k) {
         dp[k] += dp[k - e];
      }
   }

   // ────────────────────────────────
   //  4. 答えを求める
   // ────────────────────────────────
   Fp ans;
   int S = accumulate(all(C), int(0));
   if ((S + K) & 1 or (S + K) < 0) {
      ans = 0;
   }
   else {
      ans = dp[(S + K) / 2];
   }

   cout << ans << endl;
}