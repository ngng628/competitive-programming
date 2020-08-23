# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
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

using P = pair<int, int>;
# define X second
# define Y first
static const int dys[4] = {0, 1, 0, -1};
static const int dxs[4] = {1, 0, -1, 0};

int H, W;

bool over(int y, int x, int h = H, int w = W)
{
    return y < 0 or y >= h or x < 0 or x >= w;
}

signed main()
{
    cin >> H >> W;
    Cin(int, Ch, Cw);
    Ch--; Cw--;
    Cin(int, Dh, Dw);
    Dh--; Dw--;
    vector<vector<int>> S(H, vector<int>(W, 0));
    rep (i, H)
    {
        Cin(string, in);
        rep (k, len(in))
        {
            if (in[k] == '.') S[i][k] = 0;
            else S[i][k] = -1;
        }
    }

    int cur = 1;
    rep (y, H) rep (x, W)
    {
        if (S[y][x] == -1) continue;
        if (S[y][x] >= 1) continue;
        queue<P> que;
        que.push({y, x});
        S[y][x] = cur;
        while (not que.empty())
        {
            P now = que.front(); que.pop();
            rep (i, 4)
            {
                P nxt = {now.Y + dys[i], now.X + dxs[i]};
                if (over(nxt.Y, nxt.X)) continue;
                if (S[nxt.Y][nxt.X] == -1) continue;
                if (S[nxt.Y][nxt.X] >= 1) continue;
                S[nxt.Y][nxt.X] = cur;
                que.push(nxt);
            }
        }
        cur++;
    }


    //=======================================================


    int st = S[Ch][Cw] -1;
    int en = S[Dh][Dw] -1;
    if (st == en) {
        Print("0");
        return 0;
    }
    int N = cur - 1;
    vector<vector<int>> G(N);


    rep (y, H) rep (x, W)
    {
        for (int dy = -2; dy <= 2; ++dy) for (int dx = -2; dx <= 2; ++dx)
        {
            if (over(dy+y, x + dx)) continue;
            if (over(y, x)) continue;
            if (S[y][x] == -1) continue;
            if (S[y+dy][x+dx] == -1) continue;
            int now = S[y][x] -1;
            int nxt = S[y + dy][x + dx]-1;
            if (now != nxt)
            {
                G[now].pb(nxt);
            }
        }
    }
    queue<int> que;
    vector<int> d(N, -1);
    que.push(st);
    d[st] = 0;
    while (not que.empty())
    {
        int now = que.front(); que.pop();
        for (int nxt : G[now])
        {
            if (d[nxt] >= 0) continue;
            d[nxt] = d[now] + 1;
            que.push(nxt);
        }
    }

    Print(d[en]);

    return 0;
}

