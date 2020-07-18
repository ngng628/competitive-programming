# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define Unique(a) a.erase(unique(ALL(a)), a.end())
# define pb push_back
# define len(x) ((int)(x).size())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
# define LINT_MAX (LLONG_MAX)
# define LINT_MIN (LLONG_MIN)
# define cauto const auto
using namespace std;
using int32 = int32_t;
using int64 = int64_t;
using float32 = float;
using float64 = double;
using float128 = long double;
template <class Type> inline constexpr Type Square(Type x) { return x * x; }
template <class Type> inline constexpr bool InRange(const Type& x, const Type& i, const Type& a) { return (i <= x) && (x <= a); }
template<class Integer>bool chmax(Integer &a, const Integer &b) { if (a<b) { a=b; return 1; } return 0; }
template<class Integer>bool chmin(Integer &a, const Integer &b) { if (b<a) { a=b; return 1; } return 0; }
template<class Integer>bool IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool IsEven(Integer &n) { return !(n & 1); }
long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int64 gcd(int64 a, int64 b) { while(b){ int64 A = a; (a = b), (b = A % b); } return a; }
int64 lcm(int64 a, int64 b) { return a / gcd(a, b) * b; }
int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
string YesNo(bool b) { return b ? "Yes" : "No"; }
string YESNO(bool b) { return b ? "YES" : "NO"; }
string yesno(bool b) { return b ? "yes" : "no"; }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
#define Cinv(Type, xs, n) vector<Type> xs(n); rep(i, n) cin >> xs[i]
#define Cinv2(Type, xs, ys, n) vector<Type> xs(n), ys(n); rep(i, n) cin >> xs[i] >> ys[i]
#define Cinv3(Type, xs, ys, zs, n) vector<Type> xs(n), ys(n), zs(n); rep(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinvv(Type, xs, h, w) vector<vector<Type>> xs(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> xs[i][j]
void Print() { cout << endl; }
template <class Head, class... Tail> void Print(Head&& head, Tail&&... tail) { cout << head; if (sizeof...(tail) != 0) cout << " "; Print(forward<Tail>(tail)...); }
template <class Type> void Print(vector<Type> &vec) { for (auto& a : vec) { cout << a; if (&a != &vec.back()) cout << " "; } cout << endl; }
template <class Type> void Print(vector<vector<Type>> &df) { for (auto& vec : df) { Print(vec); } }
void Debug() { cerr << endl; }
template <class Head, class... Tail> void Debug(Head&& head, Tail&&... tail) { cerr << head; if (sizeof...(tail) != 0) cerr << " "; Debug(forward<Tail>(tail)...); }
template <class Type> void Debug(vector<Type> &vec) { for (auto& a : vec) { cerr << a; if (&a != &vec.back()) cerr << " "; } cerr << endl; }
template <class Type> void Debug(vector<vector<Type>> &df) { for (auto& vec : df) { Debug(vec); } }

vector<int> range(int a, int b)
{
    vector<int> ar(b-a, 0);
    iota(ALL(ar), a);
    return ar;
}

int main()
{
    Cin(int64, N, M, K);
    Cinv(int64, A, N);
    Cinv(int64, B, M);

    vector<int64> a(N+1, 0);
    vector<int64> b(M+1, 0);
    for (int64 i : range(1, N+1)) a[i] += a[i-1] + A[i-1];
    for (int64 i : range(1, M+1)) b[i] += b[i-1] + B[i-1];

    int64 ans = 0;
    for (int64 i = N; i >= 0; --i)
    {
        int64 t = a[i];
        if (t > K) continue;
        auto it = upper_bound(ALL(b), K - t);
        int64 dist = distance(b.begin(), it) - 1;
        chmax(ans, i + dist);
    }

    Print(ans);

    return 0;
}

