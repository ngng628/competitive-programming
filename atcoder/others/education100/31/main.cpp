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
template<class Integer>bool chmax(Integer &a, const Integer &b) { if (a<b) { a=b; return 1; } return 0; }
template<class Integer>bool chmin(Integer &a, const Integer &b) { if (b<a) { a=b; return 1; } return 0; }
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
# define MP(x,y) make_pair(x,y)

using P = pair<int, int>;
# define Y first
# define X second
struct phash {
    inline size_t operator ()(const pair<int,int>& p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

bool over(const vector<vector<int>>& M, const P& pos) {
    int h = len(M);
    int w = len(M[0]);

    return not (InRange(pos.Y, (int)0, h) and InRange(pos.X, (int)0, w));
}

int N = 0;

bool inside(const vector<vector<int>>& M, const P& pos) {
    return InRange(M[pos.Y][pos.X], (int)0, N);
}

bool outside(const vector<vector<int>>& M, const P& pos) {
    return not inside(M, pos);
}

signed main()
{
    vector<P> dydx[2] = {
        {{-1, 0}, {0, -1}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}},
        {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {0, 1}, {1, 0}}
    };

    Cin(int, W, H);
    vector<vector<int>> M(H, vector<int>(W, -1));
    rep (y, H)
    {
        rep (x, W)
        {
            Cin(int, m);
            if (m != 0) M[y][x] = N++;
        }
    }
    
    Debug("================");
    Debug("N: ", N);
    Debug(M);
    Debug("================");

    // 隣接リスト形式にする
    vector<vector<int>> G(N);
    {
        set<P> visited;
        rep (y, H) rep (x, W)
        {
            queue<P> que;
            if (outside(M, MP(y, x))) continue;
            que.push(MP(y, x));

            while (not que.empty())
            {
                P now = que.front(); que.pop();
                for (auto [dy, dx] : (IsEven(now.Y) ? dydx[0] : dydx[1]))
                {
                    P nxt = MP(now.Y + dy, now.X + dx);
                    if (over(M, nxt)) continue;
                    if (outside(M, nxt)) continue;
                    int u = M[now.Y][now.X];
                    int v = M[nxt.Y][nxt.X];
                    if (visited.find(MP(u, v)) != visited.end()) continue;
                    if (visited.find(MP(v, u)) != visited.end()) continue;
                    G[u].pb(v);
                    G[v].pb(u);
                    visited.insert(MP(u, v));
                }
            }
        }
    }

    // 建物チェック
    vector<int> L(N, 0);
    {
        queue<int> que;
        rep (i, N)
        {
            L[i] = 6 - len(G[i]);
        }
    }

    // 隣接チェック
    rep (y, H) rep (x, W)
    {
        stack<P> stk;
        if (inside(M, MP(y, x))) continue;
        if (M[y][x] == 1e6 or M[y][x] == 2e6) continue;
        stk.push(MP(y, x));
        stack<P> post;
        set<P> visited;
        visited.insert(MP(y, x));

        bool flag = false;
        while (not stk.empty())
        {
            P now = stk.top(); stk.pop();
            post.push(now);
            for (auto [dy, dx] : (IsEven(now.Y) ? dydx[0] : dydx[1]))
            {
                P nxt = MP(now.Y + dy, now.X + dx);
                if (over(M, nxt))
                {
                    flag = true;
                    continue;
                }
                if (inside(M, nxt)) continue;
                if (visited.find(nxt) != visited.end()) continue;
                stk.push(nxt);
                visited.insert(nxt);
            }
        }

        if (flag)
        {
            while (not post.empty())
            {
                P now = post.top(); post.pop();
                M[now.Y][now.X] = 1e6;
            }
        }
        else
        {
            while (not post.empty())
            {
                P now = post.top(); post.pop();
                M[now.Y][now.X] = 2e6;
            }
        }
    }

    Debug("=========");
    Debug(M);
    Debug("=========");

    vector<vector<int>> D(H, vector<int>(W, 0));
    rep (y, H) rep (x, W)
    {
        if (M[y][x] == 2e6)
        {
            for (auto [dy, dx] : (IsEven(y) ? dydx[0] : dydx[1]))
            {
                P nxt = MP(y + dy, x + dx);
                if (not over(M, nxt))
                {
                    if (inside(M, nxt)) 
                    {
                        D[nxt.Y][nxt.X] += 1;
                    }
                }
            }
        }
    }

    int loss = 0;
    rep(y, H) 
    {
        loss += accumulate(ALL(D[y]), 0);
    }

    Print(accumulate(ALL(L), 0) - loss);

    return 0;
}
