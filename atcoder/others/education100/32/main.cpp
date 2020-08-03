# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define pb push_back
# define cauto const auto
# define int long long
using namespace std;
template<class Integer>bool IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool IsEven(Integer &n) { return !(n & 1); }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
void Print() { cout << endl; }
template <class Head, class... Tail> void Print(Head&& head, Tail&&... tail) { cout << head; if (sizeof...(tail) != 0) cout << " "; Print(forward<Tail>(tail)...); }
template <class Type> void Print(vector<Type> &vec) { for (auto& a : vec) { cout << a; if (&a != &vec.back()) cout << " "; } cout << endl; }
template <class Type> void Print(vector<vector<Type>> &df) { for (auto& vec : df) { Print(vec); } }

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};
static const vector<pair<int, int>> dydx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int W, H;

bool read()
{
    cin >> W >> H;
    return not (W == 0 and H == 0);
}

bool read(vector<vector<int>>& G)
{
    rep (y, 2*H - 1)
    {
        rep (x, IsEven(y) ? W - 1 : W)
        {
            Cin(int, v);
            if (v == 0) // 壁なし
            {
                int now = y/2*W + x;
                int nxt = now + 1*IsEven(y) + W*IsOdd(y);
                G[now].pb(nxt);
                G[nxt].pb(now);
            }
        }
    }
    return true;
}

signed main()
{
    while (read())
    {
        vector<vector<int>> G(H*W);
        read(G);
        const int entry = 0;
        const int exit = H*W - 1;

        stack<int> stk;
        vector<int> d(W*H, -1);
        stk.push(entry);
        d[entry] = 0;
        while (not stk.empty())
        {
            int now = stk.top(); stk.pop();
            if (now == exit) break;
            for (cauto& nxt : G[now])
            {
                if (d[nxt] > 0) continue;
                d[nxt] = d[now] + 1;
                stk.push(nxt);
            }
        }
        Print(d[exit] + 1);
    }

    return 0;
}
