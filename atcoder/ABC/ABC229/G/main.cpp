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
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

template <class T, class F>
T binary_chop(T ac, T wa, const F& f) {
   while (abs(ac - wa) > 1) {
      T wj = (ac + wa) >> 1;
      (f(wj) ? ac : wa) = wj;
   }
   return ac;
}

int32_t main() {
   string s;
   cin >> s;
   const int n = len(s);
   int K;
   cin >> K;

   // Y の場所を Ai で管理する
   // Ai を座標圧縮したた結果は range(0, len(Ai))
   // すると、Ai - i = 座標圧縮後の座標と圧縮前の座標の差
   // つまり、（隙間なく）連続させるには左に何個詰めればいいですか？が分かる
   // そこで、B = Ai - i と定義する。
   // すると、|Bi - Bj| = Ai と Aj は何個詰めれば連続しますか？と解釈できる
   // 結局 B を適当に足し引きして、同じ整数をいっぱい作ってください、という問題に落とし込める
   // （ただし、足し引きできるのは合計 K まで）
   vi a;
   rep (i, n) if (s[i] == 'Y') a.push_back(i);
   const int m = len(a);
   vi b = a;
   rep (i, m) b[i] -= i;

   // 決め打ち二分探索で判定問題に落とす
   // 「同じ整数を m 個作ることはできますか？」
   // 決め打ち二分探索しているので、各判定問題が O(n) で解ければ十分高速
   // これを解くために、B の連続する L 個の整数をすべて同じにするには何回足し引きする必要がありますか？
   // を考えたくなる
   // x に値を揃えるとすると、各 Bi を x にするコストは |Bi - x|
   // i から始めて、連続する L 個の整数を x に揃える。どの x に揃えれば、
   // コストを最小化できるだろう？そのときのコストは？
   //  Σ_{k = iからi+L-1まで} |Bk - x|
   // これは有名なやつで、x は B の中央値である。（よく出るね）
   // 今回はコストを求めないといけないけど、毎回Σのforやってると間に合わない
   // k の前半は負、後半は正であることを利用すると O(1) で計算できる

   int ans = binary_chop(int(0), oo, [&](int L) {
      if (L >= m) return false;
      // 中身が O(n) であればいい
      int sum = 0;
      rep (i, L / 2) sum -= b[i];
      rep (i, L - L / 2, L) sum += b[i];

      int ans = sum;
      rep (i, L, m) {
         sum += b[i];
         sum -= b[i - L / 2];
         sum += b[i - L];
         sum -= b[i - L + L / 2];
         chmin(ans, sum);
      }

      return ans <= K;
   });

   cout << ans << endl;
}