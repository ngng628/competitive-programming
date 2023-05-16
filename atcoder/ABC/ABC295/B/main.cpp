# include <bits/stdc++.h>
using namespace std;

int main() {
   // 1. 入力
   int h, w;
   cin >> h >> w;
   vector<string> s(h);
   for (string& t : s) cin >> t;

   // 2. マス (a, b) を爆発させる
   vector<string> ans = s;
   auto explode = [&](int a, int b) {
      int power = int(s[a][b] - '0');
      for (int i = 0; i < h; i++) {
         for (int j = 0; j < w; j++) {
            if (abs(i - a) + abs(j - b) <= power) {
               ans[i][j] = '.';
            }
         }
      }
   };

   // 3. 全マスに対して爆発処理をする
   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         if (s[i][j] == '#' || s[i][j] == '.') continue;
         explode(i, j);
      }
   }

   for (string t : ans) {
      cout << t << endl;
   }
}