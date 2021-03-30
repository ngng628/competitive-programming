# include <bits/stdc++.h>
using namespace std;

int main() {
   size_t N;
   cin >> N;
   vector<uint32_t> A(N);
   for (auto& e : A) cin >> e;
   int ans = accumulate(A.begin(), A.end(), 0, [](int m, int n){
      return gcd(m, n);
   });
   cout << ans << endl;
}
