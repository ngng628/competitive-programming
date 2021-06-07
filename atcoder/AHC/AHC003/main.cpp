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
using pii = pair<int, int>;
using pdi = pair<double, int>;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
constexpr int INF = (1<<30)-(1<<15);
constexpr ll LINF = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
constexpr array<pair<int, int>, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << endl; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << endl; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << endl; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }

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
      return w % (b - a) + a;;
   }

private:
   uint64_t x, y, z, w;
} rnd;
# endif  // ngng628_library

[[nodiscard]] constexpr int node(const int i, const int j) noexcept { return 30*i + j; }
[[nodiscard]] constexpr int node(const pii& p) noexcept { return 30*p.fi + p.se; }
[[nodiscard]] constexpr int to_char(const int dy, const int dx) noexcept {
   if (dy == -1 and dx == 0) return 'U';
   if (dy == 1 and dx == 0) return 'D';
   if (dy == 0 and dx == -1) return 'L';
   if (dy == 0 and dx == 1) return 'R';
   return '?';
}
[[nodiscard]] constexpr bool over(const int y, const int x) noexcept { return y < 0 or y >= 30 or x < 0 or x >= 30; }
[[nodiscard]] constexpr bool is_vertical(const int dy, const int dx) noexcept { return abs(dy) == 1 and dx == 0; }
[[nodiscard]] constexpr bool is_horizon(const int dy, const int dx) noexcept { return abs(dx) == 1 and dy == 0; }

