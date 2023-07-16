# include <bits/stdc++.h>
using namespace std;

struct MyString {
   string s;
   MyString() = default;
   MyString(const string& _s) : s(_s) {}

   friend bool operator <(const MyString& t) {
      
   }
};

int main() {
   int n;
   cin >> n;
   vector<string> s(n);
   for (string& si : s) cin >> si;

   
}