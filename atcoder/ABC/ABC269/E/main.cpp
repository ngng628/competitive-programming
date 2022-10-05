# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int query(int a, int b, int c, int d) {
   cout << "? " << a + 1 << " " << b << " " << c + 1 << " " << d << endl;
   int t;
   cin >> t;
   return t;
}

void answer(int y, int x) {
   cout << "! " << y << " " << x << endl;
}

int main() {
   int n;
   cin >> n;
   if (n == 1) {
      answer(1, 1);
      return 0;
   }
   int mode = 0;
   int y1 = 0, y2 = n;
   int x1 = 0, x2 = n;
   int x = -1, y = -1;
   rep (turn, 20) {
      // 1ターン目だけ考える
      if (mode == 0) {
         int num = x2 - x1;
         int t = query(y1, y2, x1, (x2 - x1) / 2 + x1); // 左側の個数
         if (t == num / 2) x1 = (x2 - x1) / 2 + x1;
         else x2 = (x2 - x1) / 2 + x1;
      }
      else {
         int num = y2 - y1;
         int t = query(y1, (y2 - y1) / 2 + y1, x1, x2); // 左側の個数
         if (t == num / 2) y1 = (y2 - y1) / 2 + y1;
         else y2 = (y2 - y1) / 2 + y1;
      }

      if (x2 - x1 == 1) {
         x = x2;
         mode = 1;
         x1 = 0;
         x2 = n;
      }
      if (y2 - y1 == 1) {
         y = y2;
         break;
      }
   }

   assert(x >= 0 && y >= 0);

   answer(y, x);
}