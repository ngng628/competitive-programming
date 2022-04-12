# include <iostream>
# include <array>
using namespace std;

void solve() {
   array<array<int, 4>, 3> printers;
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 4; ++j) {
         cin >> printers[i][j];
      }
   }

   constexpr int INF = 1001001001;
   array<int, 4> limits = { INF, INF, INF, INF };
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
         limits[i] = min(limits[i], printers[j][i]);
      }
   }

   if (limits[0] + limits[1] + limits[2] + limits[3] < 1000000) {
      puts("IMPOSSIBLE");
      return;
   }

   while (limits[0] + limits[1] + limits[2] + limits[3] > 1000000) {
      for (int i = 0; i < 4; ++i) {
         if (limits[i] > 0) {
            limits[i] -= 1;
            break;
         }
      }
   }

   printf("%d %d %d %d\n", limits[0], limits[1], limits[2], limits[3]);
}

int main() {
   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      printf("Case #%d: ", i);
      solve();
   }
}