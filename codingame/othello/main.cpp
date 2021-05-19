# define _GLIBCXX_DEBUG
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
using ull = uint64_t;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
constexpr int INF = (1<<30)-(1<<15);
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

string to_bin(ull x, int board_size = 8) {
   string s;
   while (x > 0) {
      s.pb((x % 2) + '0');
      x /= 2;
   }
   reverse(all(s));
   string zeros(max(board_size*board_size - len(s), 0), '0');
   return zeros + s;
}

ull to_flag(ull x, ull y) {
   ull mask = 0x8000000000000000;
   mask >>= x;
   mask >>= 8*(y);
   return mask;
}

ull to_flag(string s) {
   return to_flag(s[0] - 'a', s[1] - '0' - 1);
}


struct Board {
   int size;
   array<ull, 2> bits;
   int turn;
   int n_moves;

   Board() = default;
   Board(int id, int s, const vec<string>& lines) : size(s), bits({0, 0}), turn(id), n_moves(0) {
      rep (x, size) rep (y, size) {
         if (lines[x][y] == '.') continue;
         bits[lines[x][y] - '0'] |= to_flag(x, y);
      }
   }

   bool can_put(ull hand) const {
      ull legal = make_legal_flags();
      eprint("turn:", turn);
      eprint(to_bin(legal));
      return (hand & legal) == hand;
   }

   ull make_legal_flags() const {
      const ull lr = bits[turn ^ 1] & 0x7e7e7e7e7e7e7e7e;
      const ull td = bits[turn ^ 1] & 0x00ffffffffffff00;
      const ull al = bits[turn ^ 1] & 0x007e7e7e7e7e7e00;
      const ull blank = ~(bits[0] |    bits[1]);

      ull res = 0;
      // 左
      res |= [&]() {
         ull tmp = lr & (bits[0] << 1);
         rep (_, 5) tmp |= lr & (tmp << 1);
         return blank & (tmp << 1);
      }();

      // 右
      res |= [&]() {
         ull tmp = lr & (bits[0] >> 1);
         rep (_, 5) tmp |= lr & (tmp >> 1);
         return blank & (tmp >> 1);
      }();

      // 上
      res |= [&]() {
         ull tmp = td & (bits[0] << 8);
         rep (_, 5) tmp |= td & (tmp << 8);
         return blank & (tmp << 8);
      }();

      // 下
      res |= [&]() {
         ull tmp = td & (bits[0] >> 8);
         rep (_, 5) tmp |= td & (tmp >> 8);
         return blank & (tmp >> 8);
      }();

      // 斜め
      for (int i : {7, 9}) {
         res |= [&]() {
            ull tmp = al & (bits[0] << i);
            rep (_, 5) tmp |= al & (tmp << i);
            return blank & (tmp << i);
         }();

         res |= [&]() {
            ull tmp = al & (bits[0] >> i);
            rep (_, 5) tmp |= al & (tmp >> i);
            return blank & (tmp >> i);
         }();
      }

      return res;
   }

   void put(ull hand) {
      ull rev = 0;
      rep (i, 8) {
         ull _rev = 0;
         ull mask = transfer(hand, i);
         while (mask and (mask & bits[turn^1])) {
            _rev |= mask;
            mask = transfer(hand, i);
         }
         if (mask & bits[turn]) rev |= _rev;
      }
      bits[turn] ^= hand | rev;
      bits[turn^1] ^= rev;

      n_moves++;
   }

   ull transfer(ull hand, ull k) {
      switch (k) {
         case 0:  return (hand << 8) & 0xffffffffffffff00;
         case 1:  return (hand << 7) & 0x7f7f7f7f7f7f7f00;
         case 2:  return (hand << 1) & 0x7f7f7f7f7f7f7f7f;
         case 3:  return (hand << 9) & 0x007f7f7f7f7f7f7f;
         case 4:  return (hand << 8) & 0x00ffffffffffffff;
         case 5:  return (hand << 7) & 0x00fefefefefefefe;
         case 6:  return (hand << 1) & 0xfefefefefefefefe;
         case 7:  return (hand << 9) & 0xfefefefefefefe00;
         default: return 0;
      }
   }

   friend ostream& operator <<(ostream& os, const Board& b) {
      rep (x, b.size) {
         rep (y, b.size) {
            ull flag = to_flag(x, y);
            if (b.bits[0] & flag) cerr << "o";
            else if (b.bits[1] & flag) cerr << "x";
            else cerr << ".";
         }
         os << "\n";
      }
      return os;
   }
};

int32_t main() {
   int id;  // 先手なら0　後手なら1
   int board_size;
   cin >> id >> board_size; cin.ignore();

   while (true) {
      vec<string> lines(board_size);
      cin >> lines; cin.ignore();
      int n_actions;
      cin >> n_actions; cin.ignore();
      vec<string> actions(n_actions);
      rep (i, n_actions) cin >> actions[i];
      Board board(id, board_size, lines);
      board.put(to_flag(actions.back()));
   }
}