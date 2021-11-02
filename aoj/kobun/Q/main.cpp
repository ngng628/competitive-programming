# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
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
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

using State = string::const_iterator;
void skip(State& it) { while (isspace(*it)) ++it; }
void skip(State& it, char c) { assert(c == *it); ++it; }
void skip(State& it, const string& s) { for (char c : s) { assert(c == *it); ++it; } }
void skip(State& it, int n) { while (n--) ++it; }
string erase_all_space(string s) { s.erase(remove_if(all(s), [](char c){ return isspace(c); }), s.end()); return s; }
int ctoi(char c) { assert('0' <= c and c <= '9'); return c - '0'; }

int32_t main() {
   int h, w;
   cin >> h >> w;
   vec<string> s(h);
   cin >> s;

   struct Parser {
      int h, w;
      vec<string> s;
      string t;
      int y, x;
      char dir;
      int gy, gx;
      map<char, pii> dydx;
      Parser(int _h, int _w, string _s) : h(_h), w(_w), s(_s), dir('N') {
         rep (i, h) rep (j, w) {
            if (s[i][j] == 's') y = i, x = j;
            if (s[i][j] == 'g') gy = i, gx = j;
         }
         dydx['N'] = make_pair(-1, 0);
         dydx['E'] = make_pair(0, 1);
         dydx['S'] = make_pair(1, 0);
         dydx['W'] = make_pair(, -1);
      }
      int parse() {
         State it = t.begin();
         return program(it, true);
      }

      int program(State& it, bool condition) {
         statement(it, condition);
      }

      int statement(State& it, bool condition) {
         if (*it == '[') {
            if_statement(it, condition);
         }
         else if (*it == '{') {
            while_statement(it, condition);
         }
         else {
            // 動作文
         }
      }

      int if_statement(State& it, bool condition) {
         skip(it, '[');
         bool f = false;
         if (*it == '~') {
            f = true;
            ++it;
         }

         condition &= [&]() -> bool {
            if (*it == 'C') {
               auto [dy, dx] = dydx[dir];
               int ny = y + dy, nx = x + dx;
               return (s[ny][nx] == '#') ^ f;
            }
            else if (*it == 'T') return (true) ^ f;
            else return (*it++ == dir) ^ f;
         }();

         program(it, condition);
         skip(it, "]");
      }

      int while_statement(State& it, bool condition) {
         skip(it, '{');
         
         skip(it, '}');
      }
   };
}