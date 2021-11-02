# include <bits/stdc++.h>
using namespace std;
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); cout << fixed << setprecision(16); } } setup_io;

using State = string::const_iterator;
int ctoi(char c) { assert('0' <= c and c <= '9'); return c - '0'; }

string concat(const vector<string>& ss) {
   string s;
   for (const auto& t : ss) s.append(t);
   return s;
}

bool Main() {
   int n;
   cin >> n;
   if (!n) return false;

   vector<string> ss(n);
   for (auto& s : ss) cin >> s;

   class Parser {
   public:
      Parser() = default;
      Parser(const vector<string>& ss) : s(concat(ss)), end(s.end()) {}

      int parse() {
         State begin = s.begin();
         return expr(begin);
      }

   private:
      string s;
      const State end;

      int expr(State& it) {
         if (*it == '+') return sum(++it, 0);
         else if (*it == '*') return prod(++it, 0);
         else return ctoi(*it);
      }

      int sum(State& it, int lv) {
         int res = 0;
         while (true) {
            int now = level(it);
            if (lv + 1 != now) {
               while (now--) --it;
               break;
            }
            else if (*it == '+') res += sum(++it, now);
            else if (*it == '*') res += prod(++it, now);
            else if (isdigit(*it)) res += number(it);
            else break;
         }
         return res;
      }

      int prod(State& it, int lv) {
         int res = 1;
         while (true) {
            int now = level(it);
            if (lv + 1 != now) {
               while (now--) --it;
               break;
            }
            else if (*it == '+') res *= sum(++it, now);
            else if (*it == '*') res *= prod(++it, now);
            else if (isdigit(*it)) res *= number(it);
            else break;
         }
         return res;
      }

      int level(State& it) {
         int res = 0;
         for (; *it == '.'; ++it) res++;
         return res;
      }

      int number(State& it) {
         int res = 0;
         for (; isdigit(*it); ++it) {
            res *= 10;
            res += ctoi(*it);
         }
         return res;
      }
   };

   cout << Parser(ss).parse() << endl;
   return true;
}

int main() {
   while (Main());
}
