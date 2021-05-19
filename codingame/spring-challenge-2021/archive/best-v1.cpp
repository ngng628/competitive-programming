# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(int)(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
using namespace chrono;
using ll = long long;
using ld = long double;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
using pii = pair<int, int>;
constexpr int INF = (1<<30)-(1<<15);
constexpr ll LINF = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T, std::size_t N> string join(const array<T, N> &v){ stringstream s; rep (i, N) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T, std::size_t N> ostream& operator <<(ostream& os, const array<T, N>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template <class T> [[nodiscard]] T scan(){ T a; cin >> a; cin.ignore(); return a; }
template <class T> [[nodiscard]] T scan(int n){ vec<T> a(n); cin >> a; cin.ignore(); return a; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }

template <typename Cont, typename Pred>
Cont filter(const Cont &container, Pred predicate) {
    Cont result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), predicate);
    return result;
}

class Stopwatch {
public:
   Stopwatch() { start = system_clock::now(); }
   void reset() noexcept { start = system_clock::now(); }
   [[nodiscard]] int ms() const noexcept { return duration_cast<milliseconds>(system_clock::now() - start).count(); }
   [[nodiscard]] int sec() const noexcept { return duration_cast<seconds>(system_clock::now() - start).count(); }

private:
   system_clock::time_point start;
} watch;

class Random {
public:
   Random() : x(1859738746), y(9707750167), z(2653432786), w(3463085849) {}
 
   [[nodiscard]] ll randint(ll n) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % n;
   }

   [[nodiscard]] ll randint(ll a, ll b) noexcept {
      uint64_t t = (x^(x<<11));
      x = y; y = z; z = w;
      w = (w^(w>>19))^(t^(t>>8));
      return w % (b - a) + a;;
   }

private:
   uint64_t x, y, z, w;
} rnd;
# endif  // ngng628_library

struct Cell {
   Cell() = default;
   int index;
   int richness;
   array<int, 6> neigh;
   friend istream& operator >>(istream& is, Cell& c) {
      return is >> c.index >> c.richness >> c.neigh;
   }
};

struct Spirit {
   Spirit() = default;
   int sun;
   int score;
   bool is_waiting;  // 入力としては敵のみ
   
   friend istream& operator >>(istream& is, Spirit& s) {
      return is >> s.sun >> s.score;
   }
};

struct Tree {
   Tree() : cell_index(-1), size(-1), is_mine(false), is_dormant(true) {}
   int cell_index;
   int size;
   bool is_mine;
   bool is_dormant;
   friend istream& operator >>(istream& is, Tree& t) {
      return is >> t.cell_index >> t.size >> t.is_mine >> t.is_dormant;
   }
};

enum ActionType {
   Wait, Grow, Seed, Complete
};

struct Action {
   Action() = default;
   Action(const string& s) {
      switch (s[0]) {
      case 'G':
         type = ActionType::Grow;
         index[0] = stoi(s.substr(5));
         index[1] = -1;
         break;
      case 'S':
         type = ActionType::Seed;
         sscanf(s.substr(5).c_str(), "%d%d", &index[0], &index[1]);
         break;
      case 'C':
         type = ActionType::Complete;
         index[0] = stoi(s.substr(9));
         index[1] = -1;
         break;
      default:
         type = ActionType::Wait;
         index[0] = index[1] = -1;
      }
   }
   Action(const ActionType& t, int i1, int i2 = -1) 
      : type(t)
      , index({i1, i2}) {}

   string str() const {
      switch (type) {
         case ActionType::Grow: return "GROW " + to_string(index[0]);
         case ActionType::Seed: return "SEED " + to_string(index[0]) + " " + to_string(index[1]);
         case ActionType::Complete: return "COMPLETE " + to_string(index[0]);
         case ActionType::Wait: return "WAIT";
         default: return "WAIT";
      }
      return "WAIT";
   }

   ActionType type;
   array<int, 2> index;
   friend ostream& operator <<(ostream& os, const Action& a){ return os << a.str(); }
};

