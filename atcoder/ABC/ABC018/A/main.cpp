# include <bits/stdc++.h>
# define rep(i,n) for(int i=0; i<(n); ++i)
# define sz(v) (int)(v).size()
# define all(v) (v).begin(), (v).end()
using namespace std;
using pii = pair<int, int>;

int main() {
   vector<int> v(3);
   rep (i, 3) {
      cin >> v[i];
   }

   vector<int> old = v;
   sort(all(v));
   rep (i, 3) {
      int r = distance(lower_bound(all(v), old[i]), v.end());
      cout << r << endl;
   }
}
