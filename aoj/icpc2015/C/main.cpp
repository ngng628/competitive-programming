# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define loop for(;;)
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int INF = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
// struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(15); } } setup_io;
# endif  // ngng628_library

typedef string::const_iterator State;

struct Parser {
   Parser() = default;
   int parse(vec<string>& _s) {
      // ────────────────────────────────
      //  1. 文字列を一行に並べる
      // ────────────────────────────────
      string s;
      for (const auto& t : _s) s.append(t);

      // ────────────────────────────────
      //  2. やる
      // ────────────────────────────────
      int ans = 0;
      State begin = s.begin();
      if (*begin == '+') {
         ++begin;
         ans = sum(begin);
      }
      else if (*begin == '*') {
         ++begin;
         ans = prod(begin);
      }
      else {
         ans = ctoi(*begin);
      }

      // ────────────────────────────────
      //  3. 出す
      // ────────────────────────────────
      return ans;
   }

   // ────────────────────────────────
   //! @brief 文字を整数値に変換する
   // ────────────────────────────────
   int ctoi(char c) {
      assert('0' <= c and c <= '9');
      return c - '0';
   }

   // ────────────────────────────────
   //! @brief 足し算を返す
   // ────────────────────────────────
   int sum(State& begin, int level = 0) {
      int res = 0;
      loop {
         int lv = 0;
         while (*begin == '.') {
            ++begin;
            lv++;
         }

         if (lv <= level) {
            rep (_, lv) --begin;
            break;
         }

         if (lv <= level) break;

         if (*begin == '+') res += sum(++begin, lv);
         else if (*begin == '*') res += prod(++begin, lv);
         else res += ctoi(*(begin++));
      }
      return res;
   }
   

   // ────────────────────────────────
   //! @brief 掛け算を返す
   // ────────────────────────────────
   int prod(State& begin, int level = 0) {
      int res = 1;
      loop {
         int lv = 0;
         while (*begin == '.') {
            ++begin;
            lv++;
         }

         if (lv <= level) {
            rep (_, lv) --begin;
            break;
         }

         if (*begin == '+') res *= sum(++begin, lv);
         else if (*begin == '*') res *= prod(++begin, lv);
         else res *= ctoi(*(begin++));
      }
      return res;
   }
};


int32_t main() {
   loop {
      int n;
      cin >> n;
      if (!n) break;
      vec<string> s(n);
      cin >> s;
      Parser solver;
      auto ans = solver.parse(s);
      cout << ans << '\n';
   }
}
