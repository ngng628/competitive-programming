# include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   string s1 = s.substr(0, s.length() / 2);
   string s2 = [](string s){ reverse(s.begin(), s.end()); return s; }(s.substr((s.length() + 1) / 2));

   vector<int> range(s.length() / 2);
   iota(range.begin(), range.end(), 0);
   cout << count_if(range.begin(), range.end(), [&](int i){ return s1[i] != s2[i]; }) << endl;
}