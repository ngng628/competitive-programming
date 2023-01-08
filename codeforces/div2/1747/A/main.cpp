# include <bits/stdc++.h>
using namespace std;

int64_t answer() {
   int n;
   cin >> n;
   int64_t sum = 0;
   while (n--) {
      int64_t a;
      cin >> a;
      sum += a;
   }
   return abs(sum);
}

int main() {
   int t;
   cin >> t;
   while (t--) {
      cout << answer() << endl;
   }
}