int n_cells;
vec<Cell> cells;
vec<vec<int>> dist;
string logtxt;
struct State {
   State() = default;
   void read() {
      cin >> day; cin.ignore();
      cin >> nutrients; cin.ignore();
      cin >> me >> enemy; cin.ignore();
      cin >> enemy.is_waiting; cin.ignore();
      cin >> n_trees; cin.ignore();
      trees.resize(n_cells);
      rep (_, n_trees) {
         Tree t;
         cin >> t; cin.ignore();
         trees[t.cell_index] = t;
         both_trees.pb(t);
         if (t.is_mine) my_trees.pb(t);
         else enemy_trees.pb(t);
      }
      cin >> n_possible_actions; cin.ignore();
      possible_actions.resize(n_possible_actions);
      rep (i, n_possible_actions) {
         string s;
         getline(cin, s);
         possible_actions[i] = Action(s);
      }

      rep (i, 4) my_n_sizes[i] = 0;
      rep (i, n_cells) {
         if (trees[i].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
      }
      int shadow_direction = day % 6;
      shadows.resize(n_cells, 0);
      rep (i, n_cells) {
         int depth = trees[i].size;
         int idx = i;
         rep (_, depth) {
            idx = cells[idx].neigh[shadow_direction];
            if (idx == -1) break;
            shadows[idx]++;
         }
      }
   }
   void info() {
      eprint("[o]", "ゲームの情報");
      eprint("[+]", "day:", day);
      eprint("[+]", "nutrients:", nutrients);
      eprint("[+]", "me:");
      eprint("[-]", "score", me.score);
      eprint("[-]", "sun", me.sun);
      eprint("[+]", "enemy:");
      eprint("[-]", "score", enemy.score);
      eprint("[-]", "sun", enemy.sun);
      eprint("[+]", "trees:");
      eprint("[-]", "size 3:", count_if(all(trees), [](const Tree& t){ return t.size == 3; }));
      eprint("[-]", "size 2:", count_if(all(trees), [](const Tree& t){ return t.size == 2; }));
      eprint("[-]", "size 1:", count_if(all(trees), [](const Tree& t){ return t.size == 1; }));
      eprint("[-]", "size 0:", count_if(all(trees), [](const Tree& t){ return t.size == 0; }));
      eprint("[+]", "possible_actions", possible_actions);
   }

   vec<pair<State, Action>> nexts() const {
      vec<pair<State, Action>> res;
      return res;
   }

   ll eval() {
      return 0ll;
   }

   int day;
   int nutrients;
   Spirit me, enemy;
   int n_trees;
   vec<Tree> trees, my_trees, enemy_trees, both_trees;
   int n_possible_actions;
   vec<Action> possible_actions;

   array<int, 4> my_n_sizes, enemy_n_sizes;
   vi shadows;
};

// struct GameMaster {
//    GameMaster() = default;
//    GameMaster(const State s) : state(s) {}
//    State run(string s_my_act, string s_en_act) {
//       Action my_act(s_my_act), en_act(s_en_act);
//       if (my_act.type == ActionType::Seed and en_act.type == ActionType::Seed) {

//       }
//       else {
//          // 自分の行動
//          if (my_act.type == "WAIT") 
//          // 相手の行動
//       }
//    }
//    State state;
// };

string best_seed(const State& s) {
   // いい種の置き方とはなんですか？
   //   1. 影に当たりづらいこと
   //     A. 斜め対抗形であること
   //     B. 距離が（できれば）3 以上離れている
   //     C. これらが少なくとも自分の木同士では実現されていること
   //   2. 任意の木に対して、距離は 2 以上を取っていること
   //   3. richness に対して平等に扱っていること
   //     A. richness = 3 に固着しない
   //     B. richness = 1 は影を作り辛いという点で優秀
   //   4. 数は多くても 8 程度
   //   5. これらを満たさない置き方は「悪い置き方」である
   //   6. （できれば影が回ってきにくいようなところに置く）
   // 「悪い置き方」をする場合は置くべきではない
   // TODO: どの親を優先する？

   // (1.) > (2.) > (4.) > 実装できれば(6.)

   // shadow の最悪形の計算
   // 影の深さ 3 で、どの方向にも放射している
   vi strong_shadows(n_cells, 0);
   vi my_strong_shadows(n_cells, 0);
   rep (i, n_cells) {
      rep (shadow_direction, 6) {
         constexpr int depth = 3;
         int idx = i;
         rep (_, depth) {
            idx = cells[idx].neigh[shadow_direction];
            if (idx == -1) break;
            strong_shadows[idx]++;
            if (s.trees[i].is_mine) {my_strong_shadows[idx]++;}
         }
      }
   }
   priority_queue<tuple<int, int, int, int, int, int, int>> pq;
   rep (i, n_cells) {
      if (s.trees[i].size != -1 or cells[i].richness == 0) continue;
      /* コストは置く場所によらないのでカット */

      // 影に当たりやすいですか？
      int shadow = INF - strong_shadows[i];
      int my_shadow = INF - my_strong_shadows[i];
      // どの木とも距離は2以上ですか？
      int d2 = [&]() {
         for (const Tree& t : s.both_trees) {
            if (dist[t.cell_index][i] < 2) return 0;
         }
         return 1;
      }();
      // 自分の木に対してなら距離は 2 以上ですか？
      int md2 = [&]() {
         int score = 0;
         for (const Tree& t : s.my_trees) {
            if (dist[t.cell_index][i] < 2) score -= 20;
            else if (dist[t.cell_index][i] == 2) score++;
            else if (dist[t.cell_index][i] >= 3) score += 2;
         }
         return score;
      }();

      int rich = [&]() {
         int cnt = 0;
         rep (i, 7) if (s.trees[i].size != -1 and s.trees[i].is_mine) cnt++;
         return cnt == 0;
      }();

      // 本当に置けますか？
      for (auto&& p : s.my_trees) {
         if (dist[i][p.cell_index] <= p.size and not p.is_dormant and s.me.sun >= s.my_n_sizes[0]) {
            pq.emplace(my_shadow, rich, shadow, d2, md2, p.cell_index, i);
         }
      }
   }
   while (not pq.empty()) {
      auto [_0, _1, _2, _3, _4, from, to] = pq.top(); pq.pop();
      bool ok = true;
      rep (i, n_cells) {
         if (s.trees[i].is_mine and dist[i][to] < 2) {
            ok = false;
            break;
         }
      }
      if (ok) return Action(ActionType::Seed, from, to).str();
   }
   return "WAIT";
}

string best_grow(const State& s) {
   // 背が高いもの順に育てる
   priority_queue<tuple<int, int, int, int>> pq;
   for (auto&& t : s.my_trees) {
      if (t.is_dormant) continue;
      if (t.size == 3) continue;
      int cost = 2*(t.size + 1) + s.my_n_sizes[t.size + 1];
      int depth = 0 <= t.cell_index < 7 ? 1 : 7 <= t.cell_index < 19 ? 2 : 3;
      if (s.me.sun >= cost) pq.emplace(t.size == 1 and s.day <= 15 ? 2 : t.size, depth, cells[t.cell_index].richness, t.cell_index);
   }
   if (not pq.empty()) return Action(ActionType::Grow, get<3>(pq.top())).str();
   return "WAIT";
}

string best_complete(const State& s) {
   // richness が高いものから刈る
   priority_queue<tuple<int, int>> pq;
   for (auto&& t : s.my_trees) {
      if (t.is_dormant) continue;
      if (t.size < 3) continue;
      constexpr int cost = 4;
      if (s.me.sun >= cost) pq.emplace(cells[t.cell_index].richness, t.cell_index);
   }
   if (not pq.empty()) return Action(ActionType::Complete, get<1>(pq.top())).str();
   return "WAIT";
}

string rule_base(State s) {
   int day = s.day;
   // eprint("[day]", day);
   string res;
   // 序盤はガチ人力
   if (day <= 2) {
      // 2 本とも size 2 に進化させる
      for (auto&& tree : s.my_trees) {
         int cost = 1 + s.my_n_sizes[1];
         if (tree.size == 1 and s.me.sun >= cost and not tree.is_dormant) {
            return Action(ActionType::Grow, tree.cell_index).str();
         }
      }
      if (day == 2) return best_seed(s);
   }
   else if (len(s.my_trees) <= 5 and s.my_n_sizes[3] <= 3) {
      int less2 = s.my_n_sizes[0] + s.my_n_sizes[1] + s.my_n_sizes[2];
      if (less2 > s.my_n_sizes[3]) {
         auto res = best_grow(s);
         if (res != "WAIT") return res;
      }
      return best_seed(s);
   }
   else if (24 - day > s.my_n_sizes[3]) {
      // 育てまくる
      int cen = [&]() {
         int cnt = 0;
         rep (i, 7) if (s.my_trees[i].size == 3) cnt++;
         return cnt;
      }();
      int valcen = [&]() {
         int cnt = 0;
         rep (i, 7) if (cells[i].richness != 0 and s.trees[i].is_mine) cnt++;
         return cnt;
      }();
      string res = "WAIT";
      if (s.me.sun > 20 and s.my_n_sizes[3] >= 2 and best_complete(s) != "WAIT") {
          return best_complete(s);
      }
      else if ((cen >= (valcen - 2) and s.my_n_sizes[3] >= 6) or (logtxt.back() == 'C')) {
         string res = "WAIT";
         if ((s.me.sun >= 20 or logtxt.back() == 'C') and s.my_n_sizes[3] >= 3) res = best_complete(s);
         if (res != "WAIT") return res;
         return best_seed(s);
         if (res != "WAIT") return res;
         res = best_grow(s);
      }
      else {
         int less2 = s.my_n_sizes[0] + s.my_n_sizes[1] + s.my_n_sizes[2];
         if (less2 > s.my_n_sizes[3] and s.my_n_sizes[3] <= 6) {
            if (len(s.my_trees) > 4) res = best_grow(s);
            else {
               // 背が高いもの順に育てる
               priority_queue<tuple<int, int, int>> pq;
               for (auto&& t : s.my_trees) {
                  if (t.is_dormant) continue;
                  if (t.size == 3) continue;
                  int cost = 2*(t.size + 1) + s.my_n_sizes[t.size + 1];
                  if (s.me.sun >= cost) pq.emplace(3 - t.size, cells[t.cell_index].richness, t.cell_index);
               }
               if (not pq.empty()) return Action(ActionType::Grow, get<2>(pq.top())).str();
               return "WAIT";
            }
         }
         if (res != "WAIT") return res;
         if (len(s.my_trees) < 6 or len(s.my_trees) < len(s.enemy_trees)) res = best_seed(s);
        //  if (res != "WAIT" and s.me.sun >= 10) res = best_grow(s);
         return res;
      }
   }
   else {
      // 適当に背の高いものを刈る
      auto res = best_complete(s);
      if (res != "WAIT") return res;
      // 背の高いもの優先で育てる
      priority_queue<tuple<int, int>> pq;
      res = best_grow(s);
      if (res != "WAIT") return res;
      if (not pq.empty()) return Action(ActionType::Grow, get<1>(pq.top())).str();
   }
   return "WAIT";
}

int main() {
   cin >> n_cells; cin.ignore();
   cells.resize(n_cells);
   rep (i, n_cells) {
      Cell c;
      cin >> c; cin.ignore();
      cells[c.index] = c;
   }

   // ノード距離を計算
   dist.resize(n_cells, vi(n_cells, INF));
   rep (s, n_cells) {
      vi& d = dist[s];
      d[s] = 0;
      for (queue<int> que({s}); not que.empty();) {
         int now = que.front(); que.pop();
         for (int nxt : cells[now].neigh) {
            if (nxt == -1) continue;
            if (d[nxt] != INF) continue;
            d[nxt] = d[now] + 1;
            que.push(nxt);
         }
      }
   }

   int turn = 0;
   vec<string> greeting = {
      "glhf!",
      "Attention PLZ!",
   };
   vec<string> compete_str = {
      "Red Wisp Come On!",
      "Blue Wisp Come On!",
      "Trick or Treat!",
      "Silent Step!",
      "Eternity!",
      "Heavy Haze!",
      "Bats Storm!",
   };

   while (true) {
      State state;
      state.read();
      // state.info();
      string ans = rule_base(state);
      if (ans == "") ans = "WAIT";

      logtxt.pb(ans[0]);
      // eprint("[LOG]", logtxt);

      string day_str = "[" + to_string(state.day) + " day]";
      string message = ans;
      if (turn <= 1) print(ans, greeting[turn]);
      else if (not logtxt.empty() and logtxt.back() == 'C') print(ans, compete_str[rnd.randint(len(compete_str))]);
      else print(ans, day_str, message);
      turn++;
   }
}
