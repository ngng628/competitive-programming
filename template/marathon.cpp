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
constexpr int INF = (1<<30)-(1<<15);
constexpr ll LINF = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
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
 
   [[nodiscard]] ll nextInt(ll n) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % n;
   }

   [[nodiscard]] ll nextInt(ll a, ll b) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % (b - a) + a;
   }

private:
   uint64_t x, y, z, w;
} rnd;
# endif  // ngng628_library

constexpr int TIME_LIMIT_ms = 3000;

struct State {
   State() = default;

   int score() {
   }
};

void print_ans(const vec<string>& ans, ostream& os = cout) {
}

State init() {
   return State();
}

State sa() {
   // 初期解
   State old_state = init();
   ll old_score = old_state.score();

   // 温度設定
   constexpr double start_temp = 100000, end_temp = 10;

   // ベストなスコア
   State max_state = old_state;
   ll max_score = old_score;

   // 経過時間
   int time_ms;

   int n_loops = 0;

   for (int time_ms = watch.ms(); time_ms <= TIME_LIMIT_ms - 12; ++n_loops, time_ms = watch.ms())
      // ──────────────────────────────────
      //  バックアップ（いらないなら消す）
      // ──────────────────────────────────
      auto backup = old_state;

      // ──────────────────────────────────
      //  遷移
      // ──────────────────────────────────
      backup = modify();
      

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


   // ──────────────────────────────────
   //  焼きなます
   // ──────────────────────────────────
   State sa_state = sa();

   // ──────────────────────────────────
   //  答えの出力
   // ──────────────────────────────────
   print_ans(sa_state.ans);
}
