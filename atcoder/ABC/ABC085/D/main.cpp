# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int int_fast64_t
# define float __long_double
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

// ABC085-D
// ダークは…
// ブラウザは白なので、白のほうがいいだろ
// ばっかーんなるやつね
// 楽しい

/*
あなたが散歩していると、突然一体の魔物が出現しました。幸い、あなたは N 本の刀、刀 1、刀 2、…、刀 N を持っていて、次の二種類の攻撃を自由な順番で行うことができます。
・持っている刀のうち一本を振る。刀 i (1≤i≤N) を振ると、魔物は a_i ポイントのダメージを受ける。同じ刀を何度振ることもできる。
・持っている刀のうち一本を投げつける。刀 i (1≤i≤N) を投げつけると、魔物は b_i ポイントのダメージを受け、あなたはその刀を失う。すなわち、あなたは以後その刀を振ることも投げつけこともできなくなる。
魔物は、受けたダメージの合計が H ポイント以上になると消滅します。魔物を消滅させるには、最小で合計何回の攻撃が必要でしょうか。

[考察]
・振るなら振り続けるべき
・そうでなければ、投げるべき

max(a) よりも大きい b_i があれば投げる
・ただ、「任意の b_i が max(a) より大きい　かつ　投げるだけじゃ削りきれないとき」は？
・結局、最後の一撃は投げるべき
そうでなければ、切る
O(N log(N)) で解けました

*/

constexpr int ceil(int a, int b) { return (a + b - 1) / b; }

int32_t main() {
   int N, H ;
   cin >> N >> H;
   int max_a = -INF;
   priority_queue<int> pq;
   rep (i, N) {
      int a, b;
      cin >> a >> b;
      chmax(max_a, a );
      pq.push(b);
   }

   int ans = 0;

   // まずは投げたほうがいい
   while (not pq.empty() and H > 0) {
      int b = pq.top();
      pq.pop();
      H = max(H - max(max_a, b), int(0));
      ans++;
   }

   // もし削りきれないなら、最効率の剣で殴る
   ans += ceil(H, max_a);

   print(ans);
}