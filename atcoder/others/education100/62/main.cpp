# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define mkp make_pair
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
# define contains(x,key) ((x).find(key) != (x).end())
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
constexpr int Flag(int n) { return 1LL << n; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
template<class It> constexpr bool same(It f, It e) { while (f != e) if (*f != *(--e)) return false; return true; }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }
# endif  // ngng628_library

template<typename T>
struct Matrix {
   vector<vector<T>> m;

   Matrix():m(vector<vector<T>>()){}
   Matrix(int h,int w) : m(vector<vector<T>>(h,vector<T>(w))) {}
   Matrix(int h,int w, T d) : m(vector<vector<T>>(h,vector<T>(w,d))){}
   Matrix(const vector<vector<T>>& _m):m(_m){}

   vector<T> operator[](const int i) const {return m[i];}
   vector<T>& operator[](const int i){return m[i];}

   int nrow = len(m);
   int ncol = len(m[0]);

   Matrix& operator+=(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
   Matrix& operator-=(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
   Matrix& operator*=(const Matrix& a){assert(ncol == a.nrow);Matrix<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
   Matrix operator+(const Matrix& a) const { return Matrix(*this) += a;}
   Matrix operator-(const Matrix& a) const { return Matrix(*this) -= a;}
   Matrix operator*(const Matrix& a) const { return Matrix(*this) *= a;}
   bool operator==(const Matrix& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}

   Matrix& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
   Matrix& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
   Matrix& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
   Matrix& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
   Matrix operator+(const T& a) const { return Matrix(*this) += a;}
   Matrix operator-(const T& a) const { return Matrix(*this) -= a;}
   Matrix operator*(const T& a) const { return Matrix(*this) *= a;}
   Matrix operator/(const T& a) const { return Matrix(*this) /= a;}
};
using Mat = Matrix<int>;
const Mat E({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});

int32_t main() {
   int h, w;
   cin >> h >> w;
   Matrix c(10, 10, 0);
   rep (i, 10) rep (k, 10) cin >> c[i][k];
   rep (m, 10) rep (i, 10) rep (k, 10) {
      chmin(c[i][k], c[i][m] + c[m][k]);
   }

   int ans = 0;
   rep (y, h) {
      rep (x, w) {
         int a;
         cin >> a;
         if (a == -1) continue;
         ans += c[a][1];
      }
   }
   print(ans);
}
