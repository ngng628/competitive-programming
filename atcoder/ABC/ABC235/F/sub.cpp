#include <bits/stdc++.h>
using namespace std;
#ifdef INCLUDED_MY_LIBRARY
using Mint = ModInt998244353;

int main() {
    STR(N);
    INT(M);
    VEC(int, C, M);

    let L = LEN(N);

    auto dpc = vector(2, vector(1 << 10, Mint::raw(0)));
    auto dps = vector(2, vector(1 << 10, Mint::raw(0)));
    dpc[0][0] = 1;
    dps[0][0] = 0;

    rep(i, 0, L) {
        let Ni = N[i] - '0';
        auto nxtdpc = vector(2, vector(1 << 10, Mint::raw(0)));
        auto nxtdps = vector(2, vector(1 << 10, Mint::raw(0)));

        rep(smaller, 0, 2) rep(bits, 0, 1 << 10) rep(x, 0, 10) {
            if (!smaller && x > Ni) continue;
            let nxtsmaller = smaller || x < Ni;

            int nxtbits = bits;
            if (x == 0) {
                if (bits) nxtbits |= 1;
            } else {
                nxtbits |= 1 << x;
            }

            nxtdpc[nxtsmaller][nxtbits] += dpc[smaller][bits];
            nxtdps[nxtsmaller][nxtbits] += (10 * dps[smaller][bits]) + (dpc[smaller][bits] * x);
        }

        swap(dpc, nxtdpc);
        swap(dps, nxtdps);
    }

    int mask = 0;
    for (let c : C) mask |= 1 << c;

    Mint ans = 0;

    rep(bits, 0, 1 << 10) {
        if ((bits & mask) == mask) {
            ans += dps[0][bits] + dps[1][bits];
        }
    }
    echo(ans);
}


#else

