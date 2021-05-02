# include <bits/stdc++.h>
using namespace std;

vector<string> splited(const string &s, char delim) {
   vector<string> elems;
   string item;
   for (char c : s) {
      if (c == delim) {
         if (not item.empty()) elems.push_back(item);
         item.clear();
      }
      else item += c;
   }
   if (not item.empty()) elems.push_back(item);
   return elems;
}

int main() {
   string s;
   cin >> s;
   auto t = splited(s, ',');
   cout << t[0] << " " << t[1] << " " << t[2] << "\n";
}