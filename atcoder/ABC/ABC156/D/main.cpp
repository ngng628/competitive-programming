# include <bits/stdc++.h>
# include <atcoder/modint>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
using namespace std;
using Int = long long;
# endif  // ngng628_library

using namespace atcoder;
using Fp = modint1000000007;
istream& operator >>(istream& is, Fp& r){ int t; is >> t; r = t; return is; }
ostream& operator <<(ostream& os, const Fp& r){ return os << r.val(); }

Fp nchoosek(int n, int k) {
   Fp num = 1;
   rep (i, k) num *= n - i;
   Fp den = 1;
   reps (i, k) den *= i;
   return num / den;
}

int32_t main() {
   int n, a, b;
   cin >> n >> a >> b;
   Fp ans = Fp(2).pow(n) - nchoosek(n, a) - nchoosek(n, b) - 1;
   cout << ans << '\n';
}