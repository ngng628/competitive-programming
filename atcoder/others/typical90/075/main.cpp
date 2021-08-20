# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
using __long_double = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
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
constexpr int ctoi(const char c){ return '0' <= c and c <= '9' ? (c - '0') : -1; }
# endif  // ngng628_library

struct Prime {
   Prime() : n_max(0) {}
   // O ( N loglog(N) )
   Prime(int n) : n_max(n), table(n+1, true), osak(n+1) {
       iota(osak.begin(), osak.end(), 0);
       osak[0] = 1;
       if (n >= 0) table[0] = false;
       if (n >= 1) table[1] = false;
       for (int i = 2; i * i <= n; i++) {
           if (not table[i]) continue;
           lst.pb(i);
           for(int k = i + i; k <= n; k += i) {
               table[k] = false;
               osak[k] = i;
           }
       }
   }

   // n <= n_max のとき: O(1)
   // それ超えのとき: O( sqrt(N) )
   bool is(const int n) {
       if (n <= n_max) return table[n];
       if (n <= 4) return n == 2 || n == 3;
       if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
       for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
       return true;
   }

   // O( sqrt(N) )
   map<int, int> factor(int n) {
       if (n == 1) {
           map<int, int> one;
           one[1] = 1;
           return one;
       }
       if (n <= n_max) return impl_factor_fast(n);
       map<int, int> ret;
       for (int i = 2; i * i <= n; i++) {
           while (n % i == 0) {
               ret[i]++;
               n /= i;
           }
       }
       if (n != 1) ret[n] = 1;
       return ret;
   }

   // O( log(N) )
   map<int, int> impl_factor_fast(int n) {
       map<int, int> ret;
       while (n != 1) {
           int p = osak[n];
           ret[p]++;
           n /= p;
       }
       return ret;
   }

   // O( len(v) log(v_max) )
   bool to(vi v) {
       unordered_set<int> s;
       for (auto& n : v) {
           while (n != 1) {
               int p = osak[n];
               if (s.count(p)) return false;
               else s.insert(p);
               while (n % p == 0) n /= p;
           }
       }
       return true;
   }

   const int n_max;
   db table;
   vi osak;
   vi lst;
} PRIME(1e7);

int powi(int x, int n) {
   int p = 1;
   while (n > 0) {
       if (n & 1) p *= x;
       x *= x;
       n >>= 1;
   }
   return p;
}

int32_t main() {
   int n;
   cin >> n;
   if (PRIME.is(n)) drop(0);

   auto f = PRIME.factor(n);
   int c = 0;
   for (pii p : f) c += p.se;
   int ok = 63;
   int ng = 0;
   while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      auto isOK = [&](int key) {
         return powi(2, key) >= c;
      };
      if (isOK(mid)) ok = mid;
      else ng = mid;
   }

   print(ok);
}