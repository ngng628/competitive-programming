# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

// 盤面のマージをする
vector<string> operator +(const vector<string>& s, const vector<string>& t) {
   const int n = s.size();
   const int m = t.size();
   vector<string> res(n + m, string(n + m, '.'));
   rep (i, n) rep (j, n) res[i][j] = s[i][j];
   rep (i, m) rep (j, m) res[i + n][j + n] = t[i][j];
   return res;
}

int32_t main() {
   // Step 0. 埋め込み
   vector<vector<string>> unit {
      { {""} }, { {""} }, { {""} },
      {
         "nn.",
         "..g",
         "..g"
      },
      {
         "ggol",
         "llol",
         "oegg",
         "oeoo"
      },
      {
         "aattc",
         "xyy.c",
         "x..zo",
         "r..zo",
         "reedd"
      },
      {
         "nn....",
         "..g...",
         "..g...",
         "...nn.",
         ".....g",
         ".....g"
      },
      {
         "rrgg..r",
         ".bb..br",
         "..rr.bg",
         "g...r.g",
         "gb..r..",
         "rb..bb.",
         "r..ggrr",
      },
   };
   unit.resize(15);

   // Step 1. 入力
   int n;
   cin >> n;

   // Step 2. 基本素子を構成
   unit[10] = unit[5] + unit[5];
   unit[11] = unit[4] + unit[7];
   unit[12] = unit[5] + unit[7];
   unit[13] = unit[4] + unit[4] + unit[5];
   unit[14] = unit[7] + unit[7];

   // Step 3. 解く
   vector<string> ans;
   if (n == 2) ans = {"-1"};
   else if (3 <= n and n <= 7) ans = unit[n];
   else if (n == 8) ans = unit[4] + unit[4];
   else if (n == 9) ans = unit[6] + unit[3];
   else {
      auto [x, y] = div(n, int(5));
      rep (i, x - 2) ans = ans + unit[5];
      ans = ans + unit[10 + y];
   }

   // Step 4. 答えの出力
   for (string a : ans) cout << a << endl;
}