#define rep(i, a, b)     for (auto i = (a); i < (b); ++i)
#define repc(i, a, b)    for (auto i = (a); i <= (b); ++i)
#define repr(i, a, b)    for (int i = (a); i >= (b); --i)
#define each_rev(itr, a) for (auto itr = rbegin(a); itr != rend(a); ++itr)
#define fn1(x, expr)    [&](const auto& x) { return (expr); }
#define fn2(x, y, expr) [&](const auto& x, const auto& y) { return (expr); }
#define pb          push_back
#define eb          emplace_back
#define LEN(a)      int(a.size())
#define all(a)      begin(a), end(a)
#define rall(a)     rbegin(a), rend(a)
#define lb(a, elem) distance(std::begin(a), lower_bound(all(a), (elem)))
#define ub(a, elem) distance(std::begin(a), upper_bound(all(a), (elem)))
#define MIN(a)      (*min_element(all(a)))
#define MAX(a)      (*max_element(all(a)))
#define UNIQ(a)     a.erase(unique(all(a)), end(a))
#define IN(x, begin, end) ((begin) <= (x) && (x) < (end))
// type alias
#define let const auto
using i64 = int64_t;
using u64 = uint64_t;
using i32 = int32_t;
using u32 = uint32_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
using ldouble = long double;
template <class T> using vec = std::vector<T>;
template <class T> using MaxHeap = std::priority_queue<T>;
template <class T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
// constants
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.14159265358979323846;
constexpr std::pair<int, int> DIR4[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
constexpr std::pair<int, int> DIR8[] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
// utils
template <class T, class U> inline bool chmin(T& a, const U& b) { return b < a && (a = b, true); }
template <class T, class U> inline bool chmax(T& a, const U& b) { return b > a && (a = b, true); }
template <class T> inline int sgn(T x) noexcept { return (T(0) < x) - (x < T(0)); }
template <class T, class U> inline auto divup(T a, U b) noexcept { return (a + b - 1) / b; }
template <class T, class U> inline auto sigma(const T& l, const U& r) noexcept { return (l + r) * (r - l + 1) / 2; }
inline i64 sigma(int l, int r) noexcept { return sigma((i64)l, (i64)r); }
inline i64 choose2(i64 n) noexcept { return n * (n - 1) >> 1; }
inline void yes(bool x = true) { cout << (x ? "yes\n" : "no\n"); }
inline void Yes(bool x = true) { cout << (x ? "Yes\n" : "No\n"); }
inline void YES(bool x = true) { cout << (x ? "YES\n" : "NO\n"); }
#define WHEN_BYTESIZE(T, bytes) template <typename T, std::enable_if_t<sizeof(T) == (bytes), std::nullptr_t> = nullptr>
WHEN_BYTESIZE(T, 4) inline int popcnt(T n) { return __builtin_popcount((unsigned)n); }
WHEN_BYTESIZE(T, 8) inline int popcnt(T n) { return __builtin_popcountll((unsigned long long)n); }
WHEN_BYTESIZE(T, 4) inline int topbit(T n) { return n == 0 ? -1 : 31 - __builtin_clz((unsigned)n); }
WHEN_BYTESIZE(T, 8) inline int topbit(T n) { return n == 0 ? -1 : 63 - __builtin_clzll((unsigned long long)n); }
WHEN_BYTESIZE(T, 4) inline int lowbit(T n) { return n == 0 ? 32 : __builtin_ctz((unsigned)n); }
WHEN_BYTESIZE(T, 8) inline int lowbit(T n) { return n == 0 ? 64 : __builtin_ctzll((unsigned long long)n); }
template <typename T> inline bool ispow2(T i) { return i && (i & -i) == i; }

template <class Container, enable_if_t<not is_same_v<typename Container::value_type, char>, nullptr_t> = nullptr>
istream& operator>>(istream& is, Container& a) {
    for (auto&& e : a) is >> e;
    return is;
}
istream& operator>>(istream& is, vector<char>& a) {
    for (auto& c: a) is >> c;
    return is;
}
template <class Container, enable_if_t<not is_same_v<typename Container::value_type, char>, nullptr_t> = nullptr>
ostream& operator<<(ostream& os, const Container& a) {
    if (&os != &cout) {
        os << '[';
        unsigned cnt = 0;
        for (auto it = begin(a); it != end(a) && cnt < 30; ++it, ++cnt) os << *it << (cnt + 1 < size(a) ? ", " : "");
        if (cnt < size(a)) os << "...";
        return os << ']';
    }
    if (a.size() == 0) return os;
    os << *begin(a);
    for (auto it = next(begin(a)); it != end(a); ++it) os << ' ' << *it;
    return os;
}
ostream& operator<<(ostream& os, const vector<char>& a) {
    os << '[';
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (isprint(*it)) os << '\'' << *it << '\'';
        else os << int(*it);
        os << " "[it + 1 == a.end()];
    }
    return os << ']';
}
template <class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

ostream& operator<<(ostream& os, __uint128_t n) {
    if (n == 0) return os << '0';
    char buf[40]{};
    char* p = buf + 38;
    while (n) {
        *(p--) = char(n % 10) + '0';
        n /= 10;
    }
    return os << (p + 1);
}

ostream& operator<<(ostream& os, __int128_t n) {
    if (n < 0) return os << '-' << __uint128_t(-n);
    return os << __uint128_t(n);
}

istream& operator>>(istream& is, __uint128_t& n) {
    int c;
    while (isspace(c = is.get()));
    n = unsigned(c - '0');
    while (isdigit(c = is.get())) n = n * 10 + unsigned(c - '0');
    return is;
}

istream& operator>>(istream& is, __int128_t& n) {
    int c;
    bool neg;
    while (isspace(c = is.get()));
    if (c == '-') {
        n = 0;
        neg = true;
    } else {
        n = c - '0';
        neg = false;
    }
    while (isdigit(c = is.get())) n = n * 10 + (c - '0');
    if (neg) n = -n;
    return is;
}

inline void echo() { std::cout << '\n'; }

template <class Head, class... Tail>
inline void echo(Head&& head, Tail&&... tail) {
    std::cout << head;
    if constexpr (sizeof...(tail)) std::cout << ' ';
    echo(std::forward<Tail>(tail)...);
}

template <class... Args>
inline void read(Args&... args) {
    (std::cin >> ... >> args);
}

static inline void __attribute__((constructor)) io_setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
}

