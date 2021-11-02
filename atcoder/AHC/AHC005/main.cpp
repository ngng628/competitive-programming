# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
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
using namespace chrono;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
using pii = pair<int, int>;
constexpr int INF = (1<<30)-(1<<15);
constexpr ll LINF = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
constexpr array<pii, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
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
char to_char(pii p) {
   if (p == make_pair(-1, 0)) return 'U';
   else if (p == make_pair(1, 0)) return 'D';
   else if (p == make_pair(0, -1)) return 'L';
   else return 'R';
}

class Stopwatch {
public:
   Stopwatch() { start = system_clock::now(); }
   void reset() noexcept { start = system_clock::now(); }
   [[nodiscard]] int ms() const noexcept { return duration_cast<milliseconds>(system_clock::now() - start).count(); }
   [[nodiscard]] int sec() const noexcept { return duration_cast<seconds>(system_clock::now() - start).count(); }

private:
   system_clock::time_point start;
} watch;

class Random {
public:
   Random() : x(1859738746), y(9707750167), z(2653432786), w(3463085849) {}
 
   [[nodiscard]] ll randint(ll n) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % n;
   }

   [[nodiscard]] ll randint(ll a, ll b) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % (b - a) + a;
   }

   [[nodiscard]] char randchar() noexcept {
      int r = randint(4);
      if (r == 0) return 'U';
      else if (r == 1) return 'D';
      else if (r == 2) return 'L';
      else return 'R';
   }

   [[nodiscard]] pii randdir() noexcept {
      return dydx4[randint(4)];
   }


private:
   uint64_t x, y, z, w;
} rnd;

// template <typename T>
// struct BIT2D {
//     int H, W;
//     vector<vector<T>> bit;  // データの格納先
//     BIT2D(int H_, int W_) { init(H_, W_); }
//     void init(int H_, int W_) {
//         H = H_ + 1;
//         W = W_ + 1;
//         bit.assign(H, vector<T>(W, 0));
//     }
//     void add(int h, int w, T x) {
//         for (int i = h; i < H; i += (i & -i)) {
//             for (int j = w; j < W; j += (j & -j)) {
//                 bit[i][j] += x;
//             }
//         }
//     }
//     // 1≦i≦h かつ 1≦j≦w
//     T sum(int h, int w) {
//         T s(0);
//         for (int i = h; i > 0; i -= (i & -i)) {
//             for (int j = w; j > 0; j -= (j & -j)) {
//                 s += bit[i][j];
//             }
//         }
//         return s;
//     }
//     // h1≦i<h2 かつ w1≦j<w2
//     T query(int h1, int w1, int h2, int w2) {
//         return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
//     }
// };
# endif  // ngng628_library

constexpr int TIME_LIMIT_ms = 3000;

int n;
pii start;
vvi c;
int r;
vec<pair<int ,int>> roads;

string get_path(vi& prev, int t) {
   vector<int> path;
   for (int cur = t; cur != -1; cur = prev[cur]) {
      path.pb(cur);
   }
   reverse(all(path)); // 逆順なのでひっくり返す
   string res;
   rep (i, len(path)-1) {
      auto [sy, sx] = div(path[i], n);
      auto [ty, tx] = div(path[i + 1], n);
      res.pb(to_char({ty - sy, tx - sx}));
   }

   return res;
}


int node(int y, int x) { return n*y + x; };
int node(pii p) { return n*p.fi + p.se; };
bool over(int y, int x) { return y < 0 or y >= n or x < 0 or x >= n; }
vec<int> next(int nd) {
   auto [y, x] = div(nd, n);
   vec<int> res;
   for (auto [dy, dx] : dydx4) {
      int ny = y + dy;
      int nx = x + dx;
      if (over(ny, nx)) continue;
      if (c[ny][nx] == INF) continue;
      res.pb(node(ny, nx));
   }
   return res;
}

// struct NodeEdgeList {
//    NodeEdgeList() = default;
//    void init() {

//    }
// }nel;

