# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(int)(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
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
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(const char c){ return '0' <= c and c <= '9' ? (c - '0') : -1; }
# endif  // ngng628_library

void rec(const vvi& dp, const vi& a, int i, int j, deque<int>& keiro, vec<deque<int>>& ans) {
   if (i == 0) {
      if (j == 0) {
         ans.push_back(keiro);
      }
      return;
   }

   // 上へ遡る (dp[i-1][j] == 0) だったら無視)
   if (dp[i-1][j]) {
      rec(dp, a, i-1, j, keiro, ans);
   }
   // 左上へ遡る (dp[i-1][j-a[i-1]] == 0 だったら無視)
   if (j-a[i-1] >= 0 && dp[i-1][j-a[i-1]]) {
      keiro.push_front(a[i-1]);
      rec(dp, a, i-1, j-a[i-1], keiro, ans);
      keiro.pop_front();
   }
}

int32_t main() {
   int n;
   cin >> n;
   vi _a(n);
   cin >> _a;

   vi a(n);
   rep (i, n) a[i] = _a[i] % 200;
   vec<deque<int>> mp(200+1); // value -> index;
   rep (i, n) {
      mp[a[i]].push_front(i);
      // mpc[a[i]].push_front(i);
   }
   // rep (i, 200+1) {
   //    if (len(mp[i]) == 0) continue;
   //    print("i:", i);
   //    rep (j, len(mp[i])) cerr << " " << mp[i][j];
   //    cout << "\n";
   // }

   constexpr int K = 200*200;
   vvi dp(n + 1, vi(K + 1, 0));
   dp[0][0] = 1;
   rep (i, n) {
      rep (j, K+1) {
         dp[i+1][j] += dp[i][j];
         if (j + a[i] < K + 1) dp[i+1][j + a[i]] += dp[i][j];
      }
   }

   rep (X, K + 1) {
      deque<int> b, c;
      deque<int> keiro;
      vector<deque<int>> ans;
      rec(dp, a, n, X, keiro, ans);
      if (len(ans) >= 2) {
         b = ans[0];
         c = ans[1];
      }
      else if (len(ans) >= 1) {
         b = ans[0];
         for (int Y = X + 200; Y <= K; Y += 200) {
            deque<int> keiro;
            vector<deque<int>> ans;
            rec(dp, a, n, Y, keiro, ans);
            if (len(ans) >= 1) {
               c = ans[0];
               break;
            }
         }
      }

      if (b.empty() or c.empty()) continue;

      // 構成してみる
      auto cp = mp;
      vi b_idx(len(b));
      rep (i, len(b)) {
         int idx = mp[b[i]].back() + 1;
         mp[b[i]].pop_back();
         b_idx[i] = idx;
      }
      
      vi c_idx(len(c));
      bool ok = true; 
      rep (i, len(c)) {
         if (mp[c[i]].empty()) { ok = false; break; }
         int idx = mp[c[i]].back() + 1;
         mp[c[i]].pop_back();
         c_idx[i] = idx;
      }
      if (not ok) {
         mp = cp;
         continue;
      }
      else {
         print("Yes");
         print(len(b), b_idx);
         print(len(c), c_idx);
         return 0;
      }
   }
   print("No");
}