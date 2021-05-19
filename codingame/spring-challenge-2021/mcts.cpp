// 多分一番ばぐは少ない
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
   Tree() : cell_index(-1), size(-1), is_mine(false), is_dormant(false) {}
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
      rep (i, n_cells) trees[i].cell_index = i;

      cin >> n_possible_actions; cin.ignore();
      possible_actions.resize(n_possible_actions);
      rep (i, n_possible_actions) {
         string s;
         getline(cin, s);
         possible_actions[i] = Action(s);
      }

      rep (i, 4) my_n_sizes[i] = enemy_n_sizes[i] = 0;
      rep (i, n_cells) {
         if (trees[n_cells].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
         if (not trees[i].is_mine) if (trees[i].size != 1) my_n_sizes[trees[i].size]++;
      }
   }
   void info() const {
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

   ll eval() const {
      return 0ll;
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
         if (trees[n_cells].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
         if (not trees[i].is_mine) if (trees[i].size != 1) my_n_sizes[trees[i].size]++;
      }
   }

   int day;
   int nutrients;
   Spirit me, enemy;
   int n_trees;
   vec<Tree> trees, my_trees, enemy_trees, both_trees;
   int n_possible_actions;
   vec<Action> possible_actions;

   array<int, 4> my_n_sizes, enemy_n_sizes;

   friend bool operator <(const State& a, const State& b) {
      int day = a.day;
      // 序盤？
      if (day <= 6) {
         int a_me = a.me.score + 3*a.me.sun;
         int a_en = a.enemy.score + 3*a.enemy.sun;
         int a_val = a_me - a_en;

         int b_me = b.me.score + 3*b.me.sun;
         int b_en = b.enemy.score + 3*b.enemy.sun;
         int b_val = b_me - b_en;

         return a_val < b_val;
      }
      // 終盤
      else if (day <= 18) {
         int a_me = 2*a.me.score + a.me.sun;
         int a_en = 2*a.enemy.score + a.enemy.sun;
         int a_val = a_me - a_en;

         int b_me = 2*b.me.score + b.me.sun;
         int b_en = 2*b.enemy.score + b.enemy.sun;
         int b_val = b_me - b_en;

         return a_val < b_val;
      }
      // ド終盤
      else {
         int a_me = a.me.score + a.me.sun / 3;
         int a_en = a.enemy.score + a.enemy.sun / 3;
         int a_val = a_me - a_en;

         int b_me = b.me.score + b.me.sun / 3;
         int b_en = b.enemy.score + b.enemy.sun / 3;
         int b_val = b_me - b_en;

         return a_val < b_val;
      }
   }
};

struct GameMaster {
   GameMaster() = default;
   GameMaster(const State s) : state(init), init(s) {}
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
         deque<bool> shadows(n_cells, false);
         rep (i, n_cells) {
            int depth = state.trees[i].size;
            int idx = i;
            rep (_, depth) {
               idx = cells[idx].neigh[shadow_direction];
               if (idx == -1) break;
               shadows[idx] = true;
            }
         }

