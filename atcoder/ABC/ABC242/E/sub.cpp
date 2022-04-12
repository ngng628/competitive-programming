# include <bits/stdc++.h>
# include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
   int T;
   cin >> T;
   while (T --> 0) {
      int n;
      cin >> n;
      string s;
      cin >> s;

      mint ans = 0;
      const int m = (n + 1) / 2;
      for (int i = 0; i < m; ++i) {
         ans += (s[i] - 'A') * mint(26).pow(m - 1 - i);
      }
      ans += 1;
      string t = s.substr(0, n / 2);
      if (n & 1) t.push_back(s[n / 2]);
      t += [](string s){ reverse(s.begin(), s.end()); return s; }(s.substr(0, n / 2));
      if (s < t) ans -= 1;

      cout << ans.val() << '\n';
   }
}