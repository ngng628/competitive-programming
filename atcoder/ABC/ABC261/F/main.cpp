# include <bits/stdc++.h>
# include <atcoder/fenwicktree>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
# define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using namespace __gnu_pbds;
using TreeSet = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
using BIT = atcoder::fenwick_tree<int>;

int main() {
   int n;
   cin >> n;
   vector<int> c(n);
   rep (i, n) cin >> c[i], c[i]--;
   vector<int> x(n);
   rep (i, n) cin >> x[i], x[i]--;
   vector<TreeSet> sets(n);


   BIT bit(n);
   long ans = 0;
   rep (i, n) {
      TreeSet& st = sets[c[i]];
      int save = st.size() - st.order_of_key(x[i] + 1);
      int sum = bit.sum(x[i] + 1, n);
      bit.add(x[i], 1);
      st.insert(x[i]);
      ans += sum - save;
   }
   cout << ans << endl;
}