#ifdef LOCAL_DEBUG
#define dump(...) (std::clog << "\e[34;1mL" << __LINE__ << ": \e[m"), dbg_impl::dump_(dbg_impl::split_(#__VA_ARGS__).begin(), __VA_ARGS__)
namespace dbg_impl {
vector<string> split_(const char* s) {
    vector<string> res;
    char buf[64], *end = buf;
    unsigned paren = 0, brace = 0;
    for (const char* p = s; *p != '\0'; ++p) {
        if (*p == ' ') continue;
        if (*p == ',' && paren == 0 && brace == 0) {
            res.emplace_back(buf, end), end = buf;
            continue;
        }
        if (*p == '(') ++paren;
        if (*p == ')') --paren;
        if (*p == '{') ++brace;
        if (*p == '}') --brace;
        *end++ = *p;
    }
    res.emplace_back(buf, end);
    return res;
}
void dump_(vector<string>::iterator) { std::clog << std::endl; }

template <class Head, class... Tail>
void dump_(vector<string>::iterator itr, Head&& head, Tail&&... tail) {
    std::clog << *itr << "\e[90;1m=\e[33;1m" << head << "\e[m, ";
    dump_(++itr, std::forward<Tail>(tail)...);
}
}  // namespace dbg_impl
#else
#define dump(...) ((void)0)
#endif

#define INT(...) int __VA_ARGS__; read(__VA_ARGS__)
#define LL(...)  i64 __VA_ARGS__; read(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; read(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; read(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; read(__VA_ARGS__)
#define VEC(type, name, len) vector<type> name(len); cin >> name

template <class T>
struct Cumsum {
    using value_type = T;
    std::valarray<T> data;
    Cumsum() = default;
    explicit Cumsum(const std::vector<T>& a) : data(a.size() + 1) {
        for (size_t i = 0; i < a.size(); ++i) data[i + 1] = data[i] + a[i];
    }
    //! range sum [l, r)
    inline const T sum(size_t l, size_t r) const {
        assert(l <= r);
        return data[r] - data[l];
    }
    inline size_t size() const { return data.size(); }
    inline auto begin() const { return std::begin(data); }
    inline auto end() const { return std::end(data); }
};

template <class T, class Func>
inline T bin_search(T ok, T ng, const Func& isOk) {
    while (std::abs(ok - ng) > 1) {
        const T mid = (ok + ng) >> 1;
        (isOk(mid) ? ok : ng) = mid;
    }
    return ok;
}

template <class ForwardItr>
auto runlength(const ForwardItr begin, const ForwardItr end) {
    vector<pair<ForwardItr, size_t>> res;
    res.reserve(distance(begin, end));
    for (auto itr = begin; itr != end;) {
        size_t cnt = 1;
        const auto head = itr++;
        while (itr != end && *itr == *head) ++itr, ++cnt;
        res.emplace_back(head, cnt);
    }
    res.shrink_to_fit();
    return res;
}

template <typename T>
constexpr T power(T x, int64_t exp) {
    T res(1);
    if (exp < 0) exp = -exp, x = 1 / x;
    for (; exp; exp >>= 1) {
        if (exp & 1) res *= x;
        x *= x;
    }
    return res;
}

template <typename CostT>
struct WeightedEdge {
    using Self = WeightedEdge<CostT>;
    uint32_t to;
    CostT cost;

    WeightedEdge() = default;
    WeightedEdge(unsigned to_, CostT cost_) : to(to_), cost(cost_) {}
    operator int() const { return (int)to; }
    operator uint32_t() const { return (uint32_t)to; }
    bool operator<(const Self& other) const { return cost < other.cost; }
    bool operator>(const Self& other) const { return cost > other.cost; }
    bool operator<=(const Self& other) const { return cost <= other.cost; }
    bool operator>=(const Self& other) const { return cost >= other.cost; }
    friend ostream& operator<<(ostream& os, const Self& e) { return os << "(to=" << e.to << ", cost=" << e.cost << ")"; }
};
template <class CostT>
using WGraph = vector<vector<WeightedEdge<CostT>>>;

using UWGraph = vector<vector<uint32_t>>;

enum class Directed : bool { No, Yes };

