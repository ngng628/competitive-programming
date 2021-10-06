# include <bits/stdc++.h>
# include <atcoder/lazysegtree>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
# define fi first
# define se second
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) (int)(x).size()
using namespace std;
using __long_double = long double;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using db = deque<bool>;
using ddb = deque<db>;
using vs = vec<string>;
constexpr int INF = (1LL<<62)-(1LL<<31);
constexpr float EPS = 1e-10;
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, std::size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.fi >> p.se; }
template<class T> string join(const vec<T> &v){ stringstream s; rep (i, len(v)) s << ' ' << v[i]; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.fi << " " << p.se; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << " "; print(args...); }
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){ cerr << v; if (sizeof...(args)) cerr << " "; eprint(args...); }
void drop(){ cout << "\n"; exit(0); }
template<class T, class... A>void drop(const T& v, const A&...args){ cout << v; if(sizeof...(args))cout << " "; drop(args...); }
template<class T> constexpr bool chmax(T &a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T &a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(const char c){ return '0' <= c and c <= '9' ? (c - '0') : -1; }
# endif  // ngng628_library

using S = long long;
using F = long long;
const S INFTY = 8e18;
const F ID = 8e18;
S op(S a, S b){ return std::max(a, b); }
S e(){ return -INFTY; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

/* BIT: RAQ対応BIT
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    int n;             // 要素数
    vector<T> bit[2];  // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(int p, int i, T x) {
         for (int idx = i; idx < n; idx += (idx & -idx)) {
               bit[p][idx] += x;
         }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
         l += 1;
         r += 1;
         add_sub(0, l, -x * (l - 1));
         add_sub(0, r, x * (r - 1));
         add_sub(1, l, x);
         add_sub(1, r, -x);
    }
    T sum_sub(int p, int i) {
         T s(0);
         for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
         }
         return s;
    }
    T sum(int i) { return sum_sub(0, i + 1) + sum_sub(1, i + 1) * (i + 1); }
};

int32_t main() {
   int n;
   cin >> n;
   atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> has_info_seg(n);
   has_info_seg.apply(0, n, 1);
   BIT<int> sum_seg(n + 1);
   // sum_seg.apply(0, n, 0);

   int q;
   cin >> q;
   while (q--) {
      int t, x, y, v;
      cin >> t >> x >> y >> v;
      x--, y--;

      auto query = [&sum_seg](int l, int r) {
         return sum_seg.sum(r - 1) - sum_seg.sum(l - 1);
      };

      // 情報 : A_x + A_y = v が与えられる
      if (t == 0) {
         if (x & 1) sum_seg.add(x, x+1, -v);
         else sum_seg.add(x, x+1, v);
         has_info_seg.set(x, 0);
      }
      // 質問 : A_x = V のとき、A_y はいくつ？が与えられる
      else {
         int ans;
         if (x < y) {
            if (has_info_seg.prod(x, y) == 1) {
               print("Ambiguous");
               continue;
            }
            int sum;
            if (y & 1) sum = query(x, y);
            else sum = (-1)*query(x, y);
            if (abs(y - x) % 2) ans = sum - v;
            else ans = sum + v;
         }
         else {
            if (has_info_seg.prod(y, x) == 1) {
               print("Ambiguous");
               continue;
            }
            int sum;
            if (y & 1) sum = (-1)*query(y, x);
            else sum = query(y, x);
            if (abs(y - x) % 2) ans = sum - v;
            else ans = sum + v;
         }
         print(ans);
      }
   }
}