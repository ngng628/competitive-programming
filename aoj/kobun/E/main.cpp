# ifndef Fruitstart_Library
# define Fruitstart_Library
# include <algorithm>
# include <cstdint>
# include <cassert>
# include <cmath>
# include <cstdio>
# include <deque>
# include <iomanip>
# include <iostream>
# include <map>
# include <queue>
# include <set>
# include <stack>
# include <unordered_map>
# include <unordered_set>
# include <utility>
# include <vector>
# include <cfloat>
# include <bitset>
# define overload3(_1, _2, _3, name, ...) name
# define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
# define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
# define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
# define reps(i, n) for (ll i = 1; i <= (ll)(n); ++i)
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (ll)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using ll = long long;
using i64 = long long;
using lint = int64_t;
using uint = uint32_t;
using ulint = uint64_t;
template<class T> using vec = vector<T>;
template<class T> using vector2d=vector<vector<T>>;
using pii = pair<ll, ll>;
using vi = vec<ll>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr ll oo = (1LL<<62)-(1LL<<31);
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
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(16); } } setup_io;
# endif  // Fruitstart_Library

using State = string::const_iterator;
string erase_all_space(string s) { s.erase(remove_if(all(s), [](char c){ return isspace(c); }), s.end()); return s; }
int ctoi(char c) { assert('0' <= c and c <= '9'); return c - '0'; }

bool Main() {
   constexpr ll MOD = 1'000'000'007;
   string s;
   getline(cin, s);
   if (s == "#") return false;

   struct Parser {
      string s;
      Parser(string t) : s(erase_all_space(t)) {}
      ll parser() {
         State it = s.begin();
         return expr(it);
      }

      ll expr(State& it) {
         ll res = term(it);
         while (it != s.end()) {
            if (*it == '>') {
               if (*next(it) == '>' and *next(next(it)) == '>') break;
               else if (*next(it) == '>' and (isdigit(*next(next(it))) or *next(next(it)) == 'S')) {
                  assert(*it++ == '>');
                  assert(*it++ == '>');
                  ll y = term(it);
                  if (y >= 64) res = 0;
                  else res >>= y;
               }
               else break;
            }
            else if (*it == 'S') return term(it);
            else break;
         }
         return res; 
      }

      ll term(State& it) {
         if (isdigit(*it)) return number(it);
         else {
            assert(*it++ == 'S');
            assert(*it++ == '<');
            ll x = expr(it) % MOD;
            assert(*it++ == '>');
            return (x*x) % MOD;
         }
      }

      ll number(State& it) {
         int res = 0;
         for (; isdigit(*it); ++it) {
            res *= 10;
            res += ctoi(*it);
         }
         return res;
      }
   };

   cout << Parser(s).parser() << endl;

   return true;
}

int main() {
   while (Main());
}