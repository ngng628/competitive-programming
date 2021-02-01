# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int long long
# define float long double
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ cout << p.fi << " " << p.se; return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
# endif  // ngng628_library

struct Setup_io {
   Setup_io() {
       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
       cout << fixed << setprecision(3);
   }
} setup_io;

class UnionFind {
   public:
      UnionFind() : _n(0) {}
      UnionFind(int n) : _n(n), parent_or_size(n, -1) {}
      int merge(int a, int b) {
         assert(0 <= a && a < _n);
         assert(0 <= b && b < _n);
         int x = leader(a), y = leader(b);
         if (x == y) return x;
         if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
         parent_or_size[x] += parent_or_size[y];
         parent_or_size[y] = x;
         return x;
      }
      bool same(int a, int b) {
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
      std::vector<int> parent_or_size;
};

struct Ball {
   float x, y, z;
   float r;
   Ball(float _x, float _y, float _z, float _r) : x(_x), y(_y), z(_z), r(_r) {}
   float distanceFrom(const Ball& other) {
      return hypot(abs(this->x - other.x), abs(this->y - other.y), abs(this->z - other.z));
   }
};

struct Edge {
   int from;
   int to;
   float weight;
   Edge(int f, int t, float w) : from(f), to(t), weight(w) {}
};
bool operator <(const Edge &iValue, const Edge &other) { return iValue.weight < other.weight; }

struct Kruskal {
   UnionFind uf;
   float sum;
   vector<Edge> edges;
   int V;
   Kruskal(const vector<Edge>& _edges, int _V) : edges(_edges), V(_V) { init(); }
   void init() {
      sort(all(edges));
      uf = UnionFind(V);
      sum = 0.0;
      for (auto& e : edges) {
         if (!uf.same(e.from, e.to)) {
            uf.merge(e.from, e.to);
            sum += e.weight;
         }
      }
   }
};

void Main(int n, vector<Ball> balls) {
   if (n == 1) {
      print(0.0);
      return;
   }

   vector<Edge> edges;
   rep (i, n) {
      rep (k, n) {
         if (i == k) continue;
         float sr = balls[i].r + balls[k].r;
         float dist = balls[i].distanceFrom(balls[k]);
         float w = max((float)0.0, dist - sr);
         edges.eb(i, k, w);
      }
   }

   Kruskal krs(edges, n);
   print(krs.sum);
}

int32_t main() {
   while (true) {
      int n;
      cin >> n;
      if (!n) break;
      vector<Ball> balls;
      rep (i, n) {
         float x, y, z, r;
         cin >> x >> y >> z >> r;
         balls.eb(x, y, z, r);
      }
      Main(n, balls);
   }
}
