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
   auto print = [](basic_string<int> s) {
      const int n = s.size();
      rep (i, n) {
         cout << s[i] << " \n"[i == n - 1];
      }
   };

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      basic_string<int> a;
      rep (i, n) {
         int c;
         cin >> c;
         a.push_back(c);
      }

      if (n == 1) {
         cout << a[0] << endl;
         continue;
      }

      int last = -1;
      rep (i, n) if (a[i] == n) last = i;

      // [l, r]
      auto rev = [](basic_string<int> a, int l, int r) {
         rep (i, a.size()) {
            if (l + i >= r - i) break;
            swap(a[l + i], a[r - i]);
         }
         return a;
      };

      set<basic_string<int>> st;
      rep (i, n) {
         if (i >= last) break;
         // [i, last)
         auto b = rev(a, i, last - 1);
         if (i == 0) {
            st.insert(b.substr(last) + b.substr(i, last));
         }
         else {
            st.insert(b.substr(last) + b.substr(i, last - i) + b.substr(0, i));
         }
      }

      st.insert(a.substr(n - 1) + a.substr(0, n - 1));
      // auto b = a.substr(n - 1) + a.substr(0, n - 1);
      // print(b);

      int index = 0;
      rep (i, n) {
         if (a[i] == n - 1) {
            index = i;
            break;
         }
      }
      basic_string<int> s = a.substr(index) + a[index - 1] + a.substr(0, index - 1);
      st.insert(s);

      auto ans = *prev(st.end());
      print(ans);
   }
}
