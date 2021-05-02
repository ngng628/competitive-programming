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
using ll = long long;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
constexpr int INF = 1001001001;
constexpr ll LINF = (1LL<<62)-(1LL<<31);
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
# endif  // ngng628_library

using namespace chrono;
class Stopwatch {
public:
   Stopwatch() { start = system_clock::now(); }
   void reset() noexcept { start = system_clock::now(); }
   [[nodiscard]] int ms() const noexcept { return duration_cast<milliseconds>(system_clock::now() - start).count(); }
   [[nodiscard]] int sec() const noexcept { return duration_cast<seconds>(system_clock::now() - start).count(); }

private:
   system_clock::time_point start;
} watch;

struct Vec2 {
   int y, x;

   Vec2() = default;
   constexpr Vec2(int _y, int _x) : y(_y), x(_x) {}

   constexpr Vec2 operator +() const { return *this; }
   constexpr Vec2 operator -() const { return{ -y, -x }; }
   constexpr Vec2 operator +(const Vec2& other) const { return{ y + other.y, x + other.x }; }
   constexpr Vec2 operator -(const Vec2& other) const { return{ y - other.y, x - other.x }; }
   constexpr Vec2 operator *(int s) const { return{ y * s, x * s }; }
   constexpr Vec2 operator /(int s) const { return{ y / s, x / s }; }
   friend inline constexpr Vec2 operator *(int s, const Vec2& v) { return{ s*v.y, s*v.x }; }

   Vec2& operator +=(const Vec2& other) { y += other.y; x += other.x; return *this; }
   Vec2& operator -=(const Vec2& other) { y -= other.y; x -= other.x; return *this; }
   Vec2& operator *=(int s) { y *= s; x *= s; return *this; }
   Vec2& operator /=(int s) { y /= s; x /= s; return *this; }

   friend istream& operator >>(istream& is, Vec2& v) { return is >> v.y >> v.x; }
   friend ostream& operator <<(ostream& os, const Vec2& v) { return os << v.y << " " << v.x; }
};

constexpr array<Vec2, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
constexpr array<Vec2, 8> dydx8 = {{
   {1, 0}, {0, 1}, {-1, 0}, {0, -1},
   {1, 1}, {-1, -1}, {-1, 1}, {1, -1},
}};

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

   [[nodiscard]] Vec2 randdir() noexcept {
      int idx = randint(4);
      return dydx4[idx];
   }

private:
   uint64_t x, y, z, w;
} rnd;


constexpr int TIME_LIMIT = 2000;
constexpr int H = 50;
constexpr int W = 50;

constexpr char dir(int dy, int dx) {
   if (dy == -1 and dx ==  0) return 'U';
   if (dy ==  0 and dx ==  1) return 'R';
   if (dy ==  1 and dx ==  0) return 'D';
   if (dy ==  0 and dx == -1) return 'L';
   return '\0';
}

constexpr char dir(const Vec2& p) {
   return dir(p.y, p.x);
}

constexpr bool over(const Vec2& p) {
   return p.y < 0 or p.y >= H or p.x < 0 or p.x >= W;
}

constexpr int dist(const Vec2& a, const Vec2& b) {
   return abs(a.y - b.y) + abs(a.x - b.x);
}

Vec2 start;
array<array<int, H>, W> tiles, points;
int last_tile_index = 0;

// array<array<int, H>, W> heat_map;

struct State {
   State()
      : closed(last_tile_index + 1, false)
      , score(0)
      , eval(0)
   {
      now = start;
      closed[tiles[start.y][start.x]] = true;
      score += points[start.y][start.x];
      // eval += heat_map[start.y][start.x];
   }

