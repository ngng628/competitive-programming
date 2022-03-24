# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   cout << "何エポック毎に見る？ > ";
   int epoch;
   cin >> epoch;
   int sum = 0;
   for (int cnt = 1;; cnt += 1) {
      vector<int> a(n, 0);
      int cnt2 = 0;
      while (!all_of(a.begin(), a.end(), [](int x) { return x == 2; })) {
         int i = rand() % n;
         int j = i;
         while (i == j) j = rand() % n;
         a[i] = (a[i] + 1) % 3;
         a[j] = (a[j] + 1) % 3;
         cnt2 += 1;
      }
      sum += cnt2;
      if (cnt % epoch == 0) {
         cout << sum / gcd(sum, cnt) << "/" << cnt / gcd(sum, cnt) << " = " << (double)sum / cnt << endl;
      }
   }
}