/// 返り値: 新しく closed になったマスの数
int paint(deque<deque<bool>>& closed, int y, int x) {
   int res = 0;
   if (not closed[y][x]) res++;
   closed[y][x] = true;
   // はじめの探索
   for (auto [dy, dx] : dydx4) {
      int u = y, v = x;
      while (not over(u + dy, v + dx) and c[u + dy][v + dx] != INF) {
         u += dy;
         v += dx;
         if (not closed[u][v]) res++;
         closed[u][v] = true;
      }
   }
   return res;
}

struct State {
   State() = default;

   ll score() {
      int v = 0;
      deque closed(n, deque<bool>(n, false));
      auto [y, x] = start;
      // はじめの探索
      v += paint(closed, y, x);

      int tot = 0;
      rep (i, len(ans)) {
         if (ans[i] == 'U') { y += -1; x +=  0; }
         if (ans[i] == 'D') { y +=  1; x +=  0; }
         if (ans[i] == 'L') { y +=  0; x += -1; }
         if (ans[i] == 'R') { y +=  0; x +=  1; }
         if (over(y, x) or c[y][x] == INF) return 0;
         tot += c[y][x];
         v += paint(closed, y, x);
      }

      if (v < r) return round(1e4 * double(v) / r);
      else return round(1e4 + 1e7 * double(n) / tot);
   }

   string ans;
};

void print_ans(const string& ans, ostream& os = cout) {
   os << ans << "\n";
}

State init() {
   State s;
   auto [y, x] = start;
   eprint("n =", n);
   rep (i, n * n * n) {
      auto [dy, dx] = rnd.randdir();
      if (not over(y + dy, x + dx) and c[y + dy][x + dx] != INF) {
         y += dy;
         x += dx;
         if (i <= n and y == start.fi and x == start.se) {
            y -= dy;
            x -= dx;
            continue;
         }
         s.ans.pb(to_char({dy, dx}));
         if (y == start.fi and x == start.se) {
            break;
         }
      }
   }
   return s;
}

/*--------------------------------------------------------------------

【方針】
- 訪れるべき頂点のリスト should_visit_list を作成
  - この頂点を訪れることができれば v == r は必ず満たされる
- 巡回セールスマン問題を解く
  - なるべく高速に
  - bitDP解法は使えない（悲しい）
  - ビームサーチ解法
    - 近そうな頂点を b 個選んでいく
  - 山登り解法
    - 訪れる頂点の順番を乱択
- 焼き鈍しパートは？
  - 訪れるべき頂点のリストを乱択
  - 巡回セールスマン問題パートを乱択

--------------------------------------------------------------------*/


vec<pii> calc_should_visit_list() {
   static std::random_device seed_gen;
   static std::mt19937 engine(seed_gen());
   std::shuffle(all(roads), engine);

   vec<pii> res;
   res.pb(start);
   deque<deque<bool>> closed(n, deque<bool>(n, false));
   int sum = 0;
   for (const auto& road : roads) {
      sum += paint(closed, road.fi, road.se);
      res.pb(road);
      if (sum == len(roads)) break;
   }
   res.pb(start);

   return res;
}

State TSP() {
   vi path;
   vec<pii> should_visit_list = calc_should_visit_list();
   const int n_list = len(should_visit_list);
   // 最近傍
   deque<int> closed(n*n, false);
   pii s = start;
   int sn = node(s);
   path.pb(sn);
   rep (_, n_list - 1) {
      closed[sn] = true;
      int g = 0;
      for (auto& t : should_visit_list) {
         int mn = INF;
         int tn = node(t);
         auto [sy, sx] = div(sn, n);
         auto [ty, tx] = div(tn, n);
         if (not closed[tn] and chmin(mn, abs(ty - sy) + abs(tx - sx))) {
            g = tn;
         }
      }
      path.pb(g);
      sn = g;
   }
   path.pb(node(start));
   // 頑張るなら 2-opt

   State res;
   rep (i, len(path) - 1) {
      vi dist(n*n, INF);
      vi prev(n*n, -1);
      priority_queue<pii, vec<pii>, greater<pii>> pq; // {dist, to}
      dist[path[i]] = 0;
      pq.emplace(dist[path[i]], path[i]);
      while (not pq.empty()) {
         auto [d, now] = pq.top(); pq.pop();
         if (dist[now] < d) continue;
         for (auto& nxt : next(now)) {
            auto [y, x] = div(nxt, n);
            int w = c[y][x];
            if (w >= INF) continue;
            int cost = dist[now] + w;
            if (chmin(dist[nxt], cost)) {
               prev[nxt] = now;
               pq.emplace(cost, nxt);
            }
         }
      }
      res.ans.append(get_path(prev, path[i + 1]));
   }
   return res;
}

