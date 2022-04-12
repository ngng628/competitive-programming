# include <iostream>
using namespace std;

void solve() {
   int h, w;
   cin >> h >> w;
   for (int i = 0; i < 2*h + 1; ++i) {
      for (int j = 0; j < 2*w + 1; ++j) {
         if (i == 0) {
            if (j == 0 or j == 1) cout << '.';
            else if (j & 1) cout << '-';
            else cout << '+';
         }
         else if (i == 1) {
            if (j == 0 or j == 1) cout << '.';
            else if (j & 1) cout << '.';
            else cout << '|';
         }
         else if (i & 1) {
            if (j & 1) cout << '.';
            else cout << '|';
         }
         else {
            if (j & 1) cout << '-';
            else cout << '+';
         }
      }
      cout << endl;
   }
}

int main() {
   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      cout << "Case #" << i << ':' << endl;
      solve();
   }
}