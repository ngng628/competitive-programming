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


struct GameMaster {
   GameMaster() = default;
   GameMaster(const State& s) : state(init), init(s) {}
   // 返り値: ゲームが終了したか
   bool run(Action my_act, Action en_act) {
      if (state.me.is_waiting) my_act = Action("WAIT");
      if (state.enemy.is_waiting) en_act = Action("WAIT");

      // 行動受理
      if (my_act.type == ActionType::Seed and en_act.type == ActionType::Seed) {

      }
      else if (my_act.type == ActionType::Complete and en_act.type == ActionType::Complete) {

      }
      else {
         // ☆自分の行動☆
         if (my_act.type == ActionType::Grow) {
            if (not state.can_action(my_act, true)) return ngng(true);
            // treesに関する他のパラメータが変更されていないのでバグる
            int idx = my_act.index[0];
            Tree& t = state.trees[idx];
            int cost = (t.size == 2 ? 7 : 2*t.size + 1) + state.my_n_sizes[t.size + 1];
            state.trees[idx].size++;
            state.me.sun -= cost;
            state.trees[idx].is_dormant = true;
         }
         else if (my_act.type == ActionType::Seed) {
            if (not state.can_action(my_act, true)) return ngng(true);
            int cost = state.my_n_sizes[0];
            auto [idx1, idx2] = my_act.index;
            // treesに関する他のパラメータ以下略
            state.trees[idx2].size++;
            state.me.sun -= cost;
            state.trees[idx1].is_dormant = true;
            state.trees[idx2].is_dormant = true;
            state.trees[idx2].is_mine = true;
         }
         else if (my_act.type == ActionType::Complete) {
            if (not state.can_action(my_act, true)) return ngng(true);
            int idx = my_act.index[0];
            constexpr int cost = 4;
            
            state.trees[idx] = Tree();
            state.me.sun -= cost;
            state.me.score += state.nutrients + 2*(cells[idx].richness - 1);
            state.nutrients = max(0, state.nutrients - 1);
         }
         else {  // Wait
            state.me.is_waiting = true;
         }

         // ☆相手の行動☆
         if (en_act.type == ActionType::Grow) {
            if (state.can_action(en_act, false)) return ngng(false);
            int idx = en_act.index[0];
            Tree& t = state.trees[idx];
            int cost = (t.size == 2 ? 7 : 2*t.size + 1) + state.enemy_n_sizes[t.size + 1];

            // treesに関する他のパラメータが変更されていないのでバグる
            state.trees[idx].size++;
            state.enemy.sun -= cost;
            state.trees[idx].is_dormant = true;
         }
         else if (en_act.type == ActionType::Seed) {
            if (state.can_action(en_act, false)) return ngng(false);
            auto [idx1, idx2] = en_act.index;
            int cost = state.enemy_n_sizes[0];

            // treesに関する他のパラメータ以下略
            state.trees[idx2].size++;
            state.enemy.sun -= cost;
            state.trees[idx1].is_dormant = true;
            state.trees[idx2].is_dormant = true;
            state.trees[idx2].is_mine = false;
         }
         else if (en_act.type == ActionType::Complete) {
            if (state.can_action(en_act, false)) return ngng(false);
            int idx = en_act.index[0];
            constexpr int cost = 4;
            
            state.trees[idx] = Tree();
            state.enemy.sun -= cost;
            state.enemy.score += state.nutrients + 2*(cells[idx].richness - 1);
            state.nutrients = max(0, state.nutrients - 1);
         }
         else {  // Wait
            state.enemy.is_waiting = true;
         }
      }
      state.update();

      // 行動受付完了
      if (state.me.is_waiting and state.enemy.is_waiting) {
         // 日を進める
         state.day++;
         if (state.day == 24) return true;

         // 影の計算
         int shadow_direction = state.day % 6;
         vi shadows(n_cells, 0);
         rep (i, n_cells) {
            int depth = state.trees[i].size;
            int idx = i;
            rep (_, depth) {
               idx = cells[idx].neigh[shadow_direction];
               if (idx == -1) break;
               chmax(shadows[idx], state.trees[i].size);
            }
         }

         // SUNポイントの授与
         for (Tree& t : state.trees) {
            if (t.is_mine and shadows[t.cell_index] < t.size) state.me.sun += max(0, t.size);
            if (not t.is_mine and shadows[t.cell_index] < t.size) state.enemy.sun += max(0, t.size);
         }

         // WAITの解除
         state.me.is_waiting = state.enemy.is_waiting = false;
      }
      return false;
   }

