# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define fi first
# define se second
# define overload3(_1,_2,_3,name,...) name
# define _step(n) _rep(_,n)
# define _rep(i,n) _repr(i,0,n)
# define _repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define rep(...) overload3(__VA_ARGS__, _repr, _rep, _step)(__VA_ARGS__)
# define _reps(i,n) _reprs(i,1,n)
# define _reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define reps(...) overload3(__VA_ARGS__, _reprs, _reps)(__VA_ARGS__)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)std::size(x)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using namespace chrono;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T> using vec = vector<T>;
using vi = vec<int>;
using vvi = vec<vi>;
using vll = vec<ll>;
using vvll = vec<vll>;
constexpr int oo = (1<<30)-(1<<15);
constexpr ll OO = (1LL<<62)-(1LL<<31);
constexpr ld EPS = 1e-10;
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
struct Setup_io { Setup_io() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); } } setup_io;

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
      return w % (b - a) + a;
   }

private:
   uint64_t x, y, z, w;
} rnd;

string table(const vvi& a, int val = 0) {
   stringstream ss;
   const int h = len(a), w = len(a[0]);
   vi perm(w);
   iota(all(perm), val);
   vi column_width(w);
   rep (j, w) {
      int mx = len(to_string(j));
      rep (i, h) chmax(mx, len(to_string(a[i][j])));
      column_width[j] = mx;
   }

   rep (i, len(to_string(h))) ss << ' ';
   rep (i, w) ss << "  " << setw(column_width[i]) << perm[i];
   ss << '\n';
   rep (i, h) {
      ss << setw(len(to_string(h))) << i + val;
      rep (j, w) ss << "  " << setw(column_width[j]) << a[i][j];
      if (i != h - 1) ss << '\n';
   }
   return ss.str();
}

string table(const vi& a, int val = 0) {
   vvi b = {a};
   return table(b, val);
}
# endif  // ngng628_library

// 制約
namespace Constraints {
   // タスクの数
   constexpr int N_MIN = 1000;
   constexpr int N_MAX = 1000;

   // 人間の数
   constexpr int M_MIN = 20;
   constexpr int M_MAX = 20;

   // 技能の種類数
   constexpr int K_MIN = 10;
   constexpr int K_MAX = 20;

   // 依存関係の数
   constexpr int R_MIN = 1000;
   constexpr int R_MAX = 3000;

   // TL
   constexpr int TIME_LIMIT_ms = 3000;
};

int N, M, K, R;
vvi d;
vi u, v;

