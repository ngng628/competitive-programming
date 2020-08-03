# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
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
# define int long long
# define float long double
using namespace std;
template <class Type> inline constexpr Type Square(Type x) { return x * x; }
template <class Type> inline constexpr bool InRange(const Type& x, const Type& fst, const Type& lst) { return (fst <= x) && (x < lst); }
template<class Integer> inline bool chmax(Integer &a, Integer b) { return a < b && (a = b, true); }
template<class Integer> inline bool chmin(Integer &a, Integer b) { return a > b && (a = b, true); }
template<class Integer>bool IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool IsEven(Integer &n) { return !(n & 1); }
long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
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

int mode(const vector<int>& v)
{
    map<int, int> cnt;
    for (cauto it : v)
    {
        cnt[it]++;
    }

    int c = -1;
    int res = -1;
    for (cauto& p : cnt)
    {
        if (chmax(c, p.second))
        {
            res = p.first;
        }
    }

    return res;
}

int mode2(const vector<int>& v, int jogai)
{
    map<int, int> cnt;
    for (cauto it : v)
    {
        cnt[it]++;
    }

    int c = -1;
    int res = -1;
    for (cauto& p : cnt)
    {
        if (p.first != jogai and chmax(c, p.second))
        {
            res = p.first;
        }
    }

    return res;
}

signed main()
{
    Cin(int, n);
    vector<int> even(n/2), odd(n/2);
    rep (i, n)
    {
        if (IsEven(i)) cin >> even[i/2];
        else cin >> odd[i/2];
    }

    int me = mode(even);
    int mo = mode(odd);

    if (me != mo)
    {
        int eans = (n/2) - count(ALL(even), me);
        int oans = (n/2) - count(ALL(odd), mo);
        Print(eans + oans);
    }
    else
    {
        int me2 = mode2(even, me);
        int mo2 = mode2(odd, mo);

        int eans1 = (n/2) - count(ALL(even), me);
        int oans1 = (n/2) - count(ALL(odd), mo2);
        int eans2 = (n/2) - count(ALL(even), me2);
        int oans2 = (n/2) - count(ALL(odd), mo);

        Print(min(eans1 + oans1, eans2 + oans2));
    }

    return 0;
}

