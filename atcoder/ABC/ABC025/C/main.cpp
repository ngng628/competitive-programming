# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
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
using namespace std;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator>>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if(sizeof...(args))cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b) { return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
# endif  // ngng628_library

int32_t main() {
   array<array<int, 3>, 2> b;
   rep (i, 2) rep (j, 3) cin >> b[i][j];
   array<array<int, 2>, 3> c;
   rep (i, 3) rep (j, 2) cin >> c[i][j];

   int sum = 0;
   rep (i, 2) sum += reduce(begin(b[i]), end(b[i]));
   rep (i, 3) sum += reduce(begin(c[i]), end(c[i]));
   
   using Board = array<array<int, 3>, 3>;
   auto calc = [&b,c](const Board& board) {
      int res = 0;
      rep (i, 2) {
         rep (j, 3) {
            if (board[i][j] == board[i+1][j]) res += b[i][j];
         }
      }
      rep (i, 3) {
         rep (j, 2) {
            if (board[i][j] == board[i][j+1]) res += c[i][j];
         }
      }
      return res;
   };

   set<Board> visited;
   map<Board, int> memo;
   auto rec = [&](auto&& self, Board board, int turn) -> int {
      if (visited.count(board)) return memo[board];
      visited.insert(board);

      if (turn == 9) {
         return memo[board] = calc(board);
      }

      int minmax = 0;
      if (turn % 2 == 0) {
         minmax = -INF;
         rep (i, 3) rep (j, 3) {
            if (board[i][j] != -1) continue;
            board[i][j] = 1;
            chmax(minmax, self(self, board, turn + 1));
            board[i][j] = -1;
         }
      }
      else {
         minmax = INF;
         rep (i, 3) rep (j, 3) {
            if (board[i][j] != -1) continue;
            board[i][j] = 2;
            chmin(minmax, self(self, board, turn + 1));
            board[i][j] = -1;
         }
      }

      return memo[board] = minmax;
   };

   Board phi;
   rep (i, 3) rep (j, 3) phi[i][j] = -1;
   int ans = rec(rec, phi, 0);
   print(ans);
   print(sum - ans);
}