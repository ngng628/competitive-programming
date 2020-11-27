//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define step(n) rep(_, n)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define cauto const auto
# define int long long
# define real long double
# define FI first
# define SE second
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for(auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

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
         mii one;
         one[1] = 1;
         return one;
      }
      if (n <= n_max) return impl_factor_fast(n);
      mii ret;
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
   mii impl_factor_fast(int n) {
      mii ret;
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
            if (contains(s, p)) return false;
            else s.insert(p);
            while (n % p == 0) n /= p;
         }
      }
      return true;
   }

   const int n_max;
   vb table;
   vi osak;
   vi lst;
} PRIME(1e7);

using ll = long long;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
 

void Main() {
   int n;
   cin >> n;

   vi ans(n);
   for (int i = 4*n, cnt = 0; cnt < n; i -= 2, cnt++) {
      ans[cnt] = i;
   }

   print(ans);
}

int32_t main() {
   int t;
   cin >> t;
   step (t) {
      Main();
   }

   return 0;
}
