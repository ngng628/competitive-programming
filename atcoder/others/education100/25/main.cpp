# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define Find(v,key) ((v).find(key) != (v).end())
# define cauto const auto
# define int long long
using namespace std;
template <class Type> inline constexpr bool InRange(const Type& x, const Type& fst, const Type& lst) { return (fst <= x) && (x < lst); }
void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
#define Cin(Type, ...) Type __VA_ARGS__; _cin(__VA_ARGS__)
#define Cinvv(Type, xs, h, w) vector<vector<Type>> xs(h, vector<int>(w)); rep(i, h) rep(j, w) cin >> xs[i][j]

# define mp(f,s) make_pair(f, s)

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

bool can(const vector<vector<int>>& c, int h, int w, P pos) {
    return InRange(pos.Y, (int)0, h)
       and InRange(pos.X, (int)0, w)
       and c[pos.Y][pos.X] == 1;
}

signed main() {
    while (true) {
        Cin(int, w, h);
        if (w == 0 and h == 0) break;
        Cinvv(int, c, h, w);

        set<P> visited;
        int ans = 0;
        rep (y, h) rep (x, w) {
            stack<P> stk;
            P ini = mp(y, x);
            if (!Find(visited, ini) and can(c, h, w, ini)) ans++;
            else continue;
            stk.push(ini);
            visited.insert(ini);

            while (!stk.empty()) {
                P now = stk.top(); stk.pop();
                for (int dy = -1; dy <= 1; ++dy) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        P nxt = mp(now.Y + dy, now.X + dx);
                        if (!can(c, h, w, nxt)) continue;
                        if (Find(visited, nxt)) continue;
                        stk.push(nxt);
                        visited.insert(nxt);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
