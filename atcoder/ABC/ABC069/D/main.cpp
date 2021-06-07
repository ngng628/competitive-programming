// 92,147,954,390
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
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
constexpr int INF = (1<<30)-(1<<15);
constexpr int BIG = 1001001;
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

constexpr array<int, 4> deltas = {1, -1, 30, -30};

[[nodiscard]] constexpr int node(const int i, const int j) {
   return 30*i + j;
}

[[nodiscard]] constexpr int node(const pii& p) {
   return 30*p.fi + p.se;
}

[[nodiscard]] constexpr int to_char(const int dy, const int dx) {
   if (dy == -1 and dx == 0) return 'U';
   if (dy == 1 and dx == 0) return 'D';
   if (dy == 0 and dx == -1) return 'L';
   if (dy == 0 and dx == 1) return 'R';
   return '?';
}

int32_t main() {
   const int query = 1000;
   vec<vec<double>> cost(30*30, vec<double>(30*30, 1.0));
   vec<vec<double>> estimates(30*30, vec<double>(30*30, 1.0));
   vvi n_visits(30*30, vi(30*30, 0));
   int sum_correct = 0;
   int sum_edge = 0;

   rep (q, query) {
      // ──────────────────────────────────
      //  入力
      // ──────────────────────────────────
      pii start, goal;
      cin >> start >> goal;

      
      // 平均の算出
      vi row_ave(30, 0);
      rep (i, 30) {
         int cnt = 0;
         double sum = 0.0;
         rep (j, 30-1) {
            if (n_visits[node(i, j)][node(i, j+1)]) {
               sum += cost[node(i, j)][node(i, j+1)];
               cnt++;
            }
         }
         if (cnt != 0) row_ave[i] = sum / cnt;
         else row_ave[i] = 0;
      }
      vi col_ave(30, 0);
      rep (j, 30) {
         int cnt = 0;
         double sum = 0.0;
         rep (i, 30-1) {
            if (n_visits[node(i, j)][node(i+1, j)]) {
               sum += cost[node(i, j)][node(i+1, j)];
               cnt++;
            }
         }
         if (cnt != 0) col_ave[j] = sum / cnt;
         else col_ave[j] = 0;
      }


      // ──────────────────────────────────
      //  ダイクストラ
      // ──────────────────────────────────
      vec<double> dist(30*30, INF);
      vi prev(30*30, -1);
      using pdi = pair<double, int>;
      priority_queue<pdi, vec<pdi>, greater<pdi>> pq; // {dist, to}
      dist[node(start)] = 0.0;
      pq.emplace(dist[node(start)], node(start));
      while (not pq.empty()) {
         auto [d, now] = pq.top(); pq.pop();
         if (dist[now] < d) continue;
         for (auto [dy, dx] : dydx4) {
            auto [y, x] = div(now, 30);
            if (y + dy < 0 or y + dy >= 30 or x + dx < 0 or x + dx >= 30) continue;
            int to = node(y + dy, x + dx);

            double c = 0.0;  // コスト
            if (abs(cost[now][to] - 1.0) <= EPS) {
               if (sum_correct == 0 and sum_edge == 0) c = 3000 + rnd.randint(2000, 4000);
               else if (q >= 250) {
                  if (abs(dy) == 1) c = col_ave[x];
                  else c = row_ave[y];
               }
               else {
                  c = double(sum_correct) / sum_edge;
               }
            }
            else c = cost[now][to];
            if (abs(c) <= EPS) c = double(sum_correct) / sum_edge;

            if (chmin(dist[to], dist[now] + c)) {
               prev[to] = now;
               pq.emplace(dist[now] + c, to);
            }
         }
      }


      // ──────────────────────────────────
      //  復元
      // ──────────────────────────────────
      deque<int> path;
      for (int cur = node(goal); cur != -1; cur = prev[cur]) {
         path.push_front(cur);
      }

      // ──────────────────────────────────
      //  出力
      // ──────────────────────────────────
      string ans;
      // eprint("[経路]");
      // rep (i, len(path)) cerr << "(" << path[i] % 30 << ", " << path[i] / 30 << ")" << " → ";
      // cerr << endl;
      rep (i, len(path) - 1) {
         auto [sy, sx] = div(path[i], 30);
         auto [ty, tx] = div(path[i + 1], 30);
         if (ty - sy == -1 and tx - sx == 0) ans.pb('U');
         else if (ty- sy == 0 and tx - sx == 1) ans.pb('R');
         else if (ty - sy == 1 and tx - sx == 0) ans.pb('D');
         else ans.pb('L');
      }
      const int V = len(path);
      const int E = V - 1;
      print(ans);

      // ──────────────────────────────────
      //  重みの更新
      // ──────────────────────────────────
      int correct;
      cin >> correct;

      sum_correct += correct;
      sum_edge += len(path) - 1;

      int lrud = max({count(all(ans), 'L'), count(all(ans), 'R'), count(all(ans), 'D'), count(all(ans), 'U')});
      string s;
      if (max({count(all(ans), 'L'), count(all(ans), 'R'), count(all(ans), 'D'), count(all(ans), 'U')}) == count(all(ans), 'L')) s.pb('L');
      if (max({count(all(ans), 'L'), count(all(ans), 'R'), count(all(ans), 'D'), count(all(ans), 'U')}) == count(all(ans), 'R')) s.pb('R');
      if (max({count(all(ans), 'L'), count(all(ans), 'R'), count(all(ans), 'D'), count(all(ans), 'U')}) == count(all(ans), 'D')) s.pb('D');
      if (max({count(all(ans), 'L'), count(all(ans), 'R'), count(all(ans), 'D'), count(all(ans), 'U')}) == count(all(ans), 'U')) s.pb('U');

      // if (q % 100 == 0) eprint("[query " + to_string(q) + "]");
      rep (i, len(path) - 1) {
         int a = path[i];
         int b = path[i + 1];
         auto [ay, ax] = div(a, 30);
         auto [by, bx] = div(b, 30);
         int dy = by - ay;
         int dx = bx - ax;

         double ave = double(correct) / E;

         int reliability = (n_visits[a][b] + 1.5) / 2.5;
         int est = abs(dy) == 1 ? col_ave[ax] : row_ave[ay];
         int keisu = [&]() {
            if (est == 0) return 0;
            else {
               // if (q <= 350) eprint("est:", est);
               if (q <= 350) return 1;
               else if (q <= 550) return 5;
               else if (q <= 850) return 2;
               else return 1;
            }
         }();
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
         
         double ave_keisu = 3*double(lrud) / len(ans);
         if (count(all(s), to_char(dy, dx))) ave_keisu = 4*double(lrud) / len(ans);
         else ave_keisu = 4*(1.0 - double(lrud) / len(ans));

         // if (double(mx_cnt) / E >= 0.9) ave_keisu += 3;
         // if (E <= 18) ave_keisu += 1;
         // else if (E <= 23) ave_keisu += 0;
         // else ave_keisu = max(ave_keisu - 1, 0.01);

         // eprint(" +", ave, est);
         // if (q % 100 == 0) {
         //    eprint(ave_keisu, ave);
         //    eprint(keisu, est);
         //    eprint(reliability, cost[a][b]);
         //    eprint();
         // }
         // if (node(10, 0) <= a and a <= node(10, 29) and node(10, 0) <= b and b <= node(10, 29)) {
         //    eprint(">> query", q);
         //    auto [ay, ax] = div(a, 30);
         //    auto [by, bx] = div(b, 30);
         //    eprint("a_pos:", ay, ax);
         //    eprint("b_pos:", by, bx);
         //    eprint(ave_keisu, ave);
         //    eprint(keisu, est);
         //    eprint(reliability, cost[a][b]);
         //    eprint();
         // }

         //double new_cost = (ave_keisu*ave + keisu*est + reliability*cost[a][b]) / (ave_keisu + keisu + reliability);
         double new_cost = (clamp(ave_keisu, 0.5, 3.0)*ave + est + reliability*cost[a][b]) / (reliability + clamp(ave_keisu, 0.1, 3.0) + 1);
         cost[a][b] = cost[b][a] = new_cost;
         n_visits[a][b]++;
         n_visits[b][a]++;
      }
      // eprint("correct:", correct);
      // eprint("predict:", round(dist[node(goal)]));
      // eprint("差分:", round(correct - dist[node(goal)]));
      // eprint();
   }
}
