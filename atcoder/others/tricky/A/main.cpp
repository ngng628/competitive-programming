# include <bits/stdc++.h>
using namespace std;

int main() {
   int T;
   cin >> T;
   while (T--) {
      int64_t A, B;
      cin >> A >> B;
      long double preans = (long double)A / B;
      if (A % abs(B) == 0) cout << A / B << endl;
      else if (preans < 0) cout << ceil(preans) << endl;
      else cout << floor(preans) << endl;
   }
}
