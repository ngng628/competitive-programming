# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
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
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using namespace chrono;
using ll = long long;
template<class T> using vec = vector<T>;
constexpr int INF = 1001001001;
constexpr ll LINF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> T scan() { T ret; cin >> ret; return ret; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ os << p.fi << " " << p.se; return os; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
ll powi(int x, int n) { ll p = 1; while (n > 0) { if (n & 1) p *= x; x *= x; n >>= 1; } return p; }
double sq(double x) { return x*x; }
# endif  // ngng628_library

# ifndef utility
# define utility
/// <summary>
/// 数値を領域内に丸めます
/// </summary>
constexpr int Round(int x) { return max(0, min(x, 10000)); }

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

/// <summary>
/// 乱数を生成します
/// </summary>
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

# endif

# ifndef data
# define data
/// <summary>
/// 出力する長方形
/// </summary>
struct Rect {
   int left_x, left_y, right_x, right_y;
   Rect() = default;
   Rect(int lx, int ly, int rx, int ry)
      : left_x(lx), left_y(ly), right_x(rx), right_y(ry) {}
   void set_xyxy(int lx, int ly, int rx, int ry) {
      left_x = lx;
      left_y = ly;
      right_x = rx;
      right_y = ry;
   }

   ll area() const {
      const int width = right_x - left_x;
      const int height = right_y - left_y;
      return width * height;
   }

   bool contains(const Rect& other) const {
      return max(this->left_x, other.left_x) <= min(this->right_x, other.right_x) and max(this->left_y, other.left_y) <= min(this->right_y, other.right_y);
   }

   friend ostream& operator <<(ostream& os, const Rect& rect) {
      printf("%4d %4d %4d %4d", rect.left_x, rect.left_y, rect.right_x, rect.right_y);
      return os;
   }
};

/// <summary>
/// 入力される広告
/// </summary>
struct Ad {
   int x, y, r;
   int id;
   Ad() = default;
   Ad(int _x, int _y, int _r, int _id) : x(_x), y(_y), r(_r), id(_id) {}
   friend ostream& operator <<(ostream& os, const Ad& a) {
      printf("%4d | %4d %4d %7d", a.id, a.x, a.y, a.r);
      return os;
   }
   
   bool contains(const Rect& rect) const {
      return rect.left_x <= x and x < rect.right_x
         and rect.left_y <= y and y < rect.right_y;
   }
};

/// <summary>
/// ゲームの状態
/// </summary>
struct State {
   State() = default;
   State(int n) : rects(n) {}
   vec<Rect> rects;
   friend ostream& operator <<(ostream& os, const State& s) {
      rep (i, len(s.rects)) {
         printf("%3d | ", i);
         os << s.rects[i] << endl;
      }
      return os;
   }
};
# endif

/// <summary>
/// 得点計算
/// </summary>
ll score(const vec<Ad>& ads, const State& state) {
   const vec<Rect>& rects = state.rects;
   const int n = ads.size();

   double tot = 0.0;
   rep (i, n) {
      repr (j, i+1, n) {
         if (rects[i].contains(rects[j])) return -1;
      }
      if (rects[i].left_x >= rects[i].right_x or rects[i].left_y >= rects[i].right_y) {
         return -1;
      }
      double p = not ads[i].contains(rects[i])
               ? 0.0
               : (double) min(rects[i].area(), (ll)ads[i].r) / max(rects[i].area(), (ll)ads[i].r);
      tot += 1.0 - sq(1.0 - p);
   }

   return round(1e9 * tot / n);
}

ll score(const vec<Ad>& ads, const State& state, int idx) {
   const vec<Rect>& rects = state.rects;
   const int n = ads.size();

   if (rects[idx].left_x >= rects[idx].right_x or rects[idx].left_y >= rects[idx].right_y) return -1;

   double tot = 0;
   rep (i, n) {
      if (i != idx and rects[i].contains(rects[idx])) return -1;
      double p = not ads[i].contains(rects[i])
               ? 0.0
               : (double) min(rects[i].area(), (ll)ads[i].r) / max(rects[i].area(), (ll)ads[i].r);
      tot += 1.0 - sq(1.0 - p);
   }

   return round(1e9 * tot / n);
}

/// <summray>
/// 焼きなまし法
/// </summary>
auto sa(const vec<Ad>& ads, State ans, int value) {
   const int n = len(ads);
   const double start_temp = 200000;
   const double end_temp  = 20;
   ll old_score = score(ads, ans);
   constexpr int TIME_LIMIT = 4990;
   int cnt = 0, time = 0;

   ll max_score = old_score;
   State max_state;
   int idx = 0;
   while (time <= TIME_LIMIT) {
      if (++cnt % 124) time = watch.ms();
      auto backup = ans;

      // modify
      if (time <= 3500) idx = (idx + 1) % n;
      else idx = rnd.randint(n);

      if (time < 1024) {
         if (backup.rects[idx].area() >= ads[idx].r) continue;
         int delta = rnd.randint(1, value);
         int where = rnd.randint(4);
         switch (where) {
            case 0: backup.rects[idx].left_x  = Round(backup.rects[idx].left_x  - delta); break;
            case 1: backup.rects[idx].left_y  = Round(backup.rects[idx].left_y  - delta); break;
            case 2: backup.rects[idx].right_x = Round(backup.rects[idx].right_x + delta); break;
            case 3: backup.rects[idx].right_y = Round(backup.rects[idx].right_y + delta); break;
         }
      }
      else {
         int delta = rnd.randint(-value, value);
         int where = rnd.randint(4);
         switch (where) {
            case 0: backup.rects[idx].left_x  = Round(backup.rects[idx].left_x  + delta); break;
            case 1: backup.rects[idx].left_y  = Round(backup.rects[idx].left_y  + delta); break;
            case 2: backup.rects[idx].right_x = Round(backup.rects[idx].right_x + delta); break;
            case 3: backup.rects[idx].right_y = Round(backup.rects[idx].right_y + delta); break;
         }
      }
      ll new_score = score(ads, backup, idx);
      if (chmax(max_score, new_score)) max_state = ans;

      double temp = start_temp + (end_temp - start_temp) * time / TIME_LIMIT;
      double prob = exp((new_score - old_score) / temp);
      if (prob > (double)rnd.randint(INF-1) / INF) {
         ans = backup;
         old_score = new_score;
      }
   }

   return pair{max_score, max_state};
}

/// <summary>
/// 答えを出力
/// </summary>
void print_answer(const vec<Ad>& ads, const State& state) {
   vec<Rect> rects(state.rects.size());
   rep (i, state.rects.size()) {
      int idx = ads[i].id;
      rects[idx] = state.rects[i];
   }

   for (auto& rect : rects) {
      printf("%d %d %d %d\n", rect.left_x, rect.left_y, rect.right_x, rect.right_y);
   }
}

int main() {
   /// ────────────────────────────────────
   ///  入力
   /// ────────────────────────────────────
   int n;
   cin >> n;
   vec<Ad> ads(n);
   rep (i, n) {
      cin >> ads[i].x >> ads[i].y >> ads[i].r;
      ads[i].id = i;
   }
   auto original_ads = ads;

   sort(all(ads), [](const Ad& a, const Ad& b) {
      return hypot(a.x, a.y) < hypot(b.x, b.y);
   });


   /// ────────────────────────────────────
   ///  初期解の生成
   /// ────────────────────────────────────
   State ans(n);
   rep (i, len(ads)) {
      auto& ad = ads[i];
      ans.rects[i] = Rect(ad.x, ad.y, Round(ad.x + 1), Round(ad.y + 1));
   }

   /// ────────────────────────────────────
   ///  焼きなまし
   /// ────────────────────────────────────
   auto [s1, ans1] = sa(ads, ans, 55);
   
   print_answer(ads, ans1);
}
