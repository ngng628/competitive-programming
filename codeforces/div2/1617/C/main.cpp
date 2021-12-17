# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define all(v) std::begin(v), std::end(v)
# define pb push_back
# define len(v) (int)std::size(v)
using namespace std;
using vi = vector<int>;
struct Setup_io { Setup_io(){ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); } } setup_io;
# endif  // ngng628_library

struct Solver {
   void solve() {
      int n;
      cin >> n;
      vi a(n);
      for (auto& e : a) cin >> e;

      set<int> perms;
      reps (i, n) perms.insert(i);
      vi b;
      rep (i, n) {
         if (perms.count(a[i])) perms.erase(a[i]);
         else b.pb((a[i] - 1) / 2);
      }
      sort(all(b));
      const int m = len(b);

      int i = 0;
      for (auto r : perms) {
         if (r > b[i]) {
            cout << -1 << endl;
            return;
         }
         i += 1;
      }

      cout << m << endl;
   }
};

int32_t main() {
   int t;
   cin >> t;
   rep (t) {
      Solver solver;
      solver.solve();
   }
}
