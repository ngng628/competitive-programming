# include <bits/stdc++.h>
using namespace std;

int main() {
   int a, b;
   cin >> a >> b;
   ostringstream oss;
   oss << b / 2  << (b & 1 ? 5 : 0) << a << endl;
   cout << stoll(oss.str()) << endl;
}