   vec<State> next_all() {
      State now_state = *this;
      vec<State> nexts;
      for (auto delta : dydx4) {
         auto next_pos = now + delta;
         if (over(next_pos)) continue;
         if (now_state.closed[tiles[next_pos.y][next_pos.x]]) continue;

         now_state.closed[tiles[next_pos.y][next_pos.x]] = true;
         now_state.score += points[next_pos.y][next_pos.x];
         // now_state.eval += heat_map[next_pos.y][next_pos.x];
         now_state.now += delta;
         now_state.moves.pb(dir(delta));

         nexts.pb(now_state);

         now_state.closed[tiles[next_pos.y][next_pos.x]] = false;
         now_state.score -= points[next_pos.y][next_pos.x];
         // now_state.eval -= heat_map[next_pos.y][next_pos.x];
         now_state.now -= delta;
         now_state.moves.pop_back();
      }

      return nexts;
   }

   vi closed;
   ll score;
   ll eval;
   Vec2 now;
   string moves;
};

bool operator <(const State& left, const State& right) {
   return left.score < right.score;
}

State beam_search(State state, int beam_width) {
   priority_queue<State> que;
   State init = state;
   que.push(init);

   ll max_score = 0;
   State max_state = init;

   while (not que.empty() and watch.ms() <= TIME_LIMIT - 15) {
      priority_queue<State> next_que;
      int que_size = len(que);
      rep (i, min(beam_width, que_size)) {
         State s = que.top(); que.pop();
         for (auto&& next : s.next_all()) {
            next_que.push(next);
            if (chmax(max_score, next.score)) max_state = next;
         }
      }
      que = next_que;
   }
   return max_state;
}

int calc_score(const array<array<int, H>, W>& p, const string& s) {
   auto convert = [](char c) -> Vec2 {
      if (c == 'U') return {-1, 0};
      if (c == 'R') return {0, 1};
      if (c == 'D') return {1, 0};
      if (c == 'L') return {0, -1};
      return {0, 0};
   };
   Vec2 now = start;
   ll sum = p[now.y][now.x];
   rep (i, len(s)) {
      now += convert(s[i]);
      sum += p[now.y][now.x];
   }
   return sum;
}

int32_t main() {
   cin >> start;
   rep (i, H) rep (j, W) {
      cin >> tiles[i][j];
      chmax(last_tile_index, tiles[i][j]);
   }
   cin >> points;
   array<array<int, H>, W> original_point = points;

   rep (i, H) rep (j, W) {
      points[i][j] = dist(start, Vec2(i, j));
   }

   State state;

   // rep (i, H) rep (j, W) {
   //    int sum = 0;
   //    Vec2 now(i, j);
   //    for (auto delta : dydx8) {
   //       Vec2 nxt = now + delta;
   //       if (over(nxt)) continue;
   //       if (delta.y == 0 and delta.x == 0) points[nxt.y][nxt.x];
   //       else sum += points[nxt.y][nxt.x] / 7;
   //    }
   //    heat_map[i][j] = sum;
   // }


   State ans = beam_search(state, 50);
   ll max_score = ans.score;
   int time = watch.ms();
   bool flg = true; 
   while (time <= TIME_LIMIT - 10) {
      time = watch.ms();
      if (flg and time >= 1200) {
         points = original_point;
         flg = false;
      }
      int beam_width = rnd.randint(500) + 1;
      int margin = rnd.randint(15);
      array<Vec2, 4> ary = {{
         {0, 0},
         {H-margin, 0},
         {0, W-margin},
         {H-margin, W-margin},
      }};
      for (auto [x, y] : ary) {
         rep (dy, margin) rep (dx, margin) {
            points[y + dy][x + dx] = 200;
         }
      }

      auto s = beam_search(state, beam_width);
      ll scr = calc_score(original_point, s.moves);
      if (chmax(max_score, scr)) {
         ans = s;
      }
      for (auto [x, y] : ary) {
         rep (dy, margin) rep (dx, margin) {
            points[y + dy][x + dx] = original_point[y + dy][x + dx];
         }
      }
   }

   print(ans.moves);
}