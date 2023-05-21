# include <bits/stdc++.h>
# define _overload3(_1, _2, _3, name, ...) name
# define _rep(i, n) repi(i, 0, n)
# define repi(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
# define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
# define rrep(i, a, n) for (ll i = n - 1; i >= a; i--)
# define LINF (1LL << 60)
# define INF (1 << 30)
# define fs first
# define sc second
# define ALL(a) a.begin(), a.end()
using ll = long long;
using namespace std;
template <class T> void chmin(T& a, T b){ if (a > b) a = b; }
template <class T> void chmax(T& a, T b){ if (a < b) a = b; }

int main() {
   string s = "abc";
   cout << "\'" << s.substr(0) << "\'" << endl;
   cout << "\'" << s.substr(1) << "\'" << endl;
   cout << "\'" << s.substr(2) << "\'" << endl;
   cout << "\'" << s.substr(3) << "\'" << endl;
}
