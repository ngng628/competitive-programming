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
int ctoi(char c){ return isdigit(c) ? c - '0' : -1; }
# endif  // ngng628_library

template <class T>
struct StaticRangeSum {
   StaticRangeSum() = default;
   explicit StaticRangeSum(const vec<T>& seq) {
      const int n = len(seq);
      sums.resize(n + 1);
      sums[0] = 0;
      partial_sum(all(seq), begin(sums) + 1);
   }

   // 0-index [l, r)
   T get(int l, int r) const {
      if (r < 0) return 0ll;
      return sums[r] - sums[l];
   }

   // 0-index
   int lower_bound(T val) const {
      return distance(cbegin(sums) + 1, lower_bound(cbegin(sums) + 1, sums.cend(), val));
   }

   // 0-index
   int upper_bound(T val) const {
      return distance(cbegin(sums) + 1, upper_bound(cbegin(sums) + 1, sums.cend(), val));
   }

   T operator ()(int l, int r) const { return get(l, r); }

   vec<T> sums;
};

int32_t main() {
   string _x;
   cin >> _x;
   vi x(len(_x));
   transform(all(_x), x.begin(), ctoi);
   const int n = len(x);

   deque<int> ans;
   StaticRangeSum<int> cumsum(x);
   int carry = 0;
   for (int i = n; i > 0 or carry; --i) {
      carry += cumsum(0, i);
      ans.push_front(carry % 10);
      carry /= 10;
   }

   for (auto a : ans) cout << a;
   cout << '\n';
}
