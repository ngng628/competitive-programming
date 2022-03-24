# include <bits/stdc++.h>
using namespace std;

int main() {
   multiset<int> ms;
   ms.insert(10);
   ms.insert(9);
   ms.insert(8);
   cout << *ms.begin() << endl;
}