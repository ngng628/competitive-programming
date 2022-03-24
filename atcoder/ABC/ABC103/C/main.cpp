# include <bits/stdc++.h>
using namespace std;

int main() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   int ans = accumulate(istream_iterator<int>(cin), istream_iterator<int>(), 0, [](int acc, int x){ return acc + x - 1; });
   cout << ans << endl;
}