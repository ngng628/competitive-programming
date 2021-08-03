# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
int ctoi(char c){ return c - '0'; }

int main() {
   auto f = [](string s) {
      if (s[0] == 'B') return -(ctoi(s[1]) - 1);
      else return ctoi(s[0]);
   };

   string s, t;
   cin >> s >> t;

   cout << abs(f(s) - f(t)) << "\n";
}