# include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> A(n);
   for (int& e : A) cin >> e;
   vector<int> B(n);
   for (int& e : B) cin >> e;

   sort(begin(A), end(A));
   sort(begin(B), end(B));

   long long sum = 0;
   for (int i = 0; i < n; ++i) {
      sum += abs(A[i] - B[i]);
   }

   cout << sum << endl;
}