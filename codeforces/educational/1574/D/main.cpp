# include <bits/stdc++.h>
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
constexpr int INF = (1LL<<62)-(1LL<<31);
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

int32_t main() {
   // ────────────────────────────────────────────────
   //  1. 入力
   // ────────────────────────────────────────────────
   int n;
   cin >> n;
   vvi a(n);
   rep (i, n) {
      int c;
      cin >> c;
      a[i].resize(c);
      cin >> a[i];
   }
   int m;
   cin >> m;
   vvi b(m, vi(n));
   rep (i, m) rep (j, n) cin >> b[i][j], b[i][j]--;
   sort(all(b));

   // ────────────────────────────────────────────────
   //  2. 「最強」は許可されていますか？
   // ────────────────────────────────────────────────
   vi best;
   rep (i, n) best.pb(len(a[i]) - 1);
   // 最強ができるなら、それを早々と出力
   if (not binary_search(all(b), best)) {
      rep (i, n) cout << best[i] + 1 << " \n"[i == n - 1];
      return 0;
   }

   // ────────────────────────────────────────────────
   //  3. できないやつの 1 つ下位互換
   // ────────────────────────────────────────────────
   int mx_score = -INF;
   pair<int, int> ans_index;  // 答えの b[i] とどれを引くか j の組 (i, j)
   rep (i, m) {
      int sum = 0;
      rep (j, n) sum += a[j][b[i][j]];

      rep (j, n) {
         if (b[i][j] <= 0) continue;
         b[i][j]--;
         if (not binary_search(all(b), b[i])) {
            if (chmax(mx_score, sum - a[j][b[i][j] + 1] + a[j][b[i][j]])) {
               ans_index = {i, j};
            }
         }
         b[i][j]++;
      }
   }

   // ────────────────────────────────────────────────
   //  3. 答えを復元
   // ────────────────────────────────────────────────
   vi ans = b[ans_index.first];
   ans[ans_index.second]--;

   // ────────────────────────────────────────────────
   //  4. 出力
   // ────────────────────────────────────────────────
   rep (i, n) cout << b[ans_index.first][i] + (i == ans_index.second ? 0 : 1) << " \n"[i == n - 1];
}