# include <bits/stdc++.h>
using namespace std;

int main() {
   string s, t;
   cin >> s >> t;

   bool ans = s == t;
   for (size_t i = 0; i < s.length() - 1; i++) {
      swap(s[i], s[i + 1]);
      ans |= s == t;
      swap(s[i], s[i + 1]);
   }

   puts(ans ? "Yes" : "No");
}