#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using P = pair<int,int>;

void solve(vector<int>& taro, vector<int>& hanako) {
  int st = accumulate(taro.begin(), taro.end(), 0LL);
  int sh = accumulate(hanako.begin(), hanako.end(), 0LL);
  
  int mini = INT_MAX;
  P ans;
  for (int t : taro) {
    for (int h : hanako) {
      if (st - t + h == sh - h + t) {
        if (t + h < mini) {
          mini = t + h;
          ans = { t, h };
        }
      }
    }
  }
  
  if (mini < INT_MAX) cout << ans.first << " " << ans.second << endl;
  else cout << -1 << endl;
}

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;
    if (!(n | m)) break;
    vector<int> taro(n), hanako(m);
    rep (i, n) cin >> taro[i];
    rep (i, m) cin >> hanako[i];
    solve(taro, hanako);
  }
  
  return 0;
}