State sa() {
   // 初期解
   State old_state = init();
   ll old_score = old_state.score();

   // 温度設定
   constexpr double start_temp = 50, end_temp = 20;

   // ベストなスコア
   State max_state = old_state;
   ll max_score = old_score;

   // ループ回数
   int n_loops = 0;

   for (int time_ms = watch.ms(); time_ms <= TIME_LIMIT_ms - 12; ++n_loops, time_ms = watch.ms()) {
      // ──────────────────────────────────
      //  バックアップ（いらないなら消す）
      // ──────────────────────────────────
      auto backup = old_state;

      // ──────────────────────────────────
      //  遷移
      // ──────────────────────────────────
      // backup = modify();
      

      // ──────────────────────────────────
      //  スコアの再計算
      // ──────────────────────────────────
      ll new_score = backup.score();

      // ──────────────────────────────────
      //  確率 prob で遷移する
      // ──────────────────────────────────
      double temp = start_temp + (end_temp - start_temp) * (time_ms) / TIME_LIMIT_ms;
      double prob = exp(double(new_score - old_score) / temp);
      if (prob > rnd.randint(INF) / (double)INF) {
         old_state = backup;
         old_score = new_score;
      }

      // ──────────────────────────────────
      //  「一番いいもの」を更新
      // ──────────────────────────────────
      if (chmax(max_score, new_score)) {
         max_state = old_state;
      }

      // ──────────────────────────────────
      //  アニメーション
      // ──────────────────────────────────
      # ifndef ONLINE_JUDGE
      // if ( /* 5ループ毎とか */ ) {
      //    eprint("-----BEGIN-----");
      //    print_ans(old_state.ans, cerr);
      //    eprint("-----END-----");
      // }
      # endif
   }

   return max_state;
}


int main() {
   // ──────────────────────────────────
   //  入力
   // ──────────────────────────────────
   cin >> n;
   cin >> start;

   vec<string> _c(n);
   cin >> _c;
   r = 0;
   for (string s : _c) {
      r += count_if(all(s), [](char c){ return c != '#'; });
   }
   c.resize(n);
   rep (i, n) {
      c[i].resize(n);
      rep (j, n) {
         c[i][j] = _c[i][j] == '#' ? INF : int(_c[i][j] - '0');
         if (c[i][j] != INF) roads.eb(i, j);
      }
   }

   // const int V = n*n;
   // dists.resize(V);
   // prevs.resize(V);
   // rep (start, V) {
   //    dists[start].resize(V, INF);
   //    prevs[start].resize(V, -1);
   //    vi& dist = dists[start];
   //    vi& prev = prevs[start];

   //    if (c[start / n][start % n] == INF) {
   //       continue;
   //    }
   //    priority_queue<pii, vec<pii>, greater<pii>> pq; // {dist, to}
   //    dist[start] = 0;
   //    pq.emplace(dist[start], start);
   //    while (not pq.empty()) {
   //       auto [d, now] = pq.top(); pq.pop();
   //       if (dist[now] < d) continue;
   //       for (auto& nxt : next(now)) {
   //          auto [y, x] = div(nxt, n);
   //          int w = c[y][x];
   //          if (w >= INF) continue;
   //          int cost = dist[now] + w;
   //          if (chmin(dist[nxt], cost)) {
   //             prev[nxt] = now;
   //             pq.emplace(cost, nxt);
   //          }
   //       }
   //    }
   // }

   // ──────────────────────────────────
   //  焼きなます
   // ──────────────────────────────────
   State sa_state = TSP();

   // ──────────────────────────────────
   //  答えの出力
   // ──────────────────────────────────
   print_ans(sa_state.ans);

   # ifndef ONLINE_JUDGE
   eprint("./a.out Score =", sa_state.score());
   # endif
}
