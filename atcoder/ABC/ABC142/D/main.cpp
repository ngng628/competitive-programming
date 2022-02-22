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
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
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
           for(int k = i + i; k <= n; k += i) {
               table[k] = false;
               osak[k] = i;
           }
       }
       reps (i, 2, n) if (table[i]) lst.pb(i);
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
} PRIME(1e6);

vi divisor(int n) {
   vi v;
   for (int i = 1; i*i <= n; i++) {
       if (n % i == 0) {
           v.pb(i);
           if (i*i != n) v.pb(n / i);
       }
   }
   sort(all(v));
   return v;
}

int32_t main() {
   int a, b;
   cin >> a >> b;

   vi cd;
   auto ad = divisor(a);
   auto bd = divisor(b);
   for (auto d : ad) {
      if (binary_search(all(bd), d)) cd.pb(d);
   }

   int ans = 0;
   for (auto d : cd) {
      if (d == 1 or PRIME.is(d)) ans += 1;
   }
   cout << ans << '\n';
}