int main() {
   const int query = 1000;
   const int INIT_COST = -1;
   vec<vec<int>> cost(30*30, vec<int>(30*30, INIT_COST));
   vec<vec<double>> reliability(30*30, vec<double>(30*30, 0.0));
   rep (q, query) {
      if (q % 200 == 0) eprint("[Query " + to_string(q) + "]");
      // ──────────────────────────
      //  入力
      // ──────────────────────────
      pii start, goal;
      cin >> start >> goal; cin.ignore();
      
      // ──────────────────────────
      //  最短経路問題を解く
      // ──────────────────────────
      vec<double> dist(30*30, INF);
      vi prev(30*30, -1);
      priority_queue<pdi, vec<pdi>, greater<pdi>> pq; // {dist, to}
      dist[node(start)] = 0.0;
      pq.emplace(dist[node(start)], node(start));
      while (not pq.empty()) {
         auto [d, now] = pq.top(); pq.pop();
         if (dist[now] < d) continue;
         for (auto [dy, dx] : dydx4) {
            auto [y, x] = div(now, 30);
            if (over(y + dy, x + dx)) continue;
            int to = node(y + dy, x + dx);

            // ──────────────────────────
            //  辺のコストを計算
            // ──────────────────────────
            double c = 1.0;
            const int theta = 1; // 信頼度に対する閾値

            // 辺のコストが未確定な場合
            // - 最も近くにある辺のコストに近似する
            if (cost[now][to] == -1) {
               int nd = INF;  // 近似するノードとのマンハッタン距離
               if (is_vertical(dy, dx)) {
                  rep (i, 29) {
                     int s = node(i, x), t = node(i+1, x);
                     if (reliability[s][t] >= theta and chmin(nd, abs(y - i))) c = cost[s][t];
                  }
               }
               if (is_horizon(dy, dx)) {
                  rep (j, 29) {
                     int s = node(y, j), t = node(y, j+1);
                     if (reliability[s][t] >= theta and chmin(nd, abs(x - j))) c = cost[s][t];
                  }
               }
            }
            // 辺のコストが確定している場合
            // - 信頼度がしきい値以上なら、そのまま使う
            // - （未実装）信頼度がしきい値以下なら、近傍の辺との平均を取る？
            else {
               c = cost[now][to];
            }

            if (chmin(dist[to], dist[now] + c)) {
               prev[to] = now;
               pq.emplace(dist[now] + c, to);
            }
         }
      }

      // ──────────────────────────
      //  出力
      // ──────────────────────────
      deque<int> path;
      for (int cur = node(goal); cur != -1; cur = prev[cur]) path.push_front(cur);
      string ans;
      rep (i, len(path) - 1) {
         auto [sy, sx] = div(path[i], 30);
         auto [ty, tx] = div(path[i + 1], 30);
         ans.pb(to_char(ty - sy, tx - sx));
      }
      const int V = len(path);
      const int E = V - 1;
      print(ans);

      // ──────────────────────────
      //  正しい距離を得る
      // ──────────────────────────
      int correct;
      cin >> correct; cin.ignore();

      // 十分クエリを処理していた場合、
      // 予測との差から信頼度を変動させる

      // 連続する路線の最大値を得る
      auto count_dir = [](const string& s, char dir) {
         const int n = len(s);
         int i = 0;
         int max_ren = 0;
         pii interval;
         while (i < n) {
            while (i < n and s[i] != dir) i++;
            int ren = 1;
            int b, e; // begin, end;
            b = i;
            while (i+1 < n and s[i+1] == dir) ren++, i++;
            e = i+1;
            if (chmax(max_ren, ren)) interval = make_pair(b, e);
            i++;
         }
         return make_pair(max_ren, interval);
      };
      string dirs = "URDL";
      array<pair<int, pii>, 4> dir_cnt;
      int mx_cnt = 0;
      pii interval = {-1, -1};
      rep (i, 4) {
         dir_cnt[i] = count_dir(ans, dirs[i]);
         if (mx_cnt < dir_cnt[i].fi) {
            mx_cnt = dir_cnt[i].fi;
            interval = dir_cnt[i].se;
         }
      }
      if (double(mx_cnt) / E < 0.9) interval = {-1, -1};

      int ave = correct / E;
      rep (i, E-1) {
         int a = path[i], b = path[i+1];
         if (q % 200 == 0){
            eprint("route:", ans);
            eprint("pos:", a / 30, a % 30);
            eprint("pos:", b / 30, b % 30);
            eprint("cost[a][b]:", cost[a][b]);
         }

         if (cost[a][b] == INIT_COST) {
            cost[a][b] = ave;
         }
         else {
            if (interval.fi <= i and i < interval.se) {
               double ave_coefficient = 4*double(mx_cnt) / len(ans);
               int new_cost = (reliability[a][b]*cost[a][b] + ave_coefficient*ave) / (reliability[a][b] + ave_coefficient);
               cost[a][b] = cost[b][a] = new_cost;
               // eprint("(ay, ax), (by, bx)", a / 30, a % 30, b / 30, b % 30);
               // eprint("cost:", ave, cost[a][b]);
               reliability[a][b] = reliability[a][b] + 3;
               reliability[b][a] = reliability[b][a] + 3;
            }
            else {
               int new_cost = (reliability[a][b]*cost[a][b] + ave) / (reliability[a][b] + 1);
               cost[a][b] = cost[b][a] = new_cost;
            }
         }

         if (q % 200 == 0) {
            eprint("new_cost:", cost[a][b]);
            eprint();
         }
      }
   }



   // eprint("[横方向の信頼度]");
   // rep (j, 30) {
   //    rep (i, 29) cerr << reliability[node(i, j)][node(i+1, j)] << " ";
   //    cerr << endl;
   // }

   // eprint("[縦方向の信頼度]");
   // rep (i, 30) {
   //    rep (j, 29) cerr << reliability[node(i,j)][node(i,j+1)] << " ";
   //    cerr << endl;
   // }

   eprint("[横のコスト]");
   rep (j, 30) {
      rep (i, 29) cerr << setw(4) << cost[node(i, j)][node(i+1, j)] << " ";
      cerr << endl;
   }

   eprint("[縦のコスト]");
   rep (j, 29) {
      rep (i, 30) {
         cerr << setw(4) << (int)cost[node(i,j)][node(i,j+1)] << " ";
      }
      cerr << endl;
   }
}
