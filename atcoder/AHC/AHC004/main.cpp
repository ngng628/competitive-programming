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

   [[nodiscard]] ll randchar() noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      t = w % 8;
      return 'A' + t;
   }

private:
   uint64_t x, y, z, w;
} rnd;

vec<string> transposed(const vec<string>& s) {
   const int h = len(s), w = len(s[0]);
   vec<string> r(w, string(h, '?'));
   rep (i, h) rep (k, w) r[k][i] = s[i][k];
   return r;
}
# endif  // ngng628_library

//constexpr int TIME_LIMIT_ms = 3000;
constexpr int TIME_LIMIT_ms = 120000;
constexpr int n = 20;
int m, source_m;
vec<string> s, source_s;

struct State {
   State() = default;
   State(const vec<string>& a) : ans(a), ans_T(transposed(a)) {}

   int score() {
      ll scr = 0;
      int n_spaces = 0;
      for (const string& a : ans) n_spaces += count(all(a), '.');
      int cnt = count_if(all(source_s), [&](const string& s){
         rep (i, n) {
            if ((ans[i] + ans[i]).find(s) != string::npos) return true;
            if ((ans_T[i] + ans_T[i]).find(s) != string::npos) return true;
         }
         return false;
      });
      if (cnt == source_m) scr = round(100000000 * double(2*n*n) / (2*n*n - n_spaces));
      else if (cnt < source_m) scr = round(100000000 * double(cnt) / source_m);
      return scr;
   }

   vec<string> ans;
   vec<string> ans_T;
};

void print_ans(const vec<string>& ans, ostream& os = cout) {
   for (const string& ss : ans) {
      for (char c : ss) os << c;
      os << "\n";
   }
}

State init1() {
   vec<string> ans;
   ans.resize(n);
   rep (i, n) {
      ans[i].resize(n);
      rep (j, n) ans[i][j] = '.'; // rnd.randchar();
   }

   // vec<string> ans;
   // string all_str;
   // rep (i, m) all_str.append(s[i]);
   // ans.resize(n);
   // rep (i, n) ans[i].resize(n);
   // rep (i, n) {
   //    rep (j, n) {
   //       ans[i][j] = all_str[20*i + j];
   //    }
   // }

   // eprint("score:", res.score());
   auto res = State(ans);
   return res;
}

void algo() {
   State state = init1();
   
}

State sa1() {
   // 初期解
   State old_state = init1();
   ll old_score = old_state.score();

   double start_temp = 100000;
   double end_temp   = 10;
   State max_state = old_state;
   ll max_score = old_score;
   int mn = INF, mx = -INF;
   int time_ms;

   int cnt = 0;
   while ((time_ms = watch.ms()) <= TIME_LIMIT_ms - 12) {
      // ──────────────────────────────────
      //  遷移
      // ──────────────────────────────────
      // とりあえず、一点更新
      int wi = rnd.randint(m);
      string word = s[wi];
      int index = rnd.randint(n);
      int jndex = rnd.randint(n);
      int which = rnd.randint(2);

      // バックアップ
      auto backup = old_state;

      if (which) {
         rep (i, len(word)) {
            int idx = (index + i) % n;
            backup.ans[idx][jndex] = word[i];
            backup.ans_T[jndex][idx] = word[i];
         }
      }
      else {
         rep (i, len(word)) {
            int jdx = (jndex + i) % n;
            backup.ans[index][jdx] = word[i];
            backup.ans_T[jdx][index] = word[i];
         }
      }
      

      // スコアの再計算
      ll new_score = backup.score();

      double temp = start_temp + (end_temp - start_temp) * (time_ms) / TIME_LIMIT_ms;
      double prob = exp(double(new_score - old_score) / temp);
      if (prob > rnd.randint(INF) / (double)INF) {
         old_state = backup;
         old_score = new_score;
      }

      // ──────────────────────────────────
      //  一番いいものを更新
      // ──────────────────────────────────
      if (chmax(max_score, new_score)) {
         max_state = old_state;
      }

      //if (time_ms <= 450 or !cnt) {
      //   eprint("-----BEGIN-----");
      //   print_ans(old_state.ans, cerr);
      //   eprint("-----END-----");
      //}
      //cnt++;
      //cnt %= 5;
   }

   return max_state;
}


int main() {
   int _n;
   cin >> _n >> m;
   s.resize(m);
   cin >> s;
   source_m = m;
   source_s = s;
   auto by_len = [](const string& a, const string& b){ return len(a) < len(b); };
   sort(all(s), by_len);

   rep (start, 10) {
      sort(all(s), by_len);
      for (auto it = s.begin(); it != s.end();) {
         if (len(*it) < start) break;
         bool cond = false;
         string sub = it->substr(start);
         auto memo = s.end();
         for (auto jt = it + 1; jt != s.end(); ++jt) {
            if (len(*it) > len(*jt)) continue;
            if (jt->find(sub) != string::npos) {
               memo = jt;
               cond = true;
               break;
            }
         }

         if (cond) {
            *memo = it->substr(0, start) + (*memo);
            it = s.erase(it);
         }
         else ++it;
      }
   }
   m = len(s);

   State sa_state = sa1();

   print_ans(sa_state.ans);
}
