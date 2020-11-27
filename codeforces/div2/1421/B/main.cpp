//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define repr(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define reprs(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define all(x) std::begin(x), std::end(x)
# define rall(x) std::rbegin(x), std::rend(x)
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define contains(x,key) ((x).find(key) != (x).end())
# define cauto const auto
# define int long long
# define real long double
# define FI first
# define SE second
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using mii = map<int, int>;
using msi = map<string, int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for(auto& y : x) is >> y; return is; }
template<class T, class U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.FI >> p.SE; }
template<class T> string join(const vector<T> &v){ stringstream s; rep (i, len(v)) s<<' '<<v[i]; return s.str().substr(1); }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v){ if (len(v)) os << join(v); return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>>& v){ rep (i, len(v)) { if (len(v[i])) os << join(v[i]) << (i-len(v)+1 ? "\n" : ""); } return os; }
void print(){ cout << "\n"; }
template<class T, class... A>void print(const T& v, const A&...args){cout << v; if(sizeof...(args))cout << " "; print(args...);}
void eprint() { cerr << "\n"; }
template<class T, class... A>void eprint(const T& v, const A&...args){cerr << v; if(sizeof...(args))cerr << " "; eprint(args...);}
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){ cout << p.FI << " " << p.SE; return os; }
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class T> inline constexpr bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> inline constexpr bool chmin(T &a, T b) { return a > b && (a = b, true); }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

constexpr array<pair<int, int>, 4> dydx4 = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

bool over(int y, int x, int h, int w) {
    return y < 0 or y >= h or x < 0 or x >= w;
}

bool dfs(vs s) {
    bool res = false;
    for (int ok = 0; ok <= 1; ++ok) {
        const int H = len(s);
        const int W = H;
        queue<pii> que;
        vector<vector<int>> dist(H, vector<int>(W, -1));
        que.emplace(0, 0);
        dist[0][0] = 0;

        while (not que.empty()) {
            pii now = que.front(); que.pop();
            for (auto [dy, dx] : dydx4) {
                pii nxt = make_pair(now.FI + dy, now.SE + dx);
                if (over(nxt.FI, nxt.SE, H, W)) continue;
                if (s[nxt.FI][nxt.SE] != ok + '0' and s[nxt.FI][nxt.SE] != 'F') continue;
                if (dist[nxt.FI][nxt.SE] > 0) continue;
                que.emplace(nxt);
                dist[nxt.FI][nxt.SE] = dist[now.FI][now.SE] + 1;
            }
        }

        res |= (dist[H-1][W-1] != -1);
    }
    return res;
}

void Main() {
    int n;
    cin >> n;
    vs s(n);
    cin >> s;

    if (s[2][0] == s[1][1] and s[1][1] == s[0][2]) {
        char v = s[2][0];
        vpii ans;
        if (s[1][0] == v) ans.eb(2, 1);
        if (s[0][1] == v) ans.eb(1, 2);
        print(len(ans));
        for (pii p : ans) print(p);
    } else {
        if (s[0][1] != s[1][0]) {
            int cnt0 = (s[2][0] == '0') + (s[1][1] == '0') + (s[0][2] == '0');
            int cnt1 = 3 - cnt0;
            if (cnt0 > cnt1) {
                // 0 に合わせる
                vpii ans;
                if (s[2][0] != '0') ans.eb(3, 1);
                if (s[1][1] != '0') ans.eb(2, 2);
                if (s[0][2] != '0') ans.eb(1, 3);

                if (s[1][0] != '1') ans.eb(2, 1);
                if (s[0][1] != '1') ans.eb(1, 2);
                print(len(ans));
                for (pii p : ans) print(p);
            }
            else {
                // 1 に合わせる
                vpii ans;
                if (s[2][0] != '1') ans.eb(3, 1);
                if (s[1][1] != '1') ans.eb(2, 2);
                if (s[0][2] != '1') ans.eb(1, 3);

                if (s[1][0] != '0') ans.eb(2, 1);
                if (s[0][1] != '0') ans.eb(1, 2);
                print(len(ans));
                for (pii p : ans) print(p);
            }
        }
        else {
            vpii ans;
            char v = s[1][0];
            if (s[2][0] == v) ans.eb(3, 1);
            if (s[1][1] == v) ans.eb(2, 2);
            if (s[0][2] == v) ans.eb(1, 3);
            print(len(ans));
            for (pii p : ans) print(p);
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    step (t) Main();

    return 0;
}