int main() {
   cin >> N >> M >> K >> R;
   d.resize(N, vi(K));
   cin >> d;
   u.resize(R), v.resize(R);
   rep (i, R) cin >> u[i] >> v[i], u[i]--, v[i]--;

   vvi graph(N);
   rep (i, R) {
      assert(v[i] < N);
      assert(u[i] < N);
      graph[v[i]].pb(u[i]);
   }

   // スキルの推定値
   vvi s_pred(M, vi(K, 0));

   // タスクの状態
   enum class TaskStatus {
      None,
      Ready,     // いつでも取りかかれる
      Progress,  // 進行中
      Wait,      // 依存関係の解決待ち
      Complete,  // 完了
   };
   vec<TaskStatus> task_status(N, TaskStatus::None);
   auto update_task_status = [&task_status, graph]() {
      rep (i, N) {
         auto completed = [&](int i){ return task_status[i] == TaskStatus::Complete; };
         if (completed(i)) continue;
         else if (task_status[i] == TaskStatus::Progress) continue;
         else if (graph[i].empty()) task_status[i] = TaskStatus::Ready;
         else if (all_of(all(graph[i]), completed)) task_status[i] = TaskStatus::Ready;
         else task_status[i] = TaskStatus::Wait;
      }
   };
   update_task_status();

   // 人間の状態
   enum class WorkerStatus {
      None,
      Ready,   // いつでも取りかかれる
      Working, // 仕事中
   };
   vec<WorkerStatus> worker_status(M, WorkerStatus::Ready);
   
   // task_manager[i] := 人間 i が始めた (タスク, 時間)
   vec<pair<int, int>> task_manager(M, {-1, -1});

   // 仕事をしたことがある人間の集合
   set<int> worked_worker;

   bool all_exp = false;
   int exp_day = -1;

   reps (day, 2000) {
      // cerr << "[day] " << day << endl;
      // 手がつけられる仕事
      vi available_task;
      rep (i, N) {
         if (task_status[i] == TaskStatus::Ready) {
            available_task.pb(i);
         }
      }

      // 手が空いている人
      vi available_worker;
      rep (i, M) {
         if (worker_status[i] == WorkerStatus::Ready) {
            available_worker.pb(i);
         }
      }
      // 仕事を割り当てる
      vec<pair<int, int>> ab;
      auto register_task = [&](int worker, int task) {
         worker_status[worker] = WorkerStatus::Working;
         task_status[task]= TaskStatus::Progress;
         task_manager[worker] = {task, day};
         worked_worker.insert(worker);
         ab.emplace_back(worker + 1, task + 1);
      };
      if (len(worked_worker) < M) {
         // 一番仕事を早く終わらせそうな人に割り当てる
         int j = 0;
         std::mt19937 engine(0);
         shuffle(all(available_task), engine);
         for (int worker : available_worker) {
            if (j >= len(available_task)) break;
            if (task_manager[worker] != make_pair(-1, -1)) continue;
            int task = available_task[j];
            register_task(worker, task);
            j++;
         }
      }
      else {
         if (not all_exp) {
            exp_day = day - 1;
            all_exp = true;
         }

         for (int task : available_task) {
            if (task_status[task] == TaskStatus::Progress) continue;
            priority_queue<tuple<ll, int, int>> heap; // {重み, 依存関係の多さ, どのタスク}
            for (int worker : available_worker) {
               if (worker_status[worker] == WorkerStatus::Working) continue;
               // worker と task の距離を見る
               int weight = 0;
               int sum_skill_lv = 0;
               rep (k, K) {
                  weight += d[task][k] - s_pred[worker][k];
                  sum_skill_lv += s_pred[worker][k];
               }
               heap.emplace(len(graph[task]), sum_skill_lv * weight, worker);
            }

            if (not heap.empty()) {
               auto [_0, _2, worker] = heap.top();
               register_task(worker, task);
            }
         }
      }

      // 出力
      cout << len(ab);
      cout.flush();
      for (auto e : ab) {
         cout << ' ' << e;
         cout.flush();
      }
      cout << '\n';
      cout.flush();

      // 更新情報の取得
      int n;
      cin >> n;
      if (n == -1) break;
      rep (n) {
         int f;
         cin >> f;
         f--;
         worker_status[f] = WorkerStatus::Ready;

         auto [task, weight] = task_manager[f];
         task_status[task] = TaskStatus::Complete;

         // s_pred[f][k] = 人 f の k 番目のスキル
         int t = day - weight;
         auto di = d[task];
         int mx = *max_element(all(di));
         rep (k, K) {
            int sgn = rnd.randint(2) == 0 ? 1 : -1;
            if (s_pred[f][k] == 0) {
               s_pred[f][k] += di[k] + sgn*(t / K);
            }
            else {
               if (mx == di[k]) {
                  s_pred[f][k] = (s_pred[f][k] + 3*(di[k] + sgn*t / K)) / 4;
               }
               else {
                  s_pred[f][k] = (3*s_pred[f][k] + di[k] + sgn*t / K) / 4;
               }
            }
         }
      }
      auto backup = task_status;
      rep (2) {
         rep (i, N) {
            auto completed = [&](int i){ return backup[i] == TaskStatus::Complete; };
            if (completed(i)) continue;
            else if (backup[i] == TaskStatus::Progress) continue;
            else if (graph[i].empty()) task_status[i] = TaskStatus::Ready;
            else if (all_of(all(graph[i]), completed)) task_status[i] = TaskStatus::Ready;
            else task_status[i] = TaskStatus::Wait;
         }
      }

      // 技能レベルの予測値を出力
      rep (i, M) {
         cout << "#s " << i + 1;
         rep (j, K) cout << " " << s_pred[i][j];
         cout << endl;
      }
   }

   cerr << "=================================================================" << endl;
   cerr << "                     表 1. 推定のスキル" << endl;
   cerr << "-----------------------------------------------------------------" << endl;
   cerr << table(s_pred) << endl;
   cerr << "=================================================================" << endl;
}
