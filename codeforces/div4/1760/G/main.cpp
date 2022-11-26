# include <bits/stdc++.h>
# define int long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

struct Edge {
   Edge() = default;
   Edge(int t, int w) : to(t), weight(w) {}
   int to;
   int weight;
};

int32_t main() {
   int t;
   cin >> t;
   
   vector<bool> answers;

   while (t--) {
      int n, a, b;
      cin >> n >> a >> b;
      a--, b--;
      
      vector<vector<Edge>> graph(n);
      for (int i = 0; i < n - 1; i++) {
         int u, v, w;
         cin >> u >> v >> w;
         u--, v--;
         graph[u].emplace_back(v, w);
         graph[v].emplace_back(u, w);
      }

      auto calc = [&](int start) {
         constexpr int NIL = -1;
         vector<int> values(n, NIL);
         values[start] = 0;
         queue<int> que({ start });
         while (!que.empty()) {
            int from = que.front();
            que.pop();
            for (auto& e : graph[from]) {
               if (values[e.to] != NIL) {
                  continue;
               }
               if (e.to == b) {
                  continue;
               }
               values[e.to] = values[from] ^ e.weight;
               que.push(e.to);
            }
         }
         return values;
      };

      auto from_a = calc(a);
      auto from_b = calc(b);

      set<int> as;
      for (int i = 0; i < n; i++) {
         if (i == a) {
            continue;
         }
         as.insert(from_a[i]);
      }

      bool ans = from_a[b] == 0;
      for (int i = 0; i < n; i++) {
         if (i == a) {
            continue;
         }
         ans |= (as.count(from_b[i]) == 1);
      }
      answers.push_back(ans);
   }

   for (bool ans : answers) {
      puts(ans ? "YES" : "NO");
   }
}
