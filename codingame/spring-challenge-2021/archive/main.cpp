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

   string str() const {
      switch (type) {
         case ActionType::Grow: return "GROW " + to_string(index[0]);
         case ActionType::Seed: return "SEED " + to_string(index[0]) + " " + to_string(index[1]);
         case ActionType::Complete: return "COMPLETE " + to_string(index[0]);
         case ActionType::Wait: return "WAIT";
         default: return "WAIT";
      }
   }

   ActionType type;
   array<int, 2> index;
   friend ostream& operator <<(ostream& os, const Action& a){ return os << a.str(); }
};

int n_cells;
vec<Cell> cells;
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
      for (auto&& action : possible_actions) {
         State cp = *this;
         if (action.type == ActionType::Grow) {
            int idx = action.index[0];
            int sz = trees[idx].size;
            int cost = (sz + 1) + (my_n_sizes[sz + 1]);

            cp.me.sun -= cost;
            cp.my_n_sizes[sz]--, cp.my_n_sizes[sz+1]++;
            cp.trees[idx].size++;
         }
         else if (action.type == ActionType::Seed) {
            int cost = cp.my_n_sizes[0];
            cp.me.sun -= cost;
            cp.my_n_sizes[0]++;
            cp.trees[action.index[1]].size = 1;
            cp.trees[action.index[1]].is_mine = true;
            cp.trees[action.index[1]].cell_index = action.index[1];
         }
         else if (action.type == ActionType::Complete) {
            int idx = action.index[0];
            int cost = 4;
            cp.me.sun -= cost;
            cp.me.score += 2*(cp.trees[idx].size - 1);
            cp.my_n_sizes[3]--;
            cp.trees[idx] = Tree();
            cp.nutrients--;
         }
         else {  // Wait

         }
         res.eb(cp, action);
      }
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
   vec<Tree> trees;
   int n_possible_actions;
   vec<Action> possible_actions;

   array<int, 4> my_n_sizes, enemy_n_sizes;
};

string greedy(State s) {
   ll max_score = 0;
   string max_action = "?";
   for (auto [state, action] : s.nexts()) {
      if (chmax(max_score, state.eval())) {
         max_action = action.str();
         eprint(__LINE__, max_action);
      }
   }
   if (max_score == 0) {
      if (s.n_possible_actions == 1) max_action = "WAIT";
      else max_action = s.possible_actions[1].str();
   }
   return max_action;
}

string rule_base(State s) {
   string res = "WAIT";
   int week = s.day / 7;
   int my_trees = accumulate(all(s.my_n_sizes), 0);
   eprint("day(week)", s.day,'(',week, ')');
   if (s.day <= 8) {
      if (s.my_n_sizes[0] <= 2 and my_trees <= 6 and s.my_n_sizes[0] - s.my_n_sizes[1] <= 0) {
         // できることなら種を蒔く
         vec<Action> couf;
         for (auto act : s.possible_actions) {
            if (act.type == ActionType::Seed) {
               couf.pb(act);
            }
         }
         rep (i, len(couf)) {
            // 土壌がいいところで育てよう
            auto act = couf[i];
            int idx = act.index[0];
            if (trees[idx].)
         }
         if (len(couf)) res = couf[rnd.randint(len(couf))].str();
      }
      else {
         for (auto act : s.possible_actions) {
            vec<Action> couf;
            if (act.type == ActionType::Grow) {
               couf.pb(act);
            }
            if (len(couf)) res = couf[rnd.randint(len(couf))].str();
         }
         if (res == "WAIT") {
            if (my_trees < 5) {
               for (auto act : s.possible_actions) {
                  if (act.type == ActionType::Seed) {
                     res = act.str();
                  }
               }
            }
         }
      }
   }
   else if (s.day <= 16) {
      for (auto act : s.possible_actions) {
         vec<Action> couf;
         if (act.type == ActionType::Grow) {
            couf.pb(act);
         }
         if (len(couf)) res = couf[rnd.randint(len(couf))].str();
      }
   }
   else if (s.day <= 20) {
      // できることなら刈る
      for (auto act : s.possible_actions) {
         if (act.type == ActionType::Complete) {
            int idx = act.index[0];
            if (s.trees[idx].size == 3) {
               res = act.str();
               break;
            }
            if (s.trees[idx].size == 1 and res != "") continue;
            res = act.str();
         }
      }
      // だめだったら育てる
      if (res == "WAIT") {
         eprint("だめだったら育てるよ");
         for (auto act : s.possible_actions) {
            if (act.type == ActionType::Grow) {
               res = act.str();
               break;
            }
         }
      }
   }
   else if (week <= 3) {
      // できることなら刈る
      for (auto act : s.possible_actions) {
         if (act.type == ActionType::Complete) {
            int idx = act.index[0];
            if (s.trees[idx].size == 3) {
               res = act.str();
               break;
            }
            if (s.trees[idx].size == 1 and res != "") continue;
            res = act.str();
         }
      }
   }
   return res;
}

int main() {
   cin >> n_cells; cin.ignore();
   cells.resize(n_cells);
   rep (i, n_cells) {
      Cell c;
      cin >> c; cin.ignore();
      cells[c.index] = c;
   }

   while (true) {
      State state;
      state.read();
      // state.info();
      rep (i, state.n_possible_actions) {
         eprint("[o]", state.possible_actions[i]);
      }
      string ans = rule_base(state);
      eprint("行動:", ans);
      print(ans, ans);
   }
}
