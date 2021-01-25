# include <bits/stdc++.h>
# define all(v) begin(v), end(v)
using namespace std;

int main() {
   string a, b;
   cin >> a >> b;
   auto sum = [](int acc, int i){ return acc + i; };
   auto ctoi = [](char c){ return c - '0'; };
   int sa = transform_reduce(all(a), 0, sum, ctoi);
   int sb = transform_reduce(all(b), 0, sum, ctoi);
   cout << max(sa, sb) << endl;
}
