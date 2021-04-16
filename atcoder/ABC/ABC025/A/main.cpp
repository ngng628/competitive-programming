# include <bits/stdc++.h>
# define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
   string s;
   int n;
   cin >> s >> n;

   vector<string> a(25);
   rep (i, 5) rep (j, 5) a[5*i + j] = {s[i], s[j]};
   sort(a.begin(), a.end());

   cout << a[n-1] << "\n";
}