         // SUNポイントの授与
         for (Tree& t : state.trees) {
            if (t.is_mine and not shadows[t.cell_index]) state.me.sun += max(0, t.size);
            if (not t.is_mine and not shadows[t.cell_index]) state.enemy.sun += max(0, t.size);
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

string best_seed(const State& s) {
   if (s.my_n_sizes[0] >= 8) return "WAIT";
   // richness, 自分との最小距離, 相手との最小距離, 飛ばす木の大きさで評価
   priority_queue<tuple<int, int, int, int, int, int>> pq;
   rep (i, n_cells) {
      if (s.trees[i].size != -1 or cells[i].richness == 0) continue;
      int my_d = INF, en_d = INF;
      for (auto&& t : s.both_trees) {
         if (t.is_mine) chmin(my_d, dist[i][t.cell_index]);
         else chmin(en_d, dist[i][t.cell_index]);
      }
      // 本当に置けますか？
      for (auto&& p : s.my_trees) {
         if (dist[i][p.cell_index] <= p.size and not p.is_dormant and s.me.sun >= s.my_n_sizes[0]) {
            int richness = cells[i].richness == 3 ? 3 : 0;
            pq.emplace(my_d, richness, INF - en_d, 3 - p.size, p.cell_index, i);
         }
      }
   }
   if (not pq.empty()) return Action(ActionType::Seed, get<4>(pq.top()), get<5>(pq.top())).str();
   return "WAIT";
}

string best_grow(const State& s) {
   // 背が高いもの順に育てる
   priority_queue<tuple<int, int, int>> pq;
   for (auto&& t : s.my_trees) {
      if (t.is_dormant) continue;
      if (t.size == 3) continue;
      int cost = (t.size == 2 ? 7 : 2*t.size + 1) + s.my_n_sizes[t.size + 1];
      int idx = t.cell_index;
      if (s.me.sun >= cost) pq.emplace(t.size == 1 and s.day <= 15 ? 3 : t.size, cells[idx].richness, idx);
   }
   if (not pq.empty()) return Action(ActionType::Grow, get<2>(pq.top())).str();
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

string random_search(State& s) {
   constexpr int TIME_LIMIT = 92;

   vec<Action> sels = s.next_actions(true);
   eprint("pos:");
   for (auto a : sels) cerr << " " << a.str();
   return "WAIT";
   GameMaster master(s);
   pair<float, Action> ans;
   ans.fi = 0.0;
   int i = 1;
   for (auto act : sels) {
      int n_loop = 0;
      int n_win = 0;
      while (watch.ms() <= i*((float)TIME_LIMIT / len(sels))) {
         vec<Action> en_acts = s.next_actions(false);
         Action en_act = en_acts[rnd.randint(len(en_acts))];
         while (not master.run(act, en_act)) {
            vec<Action> acts = s.next_actions(true);
            act = acts[rnd.randint(len(acts))];
            vec<Action> en_acts = s.next_actions(false);
            en_act = en_acts[rnd.randint(len(en_acts))];
         }
         n_loop++;
         auto score = [](const Spirit& sp) { return sp.score + sp.sun / 3; };
         if (score(master.state.me) > score(master.state.enemy)) n_win++;

         if (n_loop > 100 and (float)n_win / n_loop < 0.01) break;
      }
      if (chmax(ans.fi, (float)n_win / n_loop)) {
         ans.se = act;
      }
      i++;
   }
   return ans.se.str();
}

string rule_base(State s) {
   int day = s.day;
   eprint("[day]", day);
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
   else if (len(s.my_trees) <= 6 and s.my_n_sizes[3] <= 3 and 24 - day > s.my_n_sizes[3]) {
      if (s.my_n_sizes[3] == 0) return best_grow(s);
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
      if ((cen >= (valcen - 2) and s.my_n_sizes[3] >= 6) or (logtxt.back() == 'C') or (s.my_n_sizes[3] >= 4 and s.me.score - s.enemy.score < -20)) {
         string res = "WAIT";
         if ((s.me.sun >= 20 or logtxt.back() == 'C' or s.me.score- s.enemy.score < -25) and s.my_n_sizes[3] >= 5) res = best_complete(s);
         if (res != "WAIT") return res;
         res = best_grow(s);
         if (res != "WAIT") return res;
         res = best_seed(s);
      }
      else {
         int less2 = s.my_n_sizes[0] + s.my_n_sizes[1] + s.my_n_sizes[2];
         if (less2 > s.my_n_sizes[3] or s.my_n_sizes[3] <= 6) {
            res = best_grow(s);
         }
         if (s.me.sun >= 20) return best_seed(s);
         if (res != "WAIT") return res;
         // if (len(s.my_trees) < 6 or len(s.my_trees) < len(s.enemy_trees)) res = best_seed(s);
         // if (res != "WAIT" and s.me.sun >= 10) res = best_grow(s);
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

   while (true) {
      State state;
      state.read();
      // state.info();
      string ans = random_search(state);
      if (ans == "") ans = "WAIT";
      if (ans == "WAIT" and state.me.sun >= 20) {
         ans = best_grow(state);
         if (ans == "WAIT") ans = best_seed(state);
      }

      string message = "[" + to_string(state.day) + " day] " + ans;
      logtxt.pb(ans[0]);
      eprint("[LOG]", logtxt);
      print(ans, message);
   }
}
