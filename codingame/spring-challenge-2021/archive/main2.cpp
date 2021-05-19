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
         if (trees[n_cells].size == -1) continue;
         if (trees[i].is_mine) my_n_sizes[trees[i].size]++;
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

   // Input for One Game Turn
   int day;
   int nutrients;
   Spirit me, enemy;
   int n_trees;
   vec<Tree> trees, my_trees, enemy_trees, both_trees;
   int n_possible_actions;
   vec<Action> possible_actions;

   array<int, 4> my_n_sizes, enemy_n_sizes;
};

string best_seed(const State& s) {
   priority_queue<tuple<int, int, int, int, int, int>> pq;
   rep (i, n_cells) {
      if (s.trees[i].size != -1) continue;
      if (cells[i].richness == 0) continue;
      int my_d = INF, en_d = INF;
      for (auto&& t : s.both_trees) {
         if (t.is_mine) chmin(my_d, dist[i][t.cell_index]);
         else chmin(en_d, dist[i][t.cell_index]);
      }
      // 本当に置けますか？
      for (auto&& t : s.my_trees) {
         if (dist[i][t.cell_index] <= t.size and not t.is_dormant and s.me.sun >= s.my_n_sizes[0]) {
            int richness = cells[i].richness == 3 ? 3 : 0;
            pq.emplace(richness, my_d, en_d, 3 - t.size, t.cell_index, i);
            eprint("[o]", richness, my_d, en_d, t.cell_index, i);
         }
      }
   }
   if (not pq.empty()) return Action(ActionType::Seed, get<4>(pq.top()), get<5>(pq.top())).str();
   return Action("WAIT").str();
}

string rule_base(State s) {
   int day = s.day;
   eprint("[day]", day);
   string res;
   // 序盤はガチ人力
   if (len(s.my_trees) == 2 and s.my_n_sizes[2] < 2) {
      // 2 本とも size 2 に進化させる
      for (auto&& tree : s.my_trees) {
         int cost = 1 + s.my_n_sizes[1];
         if (tree.size == 1 and s.me.sun >= cost and not tree.is_dormant) {
            return Action(ActionType::Grow, tree.cell_index).str();
         }
      }
   }
   else if (len(s.my_trees) <= 6 and s.my_n_sizes[3] <= 3) {
      // 十分な距離を取って種をまく
      return best_seed(s);
   }
   else if (24 - day > s.my_n_sizes[3]) {
      // 育てまくる
      if (s.my_n_sizes[0] + s.my_n_sizes[1] + s.my_n_sizes[2] > s.my_n_sizes[3] and s.my_n_sizes[3] <= 5) {
         // 背の高いもの優先で育てる
         priority_queue<tuple<int, int>> pq;
         for (auto&& t : s.my_trees) {
            if (t.is_dormant) continue;
            if (t.size == 3) continue;
            int cost = 2*(t.size + 1) + s.my_n_sizes[t.size + 1];
            if (s.me.sun >= cost) pq.emplace(t.size, t.cell_index);
         }
         if (not pq.empty()) return Action(ActionType::Grow, get<1>(pq.top())).str();
      }
      else {
         // 適当に背の高いものを刈る
         priority_queue<tuple<int, int>> pq;
         for (auto&& t : s.my_trees) {
            if (t.is_dormant) continue;
            if (t.size < 3) continue;
            constexpr int cost = 4;
            
            if (s.me.sun >= cost) pq.emplace(cells[t.cell_index].richness, t.cell_index);
         }
         if (not pq.empty()) return Action(ActionType::Complete, get<1>(pq.top())).str();
      }
      if (len(s.my_trees) < 8 or len(s.my_trees) < len(s.enemy_trees)) return best_seed(s);
   }
   else {
      // 適当に背の高いものを刈る
      for (auto&& t : s.my_trees) {
         if (t.is_dormant) continue;
         if (t.size < 3) continue;
         constexpr int cost = 4;
         if (s.me.sun >= cost) return Action(ActionType::Complete, t.cell_index).str();
      }
      // 背の高いもの優先で育てる
      priority_queue<tuple<int, int>> pq;
      for (auto&& t : s.my_trees) {
         if (t.is_dormant) continue;
         if (t.size == 3) continue;
         int cost = 2*(t.size + 1) + s.my_n_sizes[t.size + 1];
         if (s.me.sun >= cost) pq.emplace(t.size, t.cell_index);
      }
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
      string ans = rule_base(state);
      if (ans == "") ans = "WAIT";
      string message = "[" + to_string(state.day) + " day] " + ans;
      print(ans, message);
   }
}
