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

struct Setup_io {
   Setup_io() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
      cout << fixed << setprecision(15);
   }
} setup_io;


void Main() {
   int a, b;
   cin >> a >> b;
   string _s;
   cin >> _s;
   if (count(all(_s), '0') == len(_s)) {
      print(0);
      return;
   }

   int start = -1;
   rep (i, len(_s)) if (_s[i] == '1') {
      start = i;
      break;
   }
   int finish = -1;
   rrep (i, len(_s)) if (_s[i] == '1') {
      finish = i;
      break;
   }
   if (start == finish) {
      print(a);
      return;
   }

   vi s;
   reprs (i, start, finish) s.pb(ctoi(_s[i]));

   int zero = 0;
   vpii ers;
   int l, r;
   rep (i, len(s)) {
      if (s[i] == 0) {
         if (!zero) l = i;
         zero++;
      }
      else {
         if (!zero) continue;
         r = i;
         if (zero*b <= a) {
            ers.eb(l, r);
         }
         zero = 0;
      }
   }

   int ans = a;
   for (const pii& p : ers) {
      repr (i, p.FI, p.SE) {
         s[i] = 1;
         ans += b;
      }
   }
   //eprint(s);
   //eprint(len(ers));
   //eprint(ers);
   unordered_set<int> st;
   int idx = 0;
   rep (i, len(s)) {
      if (s[i] == 0) {
         idx++;
      }
      else {
         st.insert(idx);
      }
   }

   ans += len(st) * a - a;

   print(ans);
}

int32_t main() {
   int t;
   cin >> t;
   step (t) Main();

   return 0;
}
