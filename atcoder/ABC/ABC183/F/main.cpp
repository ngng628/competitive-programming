/**
 *  AtCoder Beginner Contest
**/
// >>> ngng628's library 
// >>> includes 
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <functional>
# include <cmath>
# include <iomanip>
# include <stack>
# include <queue>
# include <numeric>
# include <map>
# include <set>
# include <unordered_map>
# include <unordered_set>
# include <chrono>
# include <random>
# include <bitset>
# include <cassert>
// <<<
// >>> macros
# define cauto const auto
# define int long long
# define float long double
# define FI first
# define SE second
# define mkp make_pair
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
// <<<
// >>> usings 
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
// <<<
// >>> functions 
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
// <<<
// <<<

vpii students(n);
// >>> Union Find
class UnionFind {
public:
   UnionFind() : _n(0) {}
   UnionFind(int n) : _n(n), parent_or_size(n, {-1, mii()}) {}
   int merge(int a, int b) {
      assert(0 <= a && a < _n);	
      assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if (x == y) return x;
      if (-parent_or_size[x].FI < -parent_or_size[y].FI) std::swap(x, y);
      parent_or_size[x].FI += parent_or_size[y].FI;
      parent_or_size[x].SE[students[x]]++;
      parent_or_size[x].SE[students[y]]++;
      parent_or_size[y].FI = x;
      return x;
   }
   bool same(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      return leader(a) == leader(b);
   }
   mii leader(int a) {
      assert(0 <= a && a < _n);
      if (parent_or_size[a].FI < 0) return a;
      parent_or_size[a].FI = leader(parent_or_size[a].FI);
      return parent_or_size[a].SE;
   }

   int _leader

   int size(int a) {
      assert(0 <= a && a < _n);
      return -parent_or_size[leader(a)].FI;
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
   std::vector<pair<int, mii>> parent_or_size;
};
// <<<

int32_t main() {
   int n, q;
   cin >> n >> q;
   students.resize(n);
   rep (i, n) {
      int c;
      cin >> c;
      students[i] = mkp(i, c);
   }

   UnionFind uf(n);
   while (q--) {
      int type, x, y;
      cin >> type >> x >> y;
      x--; y--;
      if (type == 1) {
         uf.merge(x, y);
      }
      else {
         auto root = uf.leader(x);
         print(root.SE[y]);
      }
   }

   return 0;
}