template <Directed directed>
UWGraph read_unweighted_graph(size_t vertex_num, size_t edge_num, bool decrement_node_id = true) {
    UWGraph g(vertex_num);
    for (size_t i = 0; i < edge_num; ++i) {
        uint32_t a, b;
        cin >> a >> b;
        if (decrement_node_id) --a, --b;
        g[a].push_back(b);
        if constexpr (directed == Directed::No) g[b].push_back(a);
    }
    return g;
}

template <Directed directed, class CostT>
WGraph<CostT> read_weighted_graph(size_t vertex_num, size_t edge_num, bool decrement_node_id = true) {
    WGraph<CostT> g(vertex_num);
    for (size_t i = 0; i < edge_num; ++i) {
        uint32_t a, b;
        CostT cost;
        cin >> a >> b >> cost;
        if (decrement_node_id) --a, --b;
        g[a].emplace_back(b, cost);
        if constexpr (directed == Directed::No) g[b].emplace_back(a, cost);
    }
    return g;
}

template <uint32_t MOD>
class ModInt {
    static_assert(MOD < numeric_limits<uint32_t>::max() / 2);
    uint32_t value;

public:
    using value_type = uint32_t;

    constexpr ModInt() : value(0) {}
    constexpr ModInt(int64_t n) : value(n >= 0 ? uint32_t(uint64_t(n) % MOD) : uint32_t(MOD - uint64_t(-n) % MOD)) {}
    constexpr ModInt(int32_t n) : value(n >= 0 ? uint32_t(n) % MOD : (MOD - uint32_t(-n) % MOD)) {}
    constexpr ModInt(uint64_t n) : value(uint32_t(n % MOD)) {}
    constexpr ModInt(uint32_t n) : value(n % MOD) {}
    inline static constexpr auto mod() { return MOD; }

    template <typename T>
    constexpr static ModInt raw(T n) {
        ModInt ret;
        ret.value = (value_type)n;
        return ret;
    }
    template <typename T>
    constexpr explicit operator T() const {
        return T(value);
    }
    ModInt& operator+=(const ModInt rhs) {
        if ((value += rhs.value) >= MOD) value -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt rhs) {
        if (value < rhs.value) value += MOD;
        value -= rhs.value;
        return *this;
    }
    ModInt& operator*=(const ModInt rhs) {
        value = uint32_t(uint64_t(value) * rhs.value % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt rhs) { return *this *= rhs.inv(); }

    constexpr const ModInt inv() const {
        value_type a = value, b = MOD;
        int u = 1, v = 0;
        while (b > 0) {
            const auto t = a / b;
            swap(a -= b * t, b);
            swap(u -= v * (int)t, v);
        }
        return ModInt(u);
    }
    constexpr const ModInt pow(int64_t exp) const {
        ModInt ret = 1u, doubled = *this;
        if (exp < 0) {
            exp = -exp;
            doubled = doubled.inv();
        }
        while (exp) {
            if (exp & 1) ret *= doubled;
            doubled *= doubled;
            exp >>= 1;
        }
        return ret;
    }
    const ModInt operator+() const { return *this; }
    const ModInt operator-() const { return ModInt::raw(MOD - value); }
    friend const ModInt operator+(ModInt lhs, const ModInt rhs) { return lhs += rhs; }
    friend const ModInt operator-(ModInt lhs, const ModInt rhs) { return lhs -= rhs; }
    friend const ModInt operator*(ModInt lhs, const ModInt rhs) { return lhs *= rhs; }
    friend const ModInt operator/(ModInt lhs, const ModInt rhs) { return lhs /= rhs; }
    friend bool operator==(const ModInt lhs, const ModInt rhs) { return lhs.value == rhs.value; }
    friend bool operator!=(const ModInt lhs, const ModInt rhs) { return !(lhs == rhs); }
    friend ostream& operator<<(ostream& os, const ModInt n) { return os << n.value; }
    friend istream& operator>>(istream& is, ModInt& n) {
        int64_t tmp;
        is >> tmp;
        n = ModInt(tmp);
        return is;
    }
};

using ModInt998244353 = ModInt<998244353>;
using ModInt1000000007 = ModInt<1000'000'007>;

#define INCLUDED_MY_LIBRARY
#include __FILE__
#endif
