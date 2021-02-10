# include <bits/stdc++.h>
using namespace std;

int main() {
   int V, T, S, D;
   cin >> V >> T >> S >> D;
   double t = (double) D / V;
   cout << (t < T or S < t ? "Yes" : "No") << endl;
}
