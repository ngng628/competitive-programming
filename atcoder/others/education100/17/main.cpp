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
template <class Type> inline constexpr bool InRange(const Type& x, const Type& i, const Type& a) { return (i <= x) && (x < a); }
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

using P = pair<int, int>;
# define R first
# define C second

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) f(indexes);
    else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

// nPkの順列に対して処理を実行する
void foreach_permutation(int n, int k, std::function<void(int *)> f) {
    foreach_comb(n, k, [&](int *c_indexes) {
        foreach_permutation(k, [&](int *p_indexes) {
            int indexes[k];
            for (int i = 0; i < k; i++) indexes[i] = c_indexes[p_indexes[i]];
            f(indexes);
        });
    });
}

vector<string> err;

void DebugBoard(const vector<string>& b)
{
    rep (r, len(b))
    {
        cerr << b[r] << "\n";
    }
}

void PrintBoard(const vector<string>& b)
{
    rep (r, 8)
    {
        rep (c,8)
        {
            cout << (b[r][c] == 'Q' ? 'Q' : '.');
        }
        cout << "\n";
    }
}

vector<string> Put(vector<string> board, P pos)
{
    if (board.at(pos.R).at(pos.C) != '.')
    {
        return err;
    }
    rep (r, 8)
    {
        if (board.at(r).at(pos.C) == 'Q') return err;
        board[r][pos.C] = 'x';
    }
    rep (c, 8)
    {
        if (board.at(pos.R).at(c) == 'Q') return err;
        board.at(pos.R).at(c) = 'x';
    }

    range_for (k, -8, 8)
    {
        if (InRange(pos.R + k, (int)0, (int)8) and InRange(pos.C + k, (int)0, (int)8))
        {
            if (board.at(pos.R + k).at(pos.C + k) == 'Q')
            {
                return err;
            }
            board.at(pos.R + k).at(pos.C + k) = 'x';
        }

        if (InRange(pos.R - k, (int)0, (int)8) and InRange(pos.C + k, (int)0, (int)8))
        {
            if (board.at(pos.R - k).at(pos.C + k) == 'Q')
            {
                return err;
            }
            board.at(pos.R - k).at(pos.C + k) = 'x';
        }
    }
    board.at(pos.R).at(pos.C) = 'Q';

    return board;
}


signed main()
{
    err.pb("-1");

    vector<string> board(8);
    rep (i, 8) board[i] = "........";
    assert(board[0].length() == 8);

    Cin(int, k);
    vector<P> p(k);
    rep (i, k)
    {
        cin >> p[i].R >> p[i].C;
        board = Put(board, p[i]);
    }


    // 置けるマスを取得
    vector<P> canPutPos;
    rep (c, 8) rep (r, 8)
    {
        if (board[r][c] == '.') canPutPos.pb(make_pair(r, c));
    }

    vector<string> ans;
    foreach_comb(len(canPutPos), 8 - k, [&](int* idx){
        vector<string> tmp = board;
        bool flag = true;
        rep (i, 8 - k)
        {
            tmp = Put(tmp, canPutPos[idx[i]]);
            if (tmp == err)
            {
                flag = false;
                break;
            }
        }
        if (flag) ans = tmp;
    });

    PrintBoard(ans);

    return 0;
}
