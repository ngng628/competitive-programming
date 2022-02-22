# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
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
# define all(v) std::begin(v), std::end(v)
# define rall(v) std::rbegin(v), std::rend(v)
# define pb push_back
# define eb emplace_back
# define len(v) (int)std::size(v)
# define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
using Int = long long;
using Float = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

class UnionFind {
public:
   UnionFind() : _n(0) {}
   UnionFind(int n) : _n(n), parent_or_size(n, -1) {}

   int unite(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      int x = leader(a), y = leader(b);
      if (x == y) return x;
      if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
      parent_or_size[x] += parent_or_size[y];
      parent_or_size[y] = x;
      return x;
   }

   bool equiv(int a, int b) {
      assert(0 <= a && a < _n);
      assert(0 <= b && b < _n);
      return leader(a) == leader(b);
   }

   int leader(int a) {
      assert(0 <= a && a < _n);
      if (parent_or_size[a] < 0) return a;
      return parent_or_size[a] = leader(parent_or_size[a]);
   }

   int size(int a) {
      assert(0 <= a && a < _n);
      return -parent_or_size[leader(a)];
   }

   vvi groups() {
      vi leader_buf(_n), group_size(_n);
      rep (i, _n) {
         leader_buf[i] = leader(i);
         group_size[leader_buf[i]]++;
      }
      vvi result(_n);
      rep (i, _n) result[i].reserve(group_size[i]);
      rep (i, _n) result[leader_buf[i]].pb(i);
      result.erase(
            remove_if(all(result), [&](const vi& v) { return v.empty(); }), result.end());
      return result;
   }

private:
   int _n;

   // root node: -1 * component size
   // otherwise: parent
   vi parent_or_size;
};

struct MinimumSpanningTree {
   struct Edge {
      Edge() = default;
      Edge(int _u, int _v, int w) : u(_u), v(_v), weight(w) {}
      int u;
      int v;
      int weight;
      friend bool operator <(const Edge& a, const Edge& b) { return a.weight < b.weight; }
   };

   MinimumSpanningTree() = default;
   MinimumSpanningTree(int _v) : v(_v) {}
   MinimumSpanningTree(int _v, const vec<Edge>& _edges) : v(_v), edges(_edges) { compile(); }

   void add_edge(int u, int v, int w) {
      edges.eb(u, v, w);
   }

   void add_edge(const Edge& edge) {
      add_edge(edge.u, edge.v, edge.weight);
   }

   void compile() {
      sum = 0;
      graph.assign(v, vi());

      sort(all(edges));
      UnionFind ut(v);
      for (auto& [u, v, w] : edges) {
         if (!ut.equiv(u, v)) {
            ut.unite(u, v);
            sum += w;
         }
      }
   }

   int v;
   int sum;
   vvi graph;

private:
   vec<Edge> edges;
};

struct Monoid {
   int val;
   static Monoid e() { return Monoid{ 0 }; }
};
Monoid operator *(const Monoid& a, const Monoid& b) { return Monoid{ max(a.val, b.val) }; }

// template <class Monoid>
struct LCA {
   struct Data {
      int idx;
      Monoid val;
   };
   using Data = pair<int, Monoid>;

   vec<vec<Data>> tree;
   LCA(const vvi& graph, int root = 0)
      : n_vertices(len(graph))
      , n_leaves(63 - __builtin_clzll(len(graph)) + 1)
   {
   }

   void add_edge(int u, int v, Monoid w) {
      tree[u][0] = Data{ v, w };
   }

   void compile() {
      tree.assign(n_vertices, vec<Data>(n_leaves, Data{ -1, Monoid::e() }));

      rep (k, n_leaves - 1) {
         rep (i, n_vertices) {
            int pre = tree[i][k].idx;
            if (pre == -1) tree[i][k + 1] = tree[i][k];
            else tree[i][k + 1] = { tree[i][k].idx, tree[i][k].val * tree[pre][k].val };
         }
      }
   }

   Data query(int i, int t) const {
      Monoid res = Monoid::e();
      rrep (k, n_leaves) {
         if ((t >> k) & 1) {
            res = res * tree[i][k].val;
            i = tree[i][k].idx;
         }
         if (i == -1) break;
      }
      return { i, res };
   }

private:
   const int n_vertices;
   const int n_leaves;
};

int32_t main() {
   // int n, m, Q;
   // cin >> n >> m >> Q;
   // MinimumSpanningTree mst;
   // rep (m) {
   //    int a, b, c;
   //    cin >> a >> b >> c;
   //    a--, b--;
   //    mst.add_edge(a, b, c);
   // }

   int n;
   cin >> n;
   vvi graph(n);
   rep (i, n) {
      int k;
      cin >> k;
      rep (k) {
         int c;
         cin >> c;
         c--;
         graph[i].push_back(c);
         graph[c].push_back(i);
      }
   }
}