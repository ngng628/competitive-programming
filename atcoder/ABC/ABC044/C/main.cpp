//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rep2(x,y,w,h) rep (x, w) rep (y, h)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define reps2(x,y,w,h) reps (x, w) reps (y, h)
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
# define float long double
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
constexpr long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
constexpr long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
const char* YesNo(bool b) { return b ? "Yes" : "No"; }
const char* YESNO(bool b) { return b ? "YES" : "NO"; }
const char* yesno(bool b) { return b ? "yes" : "no"; }
const char* yn(bool b) { return YesNo(b); }

static const int N_MAX = 50;
static const int A_MAX = 50;
static const int X_MAX = 50;
int dp[N_MAX + 10][N_MAX + 10][N_MAX*A_MAX + 10];

signed main() {
    int n, a;
    cin >> n >> a;
    vi x(n + 1);
    reps (i, n) cin >> x[i];

    dp[0][0][0] = 1;
    rep (i, n + 1) {
        dp[i][0][0] = 1;
    }
    reps (i, n) {
        reps (k, n + 1) {
            rep (s, 50*50 + 10) {
                if (s - x[i] >= 0) {
                    dp[i][k][s] = dp[i-1][k][s] + dp[i-1][k-1][s - x[i]];
                }
                else {
                    dp[i][k][s] = dp[i-1][k][s];
                }
            }
        }
    }

    int ans = 0;
    reps (k, n) ans += dp[n][k][a*k];

    print(ans);

    return 0;
}

