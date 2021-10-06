# include <bits/stdc++.h>
# ifndef ngng628_library
# define ngng628_library
# define int Int
# define float Float
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=(int)(n)-1; i>=0; --i)
# define rreps(i,n) for(int i=(n); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
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
constexpr int INF = (1LL<<62)-(1LL<<31);
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
void drop(){ cout << '\n'; exit(0); }
template<class T, class... A> void drop(const T& v, const A&...args){ cout << v; if (sizeof...(args)) cout << ' '; drop(args...); }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
# endif  // ngng628_library

template<class T=int>
class median {
    multiset<T> left;
    multiset<T> right;

public:
    //左寄りと右寄りの中央値を返す
    //要素数が奇数の場合は同じ値を返す
    pair<T, T> mid() {
        if (left.size() == right.size()) {
            return make_pair(*left.rbegin(), *right.begin());
        } else {
            return make_pair(*right.begin(), *right.begin());
        }
    }
 
    void normalize_move_l() {
        if (left.size() + 1 < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
 
    void normalize_move_r() {
        if (left.size() > right.size()) {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        }
    }
 
    auto operator+=(const T &elem) {
        if (right.size() == 0 || *right.begin() <= elem) {
            right.insert(elem);
            normalize_move_l();
        } else {
            left.insert(elem);
            normalize_move_r();
        }
    }
 
    auto operator-=(const T &elem) {
        erase(elem);
    }
 
    void erase(const T &elem) {
        if (left.size() && elem <= *left.rbegin()) {
            left.erase(left.find(elem));
            normalize_move_l();
        } else {
            right.erase(right.find(elem));
            normalize_move_r();
        }
    }
 
};

int32_t main() {
   int n;
   cin >> n;
   vi a(n);
   cin >> a;
   vvi graph(n);
   rep (_, n - 1) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       graph[u].pb(v);
       graph[v].pb(u);
   }
}