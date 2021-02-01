# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define fi first
# define se second
# define mkp make_pair
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define lb(v,x) distance(std::begin(v), lower_bound(all(v), (x)))
# define ub(v,x) distance(std::begin(v), upper_bound(all(v), (x)))
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using mii = map<int, int>;
using mci = map<char, int>;
using msi = map<string, int>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
constexpr float PI = 3.1415926535897932385;
constexpr int Flag(int n) { return 1LL << n; }
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; drop(args...);}
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
template<class It> constexpr bool same(It f, It e) { while (f != e) if (*f != *(--e)) return false; return true; }
constexpr int ctoi(const char c) { return ('0' <= c and c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }
# endif  // ngng628_library

struct Edge {
   Edge() = default;
   Edge(int t, int w = 0) : to(t), weight(w) {}
   int to;
   int weight;
};
using Graph = vector<vector<Edge>>;

auto read() {
   int n, m, k, s;
   cin >> n >> m >> k >> s;
   int p, q;
   cin >> p >> q;
   vi c(k);
   cin >> c;
   for_each(all(c), [](int& x){ x--; });
   vi a(m), b(m);
   rep (i, m) { cin >> a[i] >> b[i]; a[i]--; b[i]--; }
   return make_tuple(n, m, k, s, p, q, c, a, b);
}

int32_t main() {
   auto [N, M, K, S, P, Q, C, A, B] = read();
   sort(all(C));
   Graph _graph(N);
   rep (i, M) {
      _graph[A[i]].eb(B[i], P);
      _graph[B[i]].eb(A[i], P);
   }

   vi X, Y, Z;
   // set<pii> visited;  // 訪問済みの辺か
   set<int> D;
   rep (i, K) {
      vi dist(N, -1);
      dist[C[i]] = 0;
      for (queue<int> que({C[i]}); not que.empty();) {
         int now = que.front(); que.pop();
         for (auto&& nxt : _graph[now]) {
            // if (contains(visited, mkp(now, nxt.to))) continue;
            if (dist[nxt.to] != -1) continue;
            // visited.emplace(now, nxt.to);
            dist[nxt.to] = dist[now] + 1;
            if (dist[nxt.to] <= S) {
               D.insert(nxt.to);
            }
            que.push(nxt.to);
         }
      }
   }

   Graph graph(N);
   rep (i, M) {
      if (B[i] == N-1) graph[A[i]].eb(B[i], 0);
      else if (binary_search(all(C), B[i])) graph[A[i]].eb(B[i], INF);
      else if (contains(D, B[i])) graph[A[i]].eb(B[i], Q);
      else graph[A[i]].eb(B[i], P);

      if (A[i] == N-1) graph[B[i]].eb(A[i], 0);
      if (binary_search(all(C), A[i])) graph[B[i]].eb(A[i], INF);
      else if (contains(D, A[i])) graph[B[i]].eb(A[i], Q);
      else graph[B[i]].eb(A[i], P);
   }

   vi dist(N, INF);
   priority_queue<pii, vpii, greater<pii>> pq; // {dist, to}
   dist[0] = 0;
   pq.emplace(dist[0], 0);
   while (not pq.empty()) {
      auto [d, now] = pq.top(); pq.pop();
      if (dist[now] < d) continue;
      for (auto& edge : graph[now]) {
          if (dist[edge.to] > dist[now] + edge.weight) {
              dist[edge.to] = dist[now] + edge.weight;
              pq.emplace(dist[edge.to], edge.to);
          }
      }
   }

   print(dist[N-1]);
}