   bool ngng(bool is_me) {
      if (is_me) {
         state.me.score = -INF;
         state.enemy.score = INF;
      }
      else {
         state.me.score = INF;
         state.me.score = -INF;
      }
      return true;
   }

   void reset() {
      state = init;
   }

   State state;

private:
   State init;
};
int n_cells;
vec<Cell> cells;
vec<vec<int>> dist;
string logtxt;
int n_my_completed, n_enemy_completed;
int my_seed_day, my_grow_day, my_complete_day;
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
      rep (i, 4) enemy_n_sizes[i] = 0;
      rep (i, n_cells) {
         if (trees[i].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
         else enemy_n_sizes[trees[i].size]++;
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

   bool can_action(Action act, bool is_me) const {
      if (is_me) {
         if (act.type == ActionType::Grow) {
            auto [idx, _] = act.index;
            const Tree& t = trees[idx];
            if (t.is_dormant and not t.is_mine) return false;
            if (t.size == -1 or t.size == 3) return false;
            int cost = (t.size == 2 ? 7 : 2*t.size + 1) + my_n_sizes[t.size + 1];
            if (me.sun < cost) return false;
         }
         else if (act.type == ActionType::Seed) {
            auto [idx1, idx2] = act.index;
            const Tree& t = trees[idx1];
            if (t.is_dormant or not t.is_mine) return false;
            if (t.size == 0) return false;
            if (cells[idx2].richness == 0) return false;
            if (trees[idx2].size != -1) return false;
            if (dist[idx1][idx2] > t.size) return false;
            int cost = my_n_sizes[0];
            if (me.sun < cost) return false;
         }
         else if (act.type == ActionType::Complete) {
            auto [idx, _] = act.index;
            const Tree& t = trees[idx];
            if (t.is_dormant or not t.is_mine) return false;
            if (t.size != 3) return false;
            constexpr int cost = 4;
            if (me.sun < cost) return false;
         }
         else {  // Wait
            // 何もしない
         }
      }
      else {
         if (act.type == ActionType::Grow) {
            auto [idx, _] = act.index;
            const Tree& t = trees[idx];
            if (t.is_dormant and t.is_mine) return false;
            if (t.size == -1 or t.size == 3) return false;
            int cost = (t.size == 2 ? 7 : 2*t.size + 1) + enemy_n_sizes[t.size + 1];
            if (enemy.sun < cost) return false;
         }
         else if (act.type == ActionType::Seed) {
            auto [idx1, idx2] = act.index;
            const Tree& t = trees[idx1];
            if (t.is_dormant or t.is_mine) return false;
            if (t.size == 0) return false;
            if (cells[idx2].richness == 0) return false;
            if (trees[idx2].size != -1) return false;
            if (dist[idx1][idx2] > t.size) return false;
            int cost = enemy_n_sizes[0];
            if (enemy.sun < cost) return false;
         }
         else if (act.type == ActionType::Complete) {
            auto [idx, _] = act.index;
            const Tree& t = trees[idx];
            if (t.is_dormant or t.is_mine) return false;
            if (t.size != 3) return false;
            constexpr int cost = 4;
            if (enemy.sun < cost) return false;
         }
         else {  // Wait
            // 何もしない
         }
      }
      return true;
   }

   vec<Action> next_actions(bool is_me) const {
      vec<Action> res;
      rep (i, n_cells) {
         auto grow = Action(ActionType::Grow, i);
         if (can_action(grow, is_me)) res.pb(grow);
         rep (j, n_cells) {
            auto seed = Action(ActionType::Seed, i, j);
            if (can_action(seed, is_me)) res.pb(seed);
         }
         auto complete = Action(ActionType::Complete, i);
         if (can_action(complete, is_me)) res.pb(complete);
      }
      return res;
   }

   pair<vec<State>, vec<Action>> next_all() const {
      GameMaster gm(*this);
      auto acts = next_actions(true);
      auto oppacts = next_actions(false);
      pair<vec<State>, vec<Action>> res;
      for (auto act : acts) {
         for (auto& opp : oppacts) {
            gm.run(act, opp);
            res.fi.eb(gm.state, act);
            gm.reset();
         }
      }
      return res;
   }

   void update() {
      // my_tree と enemy_tree と both_tree
      my_trees.clear(), enemy_trees.clear(), both_trees.clear();
      rep (i, n_cells) {
         if (trees[i].size == -1) continue;
         both_trees.pb(trees[i]);
         if (trees[i].is_mine) my_trees.pb(trees[i]);
         else enemy_trees.pb(trees[i]);
      }
      // n_sizes
      rep (i, 4) my_n_sizes[i] = enemy_n_sizes[i] = 0;
      rep (i, n_cells) {
         if (trees[i].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
         if (not trees[i].is_mine) if (trees[i].size != 1) my_n_sizes[trees[i].size]++;
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
   // もしかしたら COST=0 じゃないのに種飛ばすの悪手かも^^;

   // (1.) > (2.) > (4.) > 実装できれば(6.)
   bool rich = [&]() {
      int cnt = 0;
      rep (i, 7) if (s.trees[i].size != -1 and s.trees[i].is_mine) cnt++;
      return cnt <= 1;
   }();

   // shadow の最悪形の計算
   // 影の深さ 3 で、どの方向にも放射している
   vi strong_shadows(n_cells, 0);
   vi my_strong_shadows(n_cells, 0);
   rep (i, n_cells) {
      rep (shadow_direction, 6) {
         int depth = rich ? 2 : 3;
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
      if (rich) my_shadow = INF - (bool)my_strong_shadows[i];
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

      int richness = cells[i].richness;
      // 本当に置けますか？
      for (auto&& p : s.my_trees) {
         if (dist[i][p.cell_index] <= p.size and not p.is_dormant and s.me.sun >= s.my_n_sizes[0]) {
            pq.emplace(my_shadow, richness, shadow, d2, md2, p.cell_index, i);
         }
      }
   }
   while (not pq.empty()) {
      auto [_0, _1, _2, _3, _4, from, to] = pq.top(); pq.pop();
      bool ok = true;
      rep (i, n_cells) {
         // ソーシャルディスタンスを保とう
         if (s.trees[i].is_mine and dist[i][to] < 2) {
            ok = false;
            break;
         }
         const int cost = s.my_n_sizes[0];
         if (cost > 0) {
            ok = false;
            break;
         }
      }
      if (ok) return Action(ActionType::Seed, from, to).str();
   }
   return "WAIT";
}

string best_grow(const State& s) {
   // いい育て方とはなんですか？
   //   1. バランス重視
   //     A. 木の成長に偏りがない
   //   2. なるべく 1 本は size = 3 があるように
   //   3. そんなに焦る必要もない
   // MEMO:
   //    COMPLETEしだすとそうも行っていられなくて、size3 が常に存在するように
   //    リソースをうまく管理する必要がある

   // 基本スタンスは サンパワーの消費 > size が大きい順 > 種を飛ばしやすいか > richness
   // COMPLETE が発生しだした場合:
   //    常に size3 が発生できるように頑張る
   priority_queue<tuple<int, int, int, int, int>> pq;
   for (auto&& t : s.my_trees) {
      if (t.is_dormant or t.size == 3) continue;
      int cost = (t.size == 2 ? 7 : 2*t.size + 1) + s.my_n_sizes[t.size + 1];
      if (s.me.sun < cost) continue;

      int idx = t.cell_index;

      // 距離 2 以上で飛ばせるところが何個ある？
      int flyness = [&s]() {
         int cnt = 0;
         rep (i, n_cells) {
            if (cells[i].richness != 0 and s.trees[i].size == -1) cnt++;
         }
         return cnt;
      }();

      if (n_my_completed == 0) {
         if (s.day <= 4 and s.day <= 10) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
         else if (len(s.my_trees) <= 6) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
         else if (s.my_n_sizes[2] >= 3) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
         else if (my_grow_day == 0) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
         else pq.emplace(INF - cost, t.size, flyness, cells[idx].richness, idx);
      }
      else if (my_grow_day == 0) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
      else if (s.my_n_sizes[3] == 0) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
      else if (s.my_n_sizes[3] < s.enemy_n_sizes[3]) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
      else if (s.my_n_sizes[2] >= 3) pq.emplace(t.size, INF - cost, flyness, cells[idx].richness, idx);
      else pq.emplace(INF - cost, t.size, flyness, cells[idx].richness, idx);
   }
   if (not pq.empty()) return Action(ActionType::Grow, get<4>(pq.top())).str();
   return "WAIT";
}

string best_complete(const State& s) {
   // いい刈り方とはなんですか？
   //   1. 影に当たりやすいか（当たりやすいものは優先度が高い)）
   //   2. richness が高い順？
   constexpr int cost = 4;
   if (s.me.sun < cost) return "WAIT";
   priority_queue<tuple<int, int, int>> pq;
   for (auto&& t : s.my_trees) {
      if (t.is_dormant) continue;
      if (t.size < 3) continue;

      int shadow = s.shadows[t.cell_index];
      pq.emplace(shadow, cells[t.cell_index].richness, t.cell_index);
   }
   if (not pq.empty()) return Action(ActionType::Complete, get<2>(pq.top())).str();
   return "WAIT";
}

string rule_base(State s) {
   int day = s.day;
   eprint("[day]", day);
   string res;
   // 序盤はガチ人力
   // 多分確定でできる行動があるので、それをしようか
   if ( len(logtxt) <= 5 ) {
      if (len(logtxt) == 0) return "WAIT";
      if (len(logtxt) == 1) return best_grow(s);
      if (len(logtxt) == 2) return "WAIT";
      if (len(logtxt) == 3) return best_grow(s);
      if (len(logtxt) == 4) return best_seed(s);
      if (len(logtxt) == 5) return "WAIT";
      // 多分ここまでは確定っぽい
   }
   // 最後のターン
   else if (day == 23) {
      int cost = 4;
      int rich = 0;
      int idx = 0;
      for (auto& t : s.my_trees) if (t.size == 3) if (chmax(rich, cells[t.cell_index].richness)) idx = t.cell_index;
      int get_score = s.nutrients + 2*(rich - 1);
      int point = s.me.score + get_score + (s.me.sun - 4) / 3;
      if (point > s.me.score + s.me.sun / 3) {
         return Action(ActionType::Complete, idx).str();
      }
      else return "WAIT";
   }
   else if (24 - day > s.my_n_sizes[3]) {
      // 種は一日一回まで
      bool should_complete = [&]() {
         // 「有利」ですか？
         bool ad = [&]() {
            if (s.my_n_sizes[3] < s.enemy_n_sizes[3]) return false;
            if (s.my_n_sizes[1] + s.my_n_sizes[2] < s.my_n_sizes[1] < s.my_n_sizes[2]) return false;
            if (s.me.score + 20 < s.enemy.score) return false;
            if (n_my_completed == 0) return false;
            if (s.me.sun <= 9) return false;
            return true;
         }();

         if (n_my_completed == 0 and n_enemy_completed == 0 and s.me.sun >= 12 and s.my_n_sizes[3] >= 5 and s.my_n_sizes[3] - s.enemy_n_sizes[3] > 1) {
            return true;
         }
         else if (s.enemy.is_waiting) {
            // 相手が眠っているときがスキあり
            // 攻めろーー！！！！！！！
            if (s.my_n_sizes[3] >= 4 and s.me.sun >= 8 and s.my_n_sizes[3] >= 2) {
               return true;
            }
         }
         // 有利な状況なら 1 ターンに 1 つは刈っておく
         else if (my_complete_day == 0 and ad) {
            return true;
         }
         // あんまり木が多すぎたら刈る
         else if (s.my_n_sizes[3] >= 6) {
            return true;
         }
         // 相手が刈ってきたらこっちもなるべく n + 1 回刈る
         else if ((n_my_completed != 0 or n_enemy_completed != 0) and n_my_completed + 1 <= n_enemy_completed and s.my_n_sizes[3] >= 2) {
            return true;
         }
         return false;
      }();
      if (should_complete and best_complete(s) != "WAIT") {
         return best_complete(s);
      }
      // できれば GROW → SEED の流れがいいなぁ…
      // 多分こうなると、growできないんだったら、Seedっていうのにして良さそう。。。？
      else if (best_grow(s) != "WAIT") {
         return best_grow(s);
      }
      else if (my_seed_day == 0) return best_seed(s);
   }
   else {
      // 終盤
      auto res = best_complete(s);
      if (res != "WAIT") return res;
      res = best_grow(s);
      if (res != "WAIT") return res;
      res = best_seed(s);
      return res;
   }
   return "WAIT";
}



// struct Node {
//    Node() = default;
//    Node(const State& s)
//       : state(s)
//       , n_wins(0)
//       , n_trials(0)
//    {}

//    int evalute() {
//       // ゲームが終了したら
//       if (state.day == 24) {
//          int my_score = state.me.score + state.me.sun / 3;
//          int enemy_score = state.enemy.score + state.enemy.sun / 3;
//          int value = my_score < enemy_score ? -1 : 0;
//          return value;
//       }
//       if (not children.empty()) {
//          int value = playout(state);

//          n_wins += value;
//          n_trials++;

//          // 謎のマジックナンバー
//          if (n_trials == 10) children = state.next_all();
         
//          return value;
//       }
//       else {
//          int value = -next_children().evalute();

//          n_wins += value;
//          n_trials++;

//          return value;
//       }
//    }

//    auto next_children() {
//       auto ucb1 = [&]() {
//          int sum = 0;
//          for (auto&& child : children) sum += child.n_trials;
//          vi ucb1(len(children));
//          rep (i, len(children)) {
//             ucb1[i] = -chi
//          }
//          return sum;
//       };

//    }

//    State state;
//    int n_wins;
//    int n_trials;
//    vec<Node> children;
// };

int playout(const State& s) {
   GameMaster gm(s);
   Action act, oppact;
   do {
      auto acts = gm.state.next_actions(true);
      act = acts[rnd.randint(len(acts))];
      auto oppacts = gm.state.next_actions(false);
      oppact = oppacts[rnd.randint(len(oppacts))];
   } while (gm.run(act, oppact));
   return gm.state.me.score + gm.state.me.sun / 3 > gm.state.enemy.score + gm.state.enemy.sun / 3;
}

string monte(const State& s) {
   auto [nexts, actions] = s.next_all();
   vi trials(len(nexts)), wins(len(nexts));
   priority_queue<pair<int, int>> pq;
   // UCB値, index でソート
   while (watch.ms() <= 94) {
      auto [ucb, idx] = pq.top(); pq.pop();
      int result = playout(nexts[idx]);
      trials[idx]++;
      wins[idx] += result == 1 ? 1 : 0;
      pq.emplace(wins[idx] / trials[idx], idx);
   }
   int max_idx = pq.top().se;
   return actions[max_idx].str();
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
      "Red Wisp Come On!!",
      "Blue Wisp Come On!!",
      "Trick or Treat!!",
      "Silent Step!!",
      "Eternity!!",
      "Heavy Haze!!",
      "Bats Storm!!",
   };

   int old_opp_size3 = 0;
   n_enemy_completed = 0;

   my_seed_day = 0;
   my_grow_day = 0;
   my_complete_day = 0;

   while (true) {
      State state;
      state.read();
      // state.info();

      // 行動ログを取っていく
      n_my_completed = count(all(logtxt), 'C');
      int now_opp_size3 = 0;
      for (auto& t : state.enemy_trees) if (t.size == 3) now_opp_size3++;
      if (old_opp_size3 > now_opp_size3) n_enemy_completed++;
      old_opp_size3 = now_opp_size3;

      // 日あたりの行動回数をカウント
      if (logtxt.back() == 'W') my_complete_day = my_grow_day = my_seed_day = 0;
      if (logtxt.back() == 'C') my_complete_day++;
      if (logtxt.back() == 'G') my_grow_day++;
      if (logtxt.back() == 'S') my_seed_day++;


      // 手を求める
      string ans = monte(state);
      if (ans == "") ans = "WAIT";

      // 行動リスト
      logtxt.pb(ans[0]);
      eprint("[森の様子]");
      eprint("[o] 自分の木の分布:", "[", state.my_n_sizes, " ]");
      eprint("[o] 相手の木の分布:", "[", state.enemy_n_sizes, " ]");

      string day_str = "[" + to_string(state.day) + " day]";
      string message = ans;
      if (turn <= 1) print(ans, greeting[turn]);
      else if (logtxt.back() == 'C') print(ans, compete_str[rnd.randint(len(compete_str))]);
      else print(ans, day_str, message);
      turn++;
   }
}