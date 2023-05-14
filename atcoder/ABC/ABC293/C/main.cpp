# include <bits/stdc++.h>
using namespace std;

int main() {
   int h, w;
   cin >> h >> w;
   vector a(h, vector<int>(w));
   for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
         cin >> a[i][j];
      }
   }

   struct Data {
      int i, j;
      vector<int> seq;
      Data() = default;
      Data(int _i, int _j, vector<int> _s) : i(_i), j(_j), seq(_s) {}
   };

   int cnt = 0;
   queue<Data> que;
   vector<int> ini = {a[0][0]};
   que.emplace(0, 0, ini);
   while (not que.empty()) {
      auto [i, j, seq] = que.front();
      que.pop();

      if (i == h - 1 && j == w - 1) {
         set<int> st(seq.begin(), seq.end());
         if (st.size() == seq.size()) {
            cnt += 1;
         }
      }

      {
         int ni = i + 1;
         int nj = j;
         if (!(ni >= h || nj >= w)) {
            auto copy = seq;
            copy.push_back(a[ni][nj]);
            que.emplace(ni, nj, copy);
         }
      }
      {
         int ni = i;
         int nj = j + 1;
         if (!(ni >= h || nj >= w)) {
            auto copy = seq;
            copy.push_back(a[ni][nj]);
            que.emplace(ni, nj, copy);
         }
      }
   }

   cout << cnt << endl;
}