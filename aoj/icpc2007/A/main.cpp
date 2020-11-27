#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
  while (1) {
    int n;
    cin >> n;
    if (!n) break;
    vector<int> s(n);
    rep (i, n) cin >> s[i];

    sort(s.begin(), s.end());
    int sum = accumulate(s.begin() + 1, s.end() - 1, 0);
    int ans = sum / (n-2);
    cout << ans << endl;
  }
  return 0;
}
