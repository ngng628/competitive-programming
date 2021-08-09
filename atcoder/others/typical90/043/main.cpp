# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
using __long_double = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
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

constexpr array<pair<int, int>, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
int to_int(pii p) {
   if (p == make_pair(int(-1), int(0))) return 0;
   else if (p == make_pair(int(1), int(0))) return 1;
   else if (p == make_pair(int(0), -int(1))) return 2;
   else return 3;
}

struct Node {
   Node() = default;
   Node(int _y, int _x, int _dir) : y(_y), x(_x), dir(_dir) {}
   int y, x, dir;
   friend bool operator <(Node a, Node b) {
      tuple<int, int, int> s = make_tuple(a.y, a.x, a.dir);
      tuple<int, int, int> t = make_tuple(b.y, b.x, b.dir);
      return s < t;
   }
};

int32_t main() {
   int h, w;
   cin >> h >> w;
   pii start, goal;
   cin >> start >> goal;
   start.fi--, start.se--;
   goal.fi--, goal.se--;
   vs S(h);
   cin >> S;
   auto over = [&h, w](int y, int x) { return y < 0 or y >= h or x < 0 or x >= w; };

   // dp[i][j][r] = マス i, j で向き r になるまでの方向転換の回数
   vvvi dp(h, vvi(w, vi (4, INF)));
   priority_queue<pair<int, Node>, vec<pair<int, Node>>, greater<pair<int, Node>>> pq; // {dist, to}
   rep (dir, 4) dp[start.fi][start.se][dir] = 0;
   rep (dir, 4) pq.emplace(dp[start.fi][start.se][dir], Node(start.fi, start.se, dir));
   
   while (not pq.empty()) {
      auto [d, now] = pq.top(); pq.pop();
      if (dp[now.y][now.x][now.dir] < d) continue;
      // 次の状態
      vec<Node> nexts;
      for (auto [dy, dx] : dydx4) {
         int ny = now.y + dy;
         int nx = now.x + dx;
         if (not over(ny, nx) and S[ny][nx] == '.') {
            nexts.eb(ny, nx, to_int({dy, dx}));
         }
      }
      for (auto [ny, nx, dir] : nexts) {
         int cost = dp[now.y][now.x][now.dir] + (now.dir == dir ? 0 : 1);
         if (chmin(dp[ny][nx][dir], cost)) {
            pq.emplace(cost, Node(ny, nx, dir));
         }
      }
   }

   print(*min_element(all(dp[goal.fi][goal.se])));
}