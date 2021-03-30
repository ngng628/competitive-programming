# include <bits/stdc++.h>
using namespace std;

int main() {
   int a, b;
   cin >> a >> b;
   if (a + b >= 15 and b >= 8) puts("1");
   else if (a + b >= 10 and b >= 3) puts("2");
   else if (a + b >= 3) puts("3");
   else puts("4");
}
