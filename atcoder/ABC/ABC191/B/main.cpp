# include <bits/stdc++.h>
using namespace std;

int main() {
   int N, X;
   cin >> N >> X;
   vector<int> A(N);
   for (int& a : A) cin >> a;

   auto result = remove(A.begin(), A.end(), X);
   for (auto it = A.begin(); it != result; ++it) {
      if (it != A.begin()) cout << " ";
      cout << *it;
   }
   cout << endl;
}
