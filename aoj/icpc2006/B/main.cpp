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

string reversed(string s) {
   reverse(all(s));
   return s;
}

void Main(string& s) {
   const int n = len(s);
   set<string> trains;
   reprs (i, 1, n-1) {
      string sub1 = s.substr(0, i);
      string sub2 = s.substr(i, n);

      string sub = sub1 + sub2;
      trains.insert(sub);
      sub = reversed(sub1) + sub2;
      trains.insert(sub);
      sub = sub1 + reversed(sub2);
      trains.insert(sub);
      sub = reversed(sub1) + reversed(sub2);
      trains.insert(sub);

      swap(sub1, sub2);
      sub = sub1 + sub2;
      trains.insert(sub);
      sub = reversed(sub1) + sub2;
      trains.insert(sub);
      sub = sub1 + reversed(sub2);
      trains.insert(sub);
      sub = reversed(sub1) + reversed(sub2);
      trains.insert(sub);
   }
   print(len(trains));
}

int32_t main() {
   int m;
   cin >> m;
   step (m) {
      string s;
      cin >> s;
      Main(s);
   }

   return 0;
}