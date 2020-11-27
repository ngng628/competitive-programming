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

class UnionFind {
public:
   UnionFind() : _n(0) {}
   UnionFind(int n) : _n(n), parent_or_size(n, -1) {}
   int merge(int a, int b) {
      assert(0 <= a && a < _n);	
      assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if (x == y) return x;
      if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
      parent_or_size[x] += parent_or_size[y];
      parent_or_size[y] = x;
      return x;
   }
   bool same(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      return leader(a) == leader(b);
   }
   int leader(int a) {
      assert(0 <= a && a < _n);
      if (parent_or_size[a] < 0) return a;
      return parent_or_size[a] = leader(parent_or_size[a]);
   }
   int size(int a) {
      assert(0 <= a && a < _n);
      return -parent_or_size[leader(a)];
   }
   vvi groups() {
      vi leader_buf(_n), group_size(_n);
      rep (i, _n) {
         leader_buf[i] = leader(i);
         group_size[leader_buf[i]]++;
      }
      vvi result(_n);
      rep (i, _n) result[i].reserve(group_size[i]);
      rep (i, _n) result[leader_buf[i]].pb(i);
      result.erase(
      remove_if(all(result), [&](const vi& v) { return v.empty(); }), result.end());
      return result;
   }
private:
   int _n;
   // root node: -1 * component size
   // otherwise: parent
   std::vector<int> parent_or_size;
};

void Main(int m, int n, int p, vi& a, vi& b) {
   bool start = true;
   //set<int> st;
   UnionFind uf(m);
   rep (i, n) {
      //uf.leader(p) == uf.leader(a);
      //if (a[i] == p or b[i] == p) {
      //   start = true;
      //}
      //
      if (uf.same(p, a[i]) or uf.same(p, b[i])) {
         uf.merge(a[i], b[i]);
      }

      //if (start) {
      //   uf.merge(a[i], b[i]);
      //}
      //else {
      //   if (a[i] == p or b[i] == p) {
      //      uf1.merge(a[i], b[i]);
      //   }
      //}
   }

   int cnt = 0;
   //set<int> st;
   //rep (i, m) {
   //   if (uf.same(p, i)) {
   //      cnt++;
   //   }
   //}

   rep (i, m) {
      if (uf.same(p, i)) {
         cnt++;
      }
   }

   print(cnt);
}

int32_t main() {
   while (true) {
      int m, n, p;
      cin >> m >> n >> p;
      if (!(m | n | p)) break;
      p--;
      vi a(n), b(n);
      rep (i, n) {
         cin >> a[i] >> b[i];
         a[i]--;
         b[i]--;
      }
      Main(m, n, p, a, b);
   }

   return 0;
}
