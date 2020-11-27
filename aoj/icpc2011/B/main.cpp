# include <bits/stdc++.h>
# define all(v) std::begin(v), std::end(v)
using namespace std;

void Main(string s) {
   stack<char> stk;
   string marks = [](){ string m = "([])"; sort(all(m)); return m; }();
   map<char, char> mp;
   mp['['] = ']'; mp[']'] = '[';
   mp['('] = ')'; mp[')'] = '(';
   for (char c : s) {
      if (marks.find(c) != string::npos) {
         if (c == '(' or c == '[') {
            stk.push(c);
         }
         else {
            if (stk.empty()) {
               cout << "no" << endl;
               return;
            }
            else {
               char now = stk.top(); stk.pop();
               if (mp[now] != c) {
                  cout << "no" << endl;
                  return;
               }
            }
         }
      }
   }
   puts(stk.empty() ? "yes" : "no");
}

int main() {
   while (true) {
      string s;
      do { getline(cin, s); } while (s.empty());
      if (s == ".") break;
      Main(s);
   }
   return 0;
}
