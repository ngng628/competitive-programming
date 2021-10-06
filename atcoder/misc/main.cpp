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
void drop(){ cout << '\n'; exit(0); }
template<class T, class... A> void drop(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << ' '; drop(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
int powi(int x, int n) { int p = 1; while (n > 0) { if (n & 1) p *= x; x *= x; n >>= 1; } return p; }
# endif  // ngng628_library

typedef string::const_iterator State;

map<char, int> mp;
vec<string> output;
void init_global() {
   mp = map<char, int>();
   output = vec<string>();
}

void skip(State& begin, const string& s);
void declaration(State& begin);
void assignment(State& begin);
void for_statement(State& begin);
int for_loop(State& begin);
void for_assignment(State& begin, int n_loops);
string term_str(State& begin);
string value_str(State& begin);
void print(State& begin);
int expression(State &begin);
int term(State &begin);
int value(State &begin);
int number(State &begin);

//───────────────────────────────────
//! @brief s の文字数だけ読み飛ばす
//───────────────────────────────────
void skip(State& begin, const string& s) { rep (_, len(s)) ++begin; }

//───────────────────────────────────
//! @brief 宣言文
//───────────────────────────────────
void declaration(State &begin) {
   mp[*begin] = 0;
   ++begin;
}

//───────────────────────────────────
//! @brief 代入文
//───────────────────────────────────
void assignment(State& begin) {
   char name = *begin;
   ++begin;
   skip(begin, "<--");
   mp[name] = expression(begin);
}

//───────────────────────────────────
//! @brief for文全体
//───────────────────────────────────
void for_statement(State& begin) {
   vi n_loops;
   n_loops.pb(for_loop(begin));

   loop {
      if (*begin == 'f' and *next(begin) == 'o') {
         n_loops.pb(for_loop(begin));
      }
      else if (*next(begin) == '<') {
         int prod = count(all(n_loops), 0) ? 0 : accumulate(all(n_loops), 1LL, multiplies<int>());
         for_assignment(begin, prod);
         break;
      }
      else if (*next(begin) == 'i') { // print の i
         int prod = count(all(n_loops), 0) ? 0 : accumulate(all(n_loops), 1LL, multiplies<int>());
         if (prod == 0) break;
         string s = "(" + to_string(prod) + ")";
         output.pb(s);
         break;
      }
      else {
         break;
      }
   }
}

//───────────────────────────────────
//! @brief n 個のfor文
//───────────────────────────────────
int for_loop(State& begin) {
   skip(begin, "for(");
   int a = expression(begin);
   skip(begin, ",");
   int b = expression(begin);
   skip(begin, ")");
   return max(b - a + 1, int(0));
}

//───────────────────────────────────
//! @brief 代入for文
//───────────────────────────────────
void for_assignment(State& begin, int n_loops) {
   if (n_loops == 0) return;

   char name = *begin;
   ++begin;
   skip(begin, "<--");
   vec<string> terms;
   while (*begin > 0) terms.pb(term_str(begin));

   int k = 0; // 変数 name の出現回数
   int b = 0; // 変数 name 以外のものを足したもの
   for (string term : terms) {
      if (term[0] == '+') {
         if (term[1] == name) k++;
         else if (isdigit(term[1])) b += stoll(term);
         else b += mp[term[1]];
      }
      else if (term[0] == '-') {
         if (term[1] == name) k--;
         else if (isdigit(term[1])) b += stoll(term);
         else b -= mp[term[1]];
      }
      else {
         if (term[0] == name) k++;
         else if (isdigit(term[0])) b += stoll(term);
         else b += mp[term[0]];
      }
   }

   if (k == 0) {
      mp[name] = b;
   }
   else if (k == 1) {
      mp[name] = b*n_loops + mp[name];
   }
   else {
      int frac = powi(k, n_loops) - 1;
      frac /= k - 1;
      frac *= b;
      mp[name] = frac + mp[name]*powi(k, n_loops);
   }
}

//───────────────────────────────────
//! @brief 項（文字列として）
//───────────────────────────────────
string term_str(State& begin) {
   if (*begin == '+') {
      ++begin;
      return "+" + value_str(begin);
   }
   else if (*begin == '-') {
      ++begin;
      return "-" + value_str(begin);
   }
   else {
      return "+" + value_str(begin);
   }
}

//───────────────────────────────────
//! @brief 値（文字列として）
//───────────────────────────────────
string value_str(State& begin) {
   if (isdigit(*begin)) return to_string(number(begin));
   else {
      char value_name = *begin;
      ++begin;
      return string(1, value_name);
   }
}

//───────────────────────────────────
//! @brief 表示命令
//───────────────────────────────────
void print(State& begin) {
   skip(begin, "print(");
   string s = to_string(expression(begin));
   skip(begin, ")");
   output.push_back(s);
}

//───────────────────────────────────
//! @brief 数式
//───────────────────────────────────
int expression(State &begin) {
   int ret = term(begin);
   loop {
      if (*begin == '+') {
         ++begin;
         ret += term(begin);
      }
      else break;
   }
   return ret;
}

//───────────────────────────────────
//! @brief 項
//───────────────────────────────────
int term(State& begin) {
   if (*begin == '+') {
      ++begin;
      return value(begin);
   }
   else if (*begin == '-') {
      ++begin;
      return -value(begin);
   }
   else {
      return value(begin);
   }
}

//───────────────────────────────────
//! @brief 値
//───────────────────────────────────
int value(State& begin) {
   if (isdigit(*begin)) return number(begin);
   else {
      char value_name = *begin;
      ++begin;
      return mp[value_name];
   }
}

//───────────────────────────────────
//! @brief 整数
//───────────────────────────────────
int number(State& begin) {
   int ret = 0;
   while (isdigit(*begin)) {
      ret *= 10;
      ret += *begin - '0';
      ++begin;
   }
   return ret;
}

//! これはネタです
bool operator &(const vec<string>& s, const vec<string>& t) {
   return s == t;
}

int32_t main() {
   while (true) {
      // ────────────────────────────────────────
      //  1. 入力
      // ────────────────────────────────────────
      int n, m;
      cin >> n >> m;
      if (!(n | m)) break;
      vec<string> S(n), T(m);
      cin >> S >> T;

      // ────────────────────────────────────────
      //  2. ユウちゃんのプログラム
      // ────────────────────────────────────────
      init_global();
      for (string s : S) {
         State begin = s.begin();
         string sub = s.substr(0, 3);
         if (len(sub) == 1) declaration(begin);
         else if (sub[1] == '<') assignment(begin);
         else if (sub == "for") for_statement(begin);
         else print(begin);
      }
      auto yuchan = output;

      // ────────────────────────────────────────
      //  3. レイちゃんのプログラム
      // ────────────────────────────────────────
      init_global();
      for (string t : T) {
         State begin = t.begin();
         string sub = t.substr(0, 3);
         if (len(sub) == 1) declaration(begin);
         else if (sub[1] == '<') assignment(begin);
         else if (sub == "for") for_statement(begin);
         else print(begin);
      }
      auto reikun = output;

      // ────────────────────────────────────────
      //  4. 二人のプログラムの出力の一致判定
      // ────────────────────────────────────────
      puts(yuchan & reikun ? "OK" : "FAIL");
   }
}