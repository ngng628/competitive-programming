# include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> a = {1, 2, 4, 5};
   // aの中の最大値のイテレータ
   cout << *min_element(a.begin(), a.end()) << "\n";

   return 0;
}