# include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin >> t;

   stringstream ss;

   while (t--) {
      int n, d;
      int64_t c;
      cin >> n >> c >> d;

      vector<int> a(n);
      for (int& ai : a) {
         cin >> ai;
      }

      auto judge = [&](int k) {
         priority_queue<int> heap(a.begin(), a.end());
         queue<pair<int, int>> que;

         int64_t acc = 0;
         for (int i = 1; i <= d; i++) {
            if (!heap.empty()) {
               acc += heap.top();
               que.emplace(i, heap.top());
               heap.pop();
            }
            if (i - que.front().first >= k) {
               heap.push(que.front().second);
               que.pop();
            }
         }

         return acc >= c;
      };

      int ac = 0;
      int wa = d + 1;
      if (!judge(ac)) {
         ss << "Impossible\n";
      }
      else if (judge(wa)) {
         ss << "Infinity\n";
      }
      else {
         while (wa - ac > 1) {
            int wj = (ac + wa) / 2;
            if (judge(wj)) {
               ac = wj;
            }
            else {
               wa = wj;
            }
         }
         ss << ac << '\n';
      }
   }

   cout << ss.str();
}