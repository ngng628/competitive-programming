# include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;

   if (s.size() == 8 && isupper(s[0]) && isupper(s.back())) {
      auto sub = s.substr(1, 6);
      if (all_of(sub.begin(), sub.end(), [](char c){ return isdigit(c); }) && s[1] != '0') {
         cout << "Yes" << endl;
      }
      else {
         cout << "No" << endl;
      }
   }
   else {
      cout << "No" << endl;
   }
}