# include <bits/stdc++.h>
# include <atcoder/fenwicktree>
using namespace std;
using BIT = atcoder::fenwick_tree<int>;

template <class T, class F>
T binary_chop(T ac, T wa, const F& f) {
   while (abs(ac - wa) > 1) {
      T wj = (ac + wa) >> 1;
      (f(wj) ? ac : wa) = wj;
   }
   return ac;
}

int main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   size_t Q;
   cin >> Q;
   vector<tuple<int, long long, int>> query(Q);
   for (auto& [t, x, k] : query) {
      cin >> t >> x;
      if (t == 2 or t == 3) cin >> k;
   }

   vector<long long> v(Q);
   for (size_t i = 0; i < Q; ++i) {
      v[i] = get<1>(query[i]);
   }
   sort(v.begin(), v.end());
   v.erase(unique(v.begin(), v.end()), v.end());
   unordered_map<long long, int> f;
   unordered_map<int, long long> g;
   for (size_t i = 0; i < v.size(); ++i) {
      f[v[i]] = distance(v.cbegin(), lower_bound(v.cbegin(), v.cend(), v[i]));
      g[f[v[i]]] = v[i];
   }

   BIT cumsum(f.size());
   for (auto [t, x, k] : query) {
      if (t == 1) {
         cumsum.add(f[x], 1);
      }
      if (t == 2) {
         auto ok = [&](int l) { return cumsum.sum(l, f[x] + 1) >= k; };
         long long ans = ok(0) ? g[binary_chop(0, f[x] + 1, ok)] : -1;
         cout << ans << endl;
      }
      if (t == 3) {
         auto ok = [&](int r) { return cumsum.sum(f[x], r) >= k; };
         long long ans = ok(f.size()) ? g[binary_chop((int)f.size(), f[x], ok) - 1] : -1;
         cout << ans << endl;
      }
   }
}
