#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

vector<int> ms;
void pre() {
  for (int i = 6; i <= 300000; i += (i % 7 == 1 ? 5 : 2)) {
    if (i % 7 == 1 || i % 7 == 6) {
      if (!any_of(ms.begin(), ms.end(), [=](int x){ return i % x == 0; })) {
        ms.push_back(i); 
      }
    }
  }
}

void solve(int n) {
  string ans = to_string(n) + ":";
  rep (i, (int)ms.size()) {
    if (n % ms[i] == 0) ans += " " + to_string(ms[i]);
  }
  cout << ans << endl;
}

int main() {
  pre();
  while (1) {
    int n;
    cin >> n;
    if (n == 1) break;
    solve(n);
  }
  return 0;
}
