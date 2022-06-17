# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   map<int, int> mp;
   int cur = 0;
   for (int& ai : a) {
      cin >> ai;
      if (mp.find(ai) == mp.end()) mp[ai] = cur++;
      ai = mp[ai];
   }
   for (int& bi : b) {
      cin >> bi;
      if (mp.find(bi) == mp.end()) mp[bi] = numeric_limits<int>::max();
      bi = mp[bi];
   }

   auto f = [&mp](const vector<int>& v) {
      set<int> st;
      vector<int> sizes = { 0 };
      vector<int> maxs = { numeric_limits<int>::min() };
      for (int vi : v) {
         st.insert(vi);
         sizes.push_back(st.size());
         maxs.push_back(max(maxs.back(), vi));
      }
      return make_pair(sizes, maxs);
   };
   auto [a_sizes, a_maxs] = f(a);
   auto [b_sizes, b_maxs] = f(b);

   int Q;
   cin >> Q;
   while (Q--) {
      int x, y;
      cin >> x >> y;
      if (a_sizes[x] == b_sizes[y] and a_maxs[x] == b_maxs[y]) {
         cout << "Yes" << endl;
      }
      else {
         cout << "No" << endl;
      }
   }
}