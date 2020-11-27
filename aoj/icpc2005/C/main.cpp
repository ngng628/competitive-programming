//    _        _     _         _               _    
//   | |__    (_)   | |__     (_)     ___     (_)   
//   | / /    | |   | '_ \    | |    (_-<     | |   
//   |_\_\   _|_|_  |_.__/   _|_|_   /__/_   _|_|_  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
//
# include <bits/stdc++.h>
int ctoi(char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; };
using namespace std;


int decode(const string& s) {
   map<char, int> mcxi;
   mcxi['m'] = 1000; mcxi['c'] = 100;
   mcxi['x'] = 10;   mcxi['i'] = 1;

   int res = 0;
   int pre = -1;
   for (char c : s) {
      int num = ctoi(c);
      if (num == -1) {
         if (pre == -1) res += mcxi[c];
         else res += pre*mcxi[c];
         pre = -1;
      }
      else pre = num;
   }

   return res;
}

template <class Integer> Integer GetDigit(Integer n) {
   if (n == 0) return 1;
   Integer d = 0;
   while (n) {
      n /= 10;
      d++;
   }
   return d;
}

string encode(int n) {
   string res = "";
   const string mcxi  = "mcxi";
   const int digit = GetDigit(n);
   stack<int> stk;

   while (n) {
      int a = n % 10;
      stk.push(a);
      n /= 10;
   }

   int i = 4 - digit;
   while (not stk.empty()) {
      int a = stk.top(); stk.pop();
      if (a == 0);
      else if (a == 1) res += mcxi[i];
      else res += to_string(a) + mcxi[i];
      i++;
   }

   return res;
}

int32_t main() {
   int t;
   cin >> t;
   while (t--) {
      string s, t;
      cin >> s >> t;
      cout << encode(decode(s) + decode(t)) << endl;
   }

   return 0;
}
