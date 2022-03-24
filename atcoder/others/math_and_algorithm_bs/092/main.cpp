# pragma GCC optimize("Ofast")
# include <bits/stdc++.h>
using namespace std;

int main() {
   long long n = 0;
   char c = getchar_unlocked();
   for (; isdigit(c); c = getchar_unlocked()) {
      n = 10*n + (c - '0');
   }

   const int u = sqrt(n) + 1;
   for (int w = u; w >= 1; --w) {
      if (n % w == 0) {
         printf("%lld\n", (n / w + w) << 1);
         break;
      }
   }
}