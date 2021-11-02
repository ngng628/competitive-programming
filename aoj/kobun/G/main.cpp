# include <bits/stdc++.h>
using ll = long long;
using namespace std;

using State = string::const_iterator;
void skip(State& it, char c) { assert(c == *it); ++it; }

struct Node;
using pNode = shared_ptr<Node>;
struct Node {
   int root;
   Node() : root(-1), left(nullptr), right(nullptr) {}
   shared_ptr<Node> left, right;
};


int main() {
   string s, t;
   cin >> s >> t;

   struct Parser {
      string s;
      Parser(string _s) : s(_s) {}
      pNode parse() {
         State it = s.begin();
         return tree(it);
      }

      pNode tree(State& it) {
         pNode n = make_shared<Node>();

         skip(it, '(');
         if (*it == '(') n->left = tree(it);
         else n->left = nullptr;
         skip(it, ')');

         skip(it, '[');
         n->root = number(it);
         skip(it, ']');

         skip(it, '(');
         if (*it == '(') n->right = tree(it);
         else n->right = nullptr;
         skip(it, ')');

         return n;
      }

      int number(State& it) {
         int res = 0;
         for (; isdigit(*it); ++it) {
            res *= 10;
            res += *it - '0';
         }
         return res;
      }
   };

   pNode a = Parser(s).parse();
   pNode b = Parser(t).parse();

   string c;
   auto rec = [&](auto&& self, pNode p, pNode q) -> void {
      c.push_back('(');
      if (p->left != nullptr and q->left != nullptr) {
         self(self, p->left, q->left);
      }
      c.push_back(')');

      c.push_back('[');
      c.append(to_string(p->root + q->root));
      c.push_back(']');

      c.push_back('(');
      if (p->right != nullptr and q->right != nullptr) {
         self(self, p->right, q->right);
      }
      c.push_back(')');
   };
   rec(rec, a, b);

   cout << c << endl;

   return 0;
}
