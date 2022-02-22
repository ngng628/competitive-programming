# include <bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < int(n); ++i)
# define len(v) std::size(v)
using namespace std;
template <class T> using vec = vector<T>;

struct Code {
   Code() = default;
   Code(char c, int r, int s) : ch(c), ren(r), sw(s) {}
   char ch;
   int ren;
   int sw; // 何文字進んだら !ch になるか
};
vec<Code> RunLengthEncoding(const string& s) {
   vec<pair<char, int>> code;
   for (const auto& e : s) {
      if (code.empty() or code.back().first != e) code.emplace_back(e, 1);
      else code.back().second++;
   }
   vec<Code> res;
   rep (i, len(code)) {
      rep (j, code[i].second) {
         res.emplace_back(code[i].first, code[i].second, code[i].second - j);
      }
   }
   return res;
}

int main() {
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   auto code = RunLengthEncoding(s);
   int now = n;
   deque<int> ans;
   while (now != 0) {
      int nxt = max(0, now - m);
      int diff = now - nxt;
      if (code[nxt].ch == '0') {
         ans.push_front(diff);
         now = nxt;
      }
      else {
         int tmp = diff - code[nxt].sw;
         if (tmp <= 0) return puts("-1"), 0;
         now = now - tmp;
         ans.push_front(tmp);
      }
   }

   rep (i, len(ans)) {
      if (i != 0) cout << ' ';
      cout << ans[i];
   }
   cout << '\n';
}
