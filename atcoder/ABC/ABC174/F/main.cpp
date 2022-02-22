# include <atcoder/fenwicktree>
# ifndef ONLINE_JUDGE
# include <nglib/atcoder>
# endif
# ifdef ngng628_library

using DynamicRangeSum = atcoder::fenwick_tree<int>;

using range = pii;
# define LEFT first
# define RIGHT second

int32 main() {
    int n, Q;
    cin >> n >> Q;
    vi c(n);
    cin >> c;
    vec<range> lr(Q);
    cin >> lr;

    vec<range> st;
    vec<int> vis(n + 1, -1);
    rep (i, n) {
        if (vis[c[i]] == -1) {
            vis[c[i]] = i;
        }
        else {
            int l = vis[c[i]];
            int r = i;
            st.emplace_back(l, r);
            vis[c[i]] = i;
        }
    }

    constexpr bool is_query = true;
    vec<tuple<bool, range, int>> query;
    rep (i, Q) query.emplace_back(is_query, range(lr[i].LEFT - 1, lr[i].RIGHT - 1), i);
    for (auto [l, r] : st) query.emplace_back(not is_query, range(l, r), -1);
    sort(query, [](const auto& a, const auto& b) {
        int ta = get<0>(a), tb = get<0>(b);
        int la = get<1>(a).LEFT, lb = get<1>(b).LEFT;
        if (la == lb) return ta < tb;
        else return la > lb;
    });

    vi ans(Q);
    DynamicRangeSum cumsum(n + 1);
    for (auto [t, _lr, idx] : query) {
        auto [l, r] = _lr;
        if (t == is_query) {
            int length = r - l + 1;
            int dup = cumsum.sum(0, r + 1);
            ans[idx] = length - dup;
        }
        else {
            cumsum.add(r, 1);
        }
    }

    for (auto a : ans) cout << a << '\n';
}






# else

# include <bits/stdc++.h>
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
using int32 = int32_t;
using int64 = int64_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
using usize = size_t;
using ssize = ptrdiff_t;
template<class T> using vec = vector<T>;
using pii = pair<int, int>;
using vi = vec<int>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
using db = deque<bool>;
using ddb = deque<db>;
using dddb = deque<ddb>;
constexpr int oo = (1LL<<62)-(1LL<<31);
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<class T> istream& operator >>(istream& is, vec<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T, size_t N> istream& operator >>(istream& is, array<T, N>& v) { for (auto& x : v) is >> x; return is; }
template<class T> string join(const vec<T>& v){ stringstream s; for (T t : v) s << ' ' << t; return s.str().substr(1); }
template<class T> ostream& operator <<(ostream& os, const vec<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator <<(ostream& os, const vec<vec<T>>& v){ rep (i, len(v)) if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); return os; }
template<class T, class U> ostream& operator <<(ostream& os, const pair<T, U>& p){ return os << p.first << ' ' << p.second; }
template<class T, class U, class V> ostream& operator <<(ostream& os, const tuple<T, U, V>& t){ return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t); }
template<class T> T scan(){ T t; cin >> t; return t; }
template<class T> constexpr bool chmax(T& a, const T& b){ return a < b && (a = b, true); }
template<class T> constexpr bool chmin(T& a, const T& b){ return a > b && (a = b, true); }
constexpr int ctoi(char c){ return isdigit(c) ? c - '0' : -1; }
int ceil(const int n, const int d) { assert(d); return n / d + int((n ^ d) >= 0 && n % d != 0); }
template<class T> void sort(T& v){ sort(all(v)); }
template<class T, class Compare> void sort(T& v, Compare comp){ sort(all(v), comp); }
template<class T> void rsort(T& v){ sort(all(v), greater<>()); }
template<class T, class Compare> void rsort(T& v, Compare comp){ sort(rall(v), comp); }
template<class T> void reverse(T& v){ reverse(all(v)); }
template<class T> void unique(T& v){ sort(v); v.erase(unique(all(v)), std::end(v)); }
template <class T = int, class S> T accumulate(const S& v, T init = 0) { return accumulate(std::cbegin(v), std::cend(v), init); }
template <class T = int, class S, class Operation> T accumulate(const S& v, T init, Operation op) { return accumulate(std::cbegin(v), std::cend(v), init, op); }
template <class T = int, class S> auto count(const S& v, T target) { return count(std::cbegin(v), std::cend(v), target); }
template <class T, class Compare> auto count_if(const T& v, Compare comp) { return count_if(std::cbegin(v), std::cend(v), comp); }
template<class T> auto max(T& v){ return *max_element(std::cbegin(v), std::cend(v)); }
template<class T> auto min(T& v){ return *min_element(std::cbegin(v), std::cend(v)); }
template<class T = int, class S> auto lower_bound(const S& v, T x){ return lower_bound(std::cbegin(v), std::cend(v), x); }
template<class T = int, class S> auto upper_bound(const S& v, T x){ return upper_bound(std::cbegin(v), std::cend(v), x); }
template<class T> auto next_permutation(T& v){ return next_permutation(all(v)); }
vector<int> iota(int n) { vector<int> v(n); std::iota(all(v), int(0)); return v; }
vector<int> iota(int a, int b) { vector<int> v(b - a); std::iota(all(v), a); return v; }
namespace BitOperations {
   constexpr int Popcount(int x) { return __builtin_popcountll(x); }
   constexpr int Parity(int x) { return __builtin_parityll(x); }
   constexpr int Ffs(int x) { return __builtin_ffsll(x); }
   constexpr int Clz(int x) { return __builtin_clzll(x); }
   constexpr int Ctz(int x) { return __builtin_ctzll(x); }

   constexpr int Bit(int x) { return 1LL << x; }
   constexpr bool Isbit(int x) { return x and (x & -x) == x; }
   constexpr int Msb(int x) { return x == 0 ? -1 : 63 - Clz(x); }
   constexpr int Lsb(int x) { return x == 0 ? 64 : Ctz(x); }
   constexpr int Allbit(int n) { return (1LL << n) - 1; }
   constexpr bool Stand(int x, int i) { return x & Bit(i); }
   constexpr int Log2i(int x) { return Msb(x); }
}
using namespace BitOperations;

# define ngng628_library
# include __FILE__
# endif