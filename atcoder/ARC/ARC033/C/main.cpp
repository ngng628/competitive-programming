# include <bits/stdc++.h>
using namespace std;
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using TreeList = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
   int Q;
   cin >> Q;
   TreeList tl;
   while (Q--) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
         tl.insert(x);
      }
      else {
         int kth = *tl.find_by_order(x - 1);
         cout << kth << endl;
         tl.erase(kth);
      }
   }
}