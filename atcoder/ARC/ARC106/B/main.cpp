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
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using mii = map<int, int>;
using msi = map<string, int>;
template<class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<class T> istream& operator>>(istream& is, vector<vector<T>>& v) { for(auto& x : v) for (auto& y : x) is >> y; return is; }
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

class UnionFind {
public:
    UnionFind() : _n(0) {}
    UnionFind(int n) : _n(n), parent_or_size(n, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < _n);	
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
    vvi groups() {
        vi leader_buf(_n), group_size(_n);
        rep (i, _n) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vvi result(_n);
        rep (i, _n) result[i].reserve(group_size[i]);
        rep (i, _n) result[leader_buf[i]].pb(i);
        result.erase(
        remove_if(all(result), [&](const vi& v) { return v.empty(); }), result.end());
        return result;
    }
private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int32_t main() {
    int v, e;
    cin >> v >> e;
    vi a(v), b(v);
    cin >> a >> b;
    vi s(v);
    rep (i, v) s[i] = b[i] - a[i];
    vvi graph(v);
    UnionFind uf(v);
    rep (i, e) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        graph[c].pb(d);
        graph[d].pb(c);
        uf.merge(c, d);
    }

    for (vi group : uf.groups()) {
        if (group.empty()) continue;
        int ini = group[0];
        queue<int> que;
        que.push(ini);
        vb visited(v, false);
        visited[ini] = true;
        int ans = 0;
        while (not que.empty()) {
            int now = que.front(); que.pop();
            ans += s[now];
            //int sum = s[now];
            //for (int nxt : graph[now]) sum += s[nxt];
            //if (sum == 0) {
            //    s[now] = 0;
            //    for (int nxt : graph[now]) s[nxt] = 0;
            //}
            for (int nxt : graph[now]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                que.push(nxt);
            }
        }
        if (ans != 0) {
            print("No");
            return 0;
        }
    }

    //rep (i, v) {
    //    if (s[i] != 0) {
    //        print("No");
    //        return 0;
    //    }
    //}

    print("Yes");

    return 0;
}

