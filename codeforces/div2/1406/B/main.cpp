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
using mii = map<int, int>;
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

int mex(vi& a) {
    sort(ALL(a));
    rep (i, 110) {
        if (!binary_search(ALL(a), i)) {
            return i;
        }
    }
    return 0;
}

void Main(int n, vi& a) {
    sort(RALL(a), [](int a, int b) -> bool {
        return abs(a) < abs(b);
    });
    int ans = 1;
    bool sgn = true;
    int nidx = -1;
    int pidx = -1;
    rep (i, 5) {
        if (a[i] < 0) {
            sgn = !sgn;
            nidx = i;
        } else if (a[i] > 0) {
            pidx = i;
        }
        ans *= a[i];
    }

    if (sgn) {
        Print(ans);
    }
    else {
        if (pidx == -1) {
            range_for (i, 5, n) {
                if (a[i] > 0) {
                    Print((ans / a[nidx])*a[i]);
                    return;
                }
            }
            sort(ALL(a), [](int a, int b) -> bool {
                return abs(a) < abs(b);
            });
            ans = 1;
            rep (i, 5) ans *= a[i];
            Print(ans);
        }
        else {
            int ans1 = ans, ans2 = ans;
            bool ok1, ok2;
            ok1 = ok2 = false;
            range_for (i, 5, n) {
                if (a[i] > 0 and !ok1) {
                    ans1 = (ans / a[nidx])*a[i];
                    ok1 = true;
                }
                if (a[i] < 0 and !ok2) {
                    ans2 = (ans / a[pidx])*a[i];
                    ok2 = true;
                }
            }
            if (ans1 == ans and ans2 == ans) {
                sort(ALL(a), [](int a, int b) -> bool {
                    return abs(a) < abs(b);
                });
                ans = 1;
                rep (i, 5) ans *= a[i];
                Print(ans);
            } else {
                Print(max(ans1, ans2));
            }
        }
    }
}

signed main()
{
    Cin(int, t);
    step(t) {
        Cin(int, n);
        Cinv(int, a, n);
        Main(n, a);
    }

    return 0;
}
