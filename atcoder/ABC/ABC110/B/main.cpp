# include <bits/stdc++.h>
using namespace std;

int main() {
   int N, M, X, Y;
   cin >> N >> M >> X >> Y;
   vector<int> x(N), y(M);
   for (auto& e : x) cin >> e;
   for (auto& e : y) cin >> e;
   x.push_back(X);
   y.push_back(Y);
   int lower = *max_element(x.begin(), x.end());
   int upper = *min_element(y.begin(), y.end());
   cout << (upper - lower <= 0 ? "War" : "No War") << endl;
}