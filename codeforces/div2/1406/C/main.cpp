# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rep2(x,y,w,h) rep (x, w) rep (y, h)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define reps2(x,y,w,h) reps (x, w) reps (y, h)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define range_for(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define CON(x,key) ((x).find(key) != (x).end())
# define cauto const auto
# define int long long
# define float long double
# define FI first
# define SE second
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using mii = unordered_map<int, int>;
template <class Type> inline constexpr Type Square(Type x) { return x * x; }
template <class Type> inline constexpr bool InRange(const Type& x, const Type& fst, const Type& lst) { return (fst <= x) && (x < lst); }
template <class Type> inline void Unique(Type& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class Integer> inline constexpr bool chmax(Integer &a, Integer b) { return a < b && (a = b, true); }
template<class Integer> inline constexpr bool chmin(Integer &a, Integer b) { return a > b && (a = b, true); }
template<class Integer>bool constexpr IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool constexpr IsEven(Integer &n) { return !(n & 1); }
constexpr long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
constexpr long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
string YesNo(bool b) { return b ? "Yes" : "No"; }
string YESNO(bool b) { return b ? "YES" : "NO"; }
string yesno(bool b) { return b ? "yes" : "no"; }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
# define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
# define Cinv(Type, xs, n) vector<Type> xs(n); rep(i, n) cin >> xs[i]
# define Cinv2(Type, xs, ys, n) vector<Type> xs(n), ys(n); rep(i, n) cin >> xs[i] >> ys[i]
# define Cinv3(Type, xs, ys, zs, n) vector<Type> xs(n), ys(n), zs(n); rep(i, n) cin >> xs[i] >> ys[i] >> zs[i]
# define Cinvv(Type, xs, h, w) vector<vector<Type>> xs(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> xs[i][j]
void Print() { cout << endl; }
template <class Head, class... Tail> void Print(Head&& head, Tail&&... tail) { cout << head; if (sizeof...(tail) != 0) cout << " "; Print(forward<Tail>(tail)...); }
template <class Type> void Print(vector<Type> &vec) { for (auto& a : vec) { cout << a; if (&a != &vec.back()) cout << " "; } cout << endl; }
template <class Type> void Print(vector<vector<Type>> &df) { for (auto& vec : df) { Print(vec); } }
void Debug() { cerr << endl; }
template <class Head, class... Tail> void Debug(Head&& head, Tail&&... tail) { cerr << head; if (sizeof...(tail) != 0) cerr << " "; Debug(forward<Tail>(tail)...); }
template <class Type> void Debug(vector<Type> &vec) { for (auto& a : vec) { cerr << a; if (&a != &vec.back()) cerr << " "; } cerr << endl; }
template <class Type> void Debug(vector<vector<Type>> &df) { for (auto& vec : df) { Debug(vec); } }

void Main(vvi& graph, unordered_set<int> node, const int a, const int b) {
    mii mp;
    int maxi = -1;
    for (cauto& it : node) {
        const int out = len(graph[it]);
        mp[it] = out;
        chmax(maxi, out);
    }

    vi ver;
    for (auto [v, out] : mp) {
        if (out == maxi) {
            ver.pb(v);
        }
    }

    if (len(ver) == 1) {
        Print(a+1, b+1);
        Print(a+1, b+1);
        return;
    }

    int v1, v2, w1;
    int m = LONG_LONG_MAX;
    rep (i, len(ver)) {
        int v11 = ver[i];
        int v21 = ver[(i+1)%len(ver)];

        for (int nxt : graph[v11]) {
            if (nxt != v21 and chmin(m, mp[nxt]) ) {
                v1 = v11;
                v2 = v21;
                w1 = nxt;
            }
        }
    }
    Print(min(v1+1, w1+1), max(v1+1, w1+1));
    Print(min(w1+1, v2+1), max(w1+1, v2+1));
}

signed main()
{
    Cin(int, t);
    step (t) {
        Cin(int, n);
        vvi graph(n);
        unordered_set<int> node;
        int a = 0, b = 0;
        rep (i, n-1) {
            Cin(int, x, y);
            x--; y--;
            a = x;
            b = y;
            graph[x].pb(y);
            graph[y].pb(x);
            node.insert(x);
            node.insert(y);
        }
        Main(graph, node, a, b);
    }

    return 0;
}
