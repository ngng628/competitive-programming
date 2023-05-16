# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   // cnt[i] = 色が i の靴下の枚数
   map<int, int> cnt;
   for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
   }

   int ans = 0;

   // cnt に入っている色と靴下の枚数のペアを列挙する
   for (auto [key, value] : cnt) {
      ans += value / 2;
   }

   cout << ans << endl;
}