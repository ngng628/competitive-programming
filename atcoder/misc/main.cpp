# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using State = string::const_iterator;

ll qp(ll x, int n) {
   ll p = 1;
   while (n > 0) {
       if (n & 1) p *= x;
       x *= x;
       n >>= 1;
   }
   return p;
}

// これはネタです。
bool operator &(const vector<pair<ll, string>>& s, const vector<pair<ll, string>>& t) {
   return s == t;
}

int main() {
   while (true) {
      //────────────────────────────────────────
      //  1. 入力
      //────────────────────────────────────────
      int N, M;
      cin >> N >> M;
      if (!(N | M)) break;
      vector<string> S(N), T(M);
      for (auto& e : S) cin >> e;
      for (auto& e : T) cin >> e;

      //────────────────────────────────────────
      //  2. 構文解析器
      //────────────────────────────────────────
      struct Parser {
         vector<string> S;
         vector<pair<ll, string>> output;
         vector<ll> val;

         Parser(const vector<string>& s) : S(s), val(123) {};

         //! @brief プログラムを解析する
         vector<pair<ll, string>> parse() {
            for (string s : S) {
               State begin = s.begin();
               string sub = s.substr(0, 3);
               if (sub.size() == 1) declaration(begin);
               else if (sub[1] == '<') assignment(begin);
               else if (sub == "for") for_statement(begin);
               else print(begin);
            }
            return output;
         }

         //! @brief 文字列をスキップする
         void skip(State& itr, const string& s) { rep (_, s.size()) ++itr; }

         //! @brief 変数を宣言する
         void declaration(State& itr) {
            val[*itr++] = 0;
         }

         //! @brief 変数に値を代入する
         void assignment(State& itr) {
            char name = *itr++;
            skip(itr, "<--");
            val[name] = expression(itr);
         }

         //! @brief for文全体
         void for_statement(State& itr) {
            vector<ll> n_loops;
            n_loops.push_back(for_loop(itr));
            while (true) {
               if (*next(itr) == 'o') {
                  n_loops.push_back(for_loop(itr));
               }
               else if (*next(itr) == '<') {
                  ll prod = count(n_loops.begin(), n_loops.end(), 0LL)
                        ? 0LL
                        : accumulate(n_loops.begin(), n_loops.end(), 1LL, multiplies<ll>());
                  for_assignment(itr, prod);
                  break;
               }
               else if (*next(itr) == 'r') { // print の i
                  ll prod = count(n_loops.begin(), n_loops.end(), 0LL)
                        ? 0LL
                        : accumulate(n_loops.begin(), n_loops.end(), 1LL, multiplies<ll>());
                  print(itr, prod);
                  break;
               }
            }
         }

         //! @brief for文
         ll for_loop(State& itr) {
            skip(itr, "for(");
            ll a = expression(itr);
            skip(itr, ",");
            ll b = expression(itr);
            skip(itr, ")");
            return max(b - a + 1, 0LL);
         }

         //! @brief for文後の代入
         void for_assignment(State& itr, ll num) {
            if (num == 0) return;
            char name = *itr++;
            skip(itr, "<--");
            vector<string> terms;
            while (*itr > 0) terms.push_back(term_str(itr));

            ll k = 0; // 変数 name の係数
            ll b = 0; // 変数 name の以外の定数
            for (string term : terms) {
               if (term[0] == '+') {
                  if (term[1] == name) k += 1;
                  else if (isdigit(term[1])) b += stoi(term);
                  else b += val[term[1]];
               }
               else if (term[0] == '-') {
                  if (term[1] == name) k -= 1;
                  else if (isdigit(term[1])) b += stoi(term);
                  else b -= val[term[1]];
               }
               else {
                  if (term[0] == name) k += 1;
                  else if (isdigit(term[0])) b += stoll(term);
                  else b += val[term[0]];
               }
            }

            // 実際の代入処理
            if (k == 0) val[name] = b;
            else if (k == 1) val[name] = b*num + val[name];
            else {
               long long frac = qp(k, num) - 1;
               frac /= k - 1;
               frac *= b;
               val[name] = frac + val[name] * qp(k, num);
            }
         }

         //! @brief 文字列として数式の項の集合を返す
         string term_str(State& itr) {
            if (*itr == '+') return "+" + value_str(++itr);
            else if (*itr == '-') return "-" + value_str(++itr);
            else {
               string res = "+" + value_str(itr);
               ++itr;
               return res;
            }
         }

         //! @brief 文字列として、数字は数値、変数は変数名を返す
         string value_str(State& itr) {
            if (isdigit(*itr)) return to_string(number(itr));
            else return string(1, *itr++);
         }

         //! @brief 画面出力された文字列を追加
         void print(State& itr, ll num = 1) {
            if (num == 0) return;

            skip(itr, "print(");
            ll expr = expression(itr);
            cout << "<expr> = "<< expr << endl;
            cout << "<a> = "<< val['a'] << endl;
            skip(itr, ")");

            if (output.empty()) {
               output.emplace_back(num, to_string(expr));
               return;
            }

            if (to_string(expr) == output.back().second) output.back().first += num;
            else output.emplace_back(num, to_string(expr));
         }

         //! @brief 数式の値を整数値で返す
         ll expression(State& itr) {
            ll ret = term(itr);
            while (*itr == '+') ret += term(++itr);
            cout << "<ret> = " << ret << endl;
            return ret;
         }

         //! @brief 項の値を整数値で返す
         ll term(State& itr) {
            if (*itr == '+') return value(++itr);
            else if (*itr == '-') return -value(++itr);
            else return value(itr);
         }

         //! @brief 数字または変数の値を整数値で返す
         ll value(State& itr) {
            if (isdigit(*itr)) return number(itr);
            else return val[*itr++];
         }

         //! @brief 数字を整数値で返す
         ll number(State& itr) {
            ll ret = 0;
            while (isdigit(*itr)) {
               ret *= 10;
               ret += *itr - '0';
               ++itr;
            }
            return ret;
         }
      };

      //────────────────────────────────────────
      //  3. ユウちゃん&レイくんのプログラムを実行
      //────────────────────────────────────────
      auto Yu = Parser(S).parse();
      auto Rei = Parser(T).parse();

      //────────────────────────────────────────
      //  4. 二人の出力の一致判定
      //────────────────────────────────────────
      for (auto [L, expr] : Yu) {
         cout << L << ' ' << expr << endl;
      }
      cout << "---" << endl;
      for (auto [L, expr] : Rei) {
         cout << L << ' ' << expr << endl;
      }
      puts(Yu & Rei ? "OK" : "FAIL");
      cout << "===========" << endl;
   }
}