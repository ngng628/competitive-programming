# include <bits/stdc++.h>
# define rep(i,n) for(int i=0; i<(n); ++i)
# define sz(v) (int)(v).size()
using namespace std;

bool is_choku1(char c) {
   return c == 'o' or c == 'k' or c == 'u';
}

string yn(bool b) {
   return b ? "YES" : "NO";
}

int main() {
   string X;
   cin >> X;
   int n = sz(X);
   bool choku = true;
   rep (i, n) {
      choku &= is_choku1(X[i]) or (i+1 < n and X[i] == 'c' and X[++i] == 'h');
   }

   cout << yn(choku) << endl;

   return 0;
}
