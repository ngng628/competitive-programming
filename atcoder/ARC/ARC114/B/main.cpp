# include <bits/stdc++.h>
# include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
   int n;
   cin >> n;
   dsu uf(n);
   for (int i = 0; i < n; ++i) {
      int f;
      cin >> f;
      uf.merge(i, f-1);
   }

   cout << (mint(2).pow(uf.groups().size()) - 1).val() << endl;
}
