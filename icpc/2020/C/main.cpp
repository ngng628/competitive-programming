//    _        _     _         _               _    
//   | |__    (_)   | |__     (_)     ___     (_)   
//   | / /    | |   | '_ \    | |    (_-<     | |   
//   |_\_\   _|_|_  |_.__/   _|_|_   /__/_   _|_|_  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
//
# include <bits/stdc++.h>
# define cauto const auto
//# define int __int128
using ll = __int128;
# define float long double
# define FI first
# define SE second
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
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;

istream& operator>>(istream& is, ll& v) {
   string s;
   is >> s;
   v = 0;
   for (int i = 0; i < (int)s.size(); i++) {
      if (isdigit(s[i])) { v = v * 10 + s[i] - '0'; }
   }
   if (s[0] == '-') { v *= -1; }
   return is;
}

ostream& operator<<(ostream& os, const ll& v) {
   if (v == 0) { return (os << "0"); }
   ll num = v;
   if (v < 0) {
      os << '-';
      num = -num;
   }
   string s;
   for (; num > 0; num /= 10) { s.push_back((char)(num % 10) + '0'); }
   reverse(s.begin(), s.end());
   return (os << s);
}

vector<ll> divisor(ll n) {
   vector<ll> v;
   for (ll i = 1; i*i <= n; i++) {
      if (n % i == 0) {
         v.pb(i);
         if (i*i != n) v.pb(n / i);
      }
   }
   sort(all(v));
   return v;
}

void Main(ll p) {
   vector<ll> lst = divisor(p);
   const ll n = len(lst);
   ll ans = LONG_LONG_MAX;
   rep (i, n) {
      rep (k, n) {
         ll a = lst[i];
         ll b = lst[k];
         ll ab = a*b;
         if (p % ab == 0) {
            chmin(ans, a + b + (p / ab));
         }
      }
   }

   cout << ans << "\n";
}

int32_t main() {
   while (true) {
      ll p;
      cin >> p;
      if (!p) break;
      Main(p);
   }

   return 0;
}
