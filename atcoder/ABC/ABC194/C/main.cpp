# include <bits/stdc++.h>
# define int long long
using namespace std;

int32_t main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int& e : a) cin >> e;
   
   vector<int> s(n+1, 0);
   partial_sum(a.begin(), a.end(), s.begin()+1);

   int ans = 0;
   auto sq = [](int x){ return x*x; };
   for (int i = 0; i < n; ++i) {
      ans += (n-1)*sq(a[i]) - 2*a[i]*(s[n]-s[i+1]);
   }

   cout << ans << endl;
}
