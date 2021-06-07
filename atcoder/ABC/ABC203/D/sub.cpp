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

int32_t main() {
   int N, K;
   cin >> N >> K;
   vvi A(N, vi(N));
   cin >> A;

   map<int, int> mp;
   rep (i, K) {
      rep (j, K) {
         mp[A[i][j]]++;
      }
   }

   auto solve = [&K](map<int, int> mp) {
      int num = 0;
      for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
         auto p = *it;
         num += p.second;
         if (num > K*K / 2) return p.fi;
      }
      return -1LL;
   };

   int ans = solve(mp);
   rep (i, N - K) {
      if (i % 2 == 0) {
         rep (j, N - K+1) {
            if (j == 0) continue;
            rep (k, K) {
               mp[A[i + k][j-1]]--;
               if (mp[A[i + k][j-1]] == 0) mp.erase(A[i+k][j-1]);
               mp[A[i + k][j + K - 1]]++;
            }

            chmin(ans, solve(mp));
         }
      }
      else {
         rrep (j, N - K) {
            if (j == N-K-1) continue;
            rep (k, K) {
               mp[A[i + k][j - K]]--;
               if (mp[A[i + k][j-K]] == 0) mp.erase(A[i+k][j-K]);
               mp[A[i + k][j]]++;
            }
            chmin(ans, solve(mp));
         }

      }
      // 下にずらす
      if (i & 1) {
         rep (k, K) {
            mp[A[i][k]]--;
            if (mp[A[i][k]] == 0) mp.erase(A[i][k]);
            mp[A[i+K][k]]++;
         }
      }
      else {
         rep (k, K) {
            mp[A[i][N - K + k]]--;
            if (A[i][N - K + k] == 0) mp.erase(A[i][N - K + k]);
            mp[A[i+K][N - K + k]]++;
         }
      }
      chmin(ans, solve(mp));
   }
   print(ans);
}
