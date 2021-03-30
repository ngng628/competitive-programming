# include <bits/stdc++.h>
using namespace std;

int main() {
   uint16_t P, Q, R;
   cin >> P >> Q >> R;
   cout << P + Q + R - max({P, Q, R}) << "\n";
}
