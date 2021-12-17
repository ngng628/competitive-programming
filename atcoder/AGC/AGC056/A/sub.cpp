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

class UnionFind {
public:
   UnionFind() : _n(0) {}
   UnionFind(int n) : _n(n), parent_or_size(n, -1) {}

   int unite(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if (x == y) return x;
      if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
      parent_or_size[x] += parent_or_size[y];
      parent_or_size[y] = x;
      return x;
   }

   bool equiv(int a, int b) {
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
   vi parent_or_size;
};

bool judge(const vec<string>& s) {
   const int n = len(s);
   auto over = [&n](int y, int x) { return y < 0 or y >= n or x < 0 or x >= n; };

   rep (i, n) {
      int cnt = 0;
      rep (j, n) {
         cnt += int(s[i][j] == '#');
      }
      if (cnt != 3) return false;
   }
   rep (j, n) {
      int cnt = 0;
      rep (i, n) {
         cnt += int(s[i][j] == '#');
      }
      if (cnt != 3) return false;
   }

   constexpr array<pair<int, int>, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

   ddb visited(n, db(n, false));
   int cnt = 0;
   rep (y, n) {
      rep (x, n) {
         if (visited[y][x]) continue;
         if (s[y][x] == '.') continue;
         cnt += 1;
         auto dfs = [&](auto&& Recall, int i, int j) {
            if (visited[i][j]) return;
            visited[i][j] = true;
            for (auto [di, dj] : dydx4) {
               int ni = i + di;
               int nj = j + dj;
               if (over(ni, nj)) continue;
               if (s[ni][nj] == '.') continue;
               if (visited[ni][nj]) continue;
               Recall(Recall, ni, nj);
            }
         };
         dfs(dfs, y, x);
      }
   }

   return cnt == n;
}

int32_t main() {
   srand((int)time(0));
   int n = 9;
   vec<string> s;
   rep (i, n) {
      string t = "";
      rep (j, n) {
         t.push_back(rand() % 2 ? '.' : '#');
      }
      s.push_back(t);
   }

   // int cnt = 0;
   while (true) {
      // cnt++;
      // if (cnt % 100000 == 0) {
      //    cerr << "cnt = " << cnt << endl;
      //    for (auto a : s) cerr << a << endl;
      //    cnt = 1;
      // }
      if (judge(s)) break;
      int i = rand() % n;
      int j = rand() % n;
      if (count(all(s[i]), '#') > 5) {
         s[i][j] = '.';
      }
      else if ([&]() -> int { int c = 0; rep (ii, n) c += s[ii][j] == '#'; return c; }() > 5) {
         s[i][j] = '.';
      }
      else {
         s[i][j] = rand() % 2 ? '.' : '#';
      }
   }

   for (auto a : s) cout << a << endl;
}
