# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;

int main() {
   int n, q;
   cin >> n >> q;
   vector<vector<int>> graph(n);
   rep (_, n - 1) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   vector<int> parity(n, -1);
   parity[0] = 0;
   for (queue<int> que({0}); not que.empty();) {
      int now = que.front(); que.pop();
      for (int nxt : graph[now]) {
         if (parity[nxt] != -1) continue;
         parity[nxt] = parity[now] ^ 1;
         que.push(nxt);
      }
   }

   while (q--) {
      int c, d;
      cin >> c >> d;
      c--, d--;
      puts(parity[c] xor parity[d] ? "Road" : "Town");
   }
}