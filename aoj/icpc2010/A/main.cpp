# include <bits/stdc++.h>
# define rep(i,n) for(int i=0; i<(n); ++i)
# define FI first
# define SE second
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

struct phash {
   inline size_t operator ()(const pair<int,int>& p) const {
      const auto h1 = hash<int>()(p.first);
      const auto h2 = hash<int>()(p.second);
      return h1 ^ (h2 << 1);
   }
};

void Main(int N, vi n, vi d) {
   unordered_map<int, pii> pos;
   pos[0] = { 0, 0 };
   rep (i, N-1) {
      int num = n[i];
      int dir = d[i];
      switch (dir) {
         case 0: // 左側
            pos[i+1] = { pos[num].FI - 1, pos[num].SE };
            break;
         case 1: // 下側
            pos[i+1] = { pos[num].FI, pos[num].SE - 1 };
            break;
         case 2: // 右側
            pos[i+1] = { pos[num].FI + 1, pos[num].SE };
            break;
         case 3: // 上側
            pos[i+1] = { pos[num].FI, pos[num].SE + 1 };
            break;
         default:
            pos[i+1] = { pos[num].FI, pos[num].SE };
      }
   }

   int width = 0;
   int height = 0;
   for (int i = 0; i < N; ++i) {
      for (int k = i + 1; k < N; ++k) {
         width = max(width, abs(pos[i].FI - pos[k].FI));
         height = max(height, abs(pos[i].SE - pos[k].SE));
      }
   }

   cout << width + 1 << " " << height + 1 << endl;
}

int main() {
   while (true) {
      int N;
      cin >> N;
      if (!N) break;
      vi n(N-1), d(N-1);
      rep (i, N-1) cin >> n[i] >> d[i];
      Main(N, n, d);
   }
   return 0;
}
