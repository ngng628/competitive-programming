# include <bits/stdc++.h>
using namespace std;

int main() {
   int n, m;
   cin >> n >> m;
   vector<long long> x(m);
   for (long long& e : x) cin >> e;
   sort(x.begin(), x.end());

   vector<long long> diffs(m - 1);
   for (int i = 0; i < m - 1; ++i) {
      diffs[i] = abs(x[i + 1] - x[i]);
   }

   priority_queue<long long> heap(diffs.cbegin(), diffs.cend());
   for (int i = 0; i < n - 1 and not heap.empty(); ++i) {
      heap.pop();
   }

   long long ans = 0;
   while (not heap.empty()) {
      ans += heap.top();
      heap.pop();
   }

   cout << ans << '\n';
}
