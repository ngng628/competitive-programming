//    _        _     _         _               _    
//   | |__    (_)   | |__     (_)     ___     (_)   
//   | / /    | |   | '_ \    | |    (_-<     | |   
//   |_\_\   _|_|_  |_.__/   _|_|_   /__/_   _|_|_  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
//
# include <bits/stdc++.h>
# define cauto const auto
# define int long long
# define real long double
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

struct PC {
   PC() : imos(1302, 0) {}

   void in(int l, int m) {
      imos[l] += m;
   }

   void out(int r, int m) {
      imos[r] -= m;
   }

   void run() {
      rep (i, 1301) {
         imos[i+1] += imos[i];
      }
   }

   vi filter(int m) {
      vector<int> filtered(1302);
      rep (i, len(imos)) {
         if (imos[i] == m) {
            filtered[i] = 1;
         }
         else {
            filtered[i] = 0;
         }
      }
      return filtered;
   }
   //private:
   vector<int> imos;
};

int32_t main() {
   while (true) {
      int N, M;
      cin >> N >> M;
      if (!(N | M)) break;

      vector<PC> pc(N);
      int r;
      cin >> r;
      while (r--) {
         int t, n, m, s;
         cin >> t >> n >> m >> s;
         n--;
         if (s == 1) pc[n].in(t, m);
         else pc[n].out(t, m);
      }

      rep (i, N) pc[i].run();

      int q;
      cin >> q;
      while (q--) {
         int ts, te, m;
         cin >> ts >> te >> m;

         vvi filtered(N);
         rep (i, N) {
            filtered[i] = pc[i].filter(m);
         }
         set<int> s;
         rep (i, N) {
            repr (k, ts, te) {
               if (filtered[i][k] == 1) s.insert(k);
            }
         }
         print(len(s));
      }
   }

   return 0;
}
