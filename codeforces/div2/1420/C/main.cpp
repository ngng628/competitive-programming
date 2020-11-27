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
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
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
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
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
template<class T> inline constexpr bool InRange(const T& x, const T& fst, const T& lst) { return (fst <= x) && (x < lst); }
template<class T> inline void Unique(T& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
template<class Integer> inline constexpr bool chmax(Integer &a, Integer b) { return a < b && (a = b, true); }
template<class Integer> inline constexpr bool chmin(Integer &a, Integer b) { return a > b && (a = b, true); }
constexpr long long gcd(long long a, long long b) { while(b){ long long A = a; (a = b), (b = A % b); } return a; }
constexpr long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
constexpr int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
constexpr const char* YesNo(bool b) { return b ? "Yes" : "No"; }
constexpr const char* YESNO(bool b) { return b ? "YES" : "NO"; }
constexpr const char* yesno(bool b) { return b ? "yes" : "no"; }
constexpr const char* yn(bool b) { return YesNo(b); }

static const bool pos = true;
static const bool neg = false;

void Main(int n, vi& a) {
    if (n == 1) {
        print(a[0]);
        return;
    }

    int tmp = a[0];
    vi pole;
    pole.pb(a[0]);
    bool sgn = (a[1] - a[0] > 0);
    reps (i, n-1) {
        if (sgn == pos) {
            if (!chmax(tmp, a[i])) {
                pole.pb(tmp);
                tmp = a[i];
                sgn = !sgn;
            }
        }
        else if (sgn == neg) {
            if (!chmin(tmp, a[i])) {
                pole.pb(tmp);
                tmp = a[i];
                sgn = !sgn;
            }
        }
    }
    pole.pb(a[len(a)-1]);

    if (len(pole) == 1) {
        print(max(a[0], a[len(a) - 1]));
    } else {
        int sum = 0;
        if (pole[1] - pole[0] >= 0) {
            sum = pole[1];
            for (int i = 2; i+1 < len(pole); i += 2) {
                sum = sum - pole[i] + pole[i+1];
            }
        } else {
            sum = pole[0];
            for (int i = 1; i+1 < len(pole); i += 2) {
                sum = sum - pole[i] + pole[i+1];
            }
        }
        print(sum);
    }
}

signed main() {
    int t;
    cin >> t;
    step (t) {
        int n, q;
        cin >> n >> q;
        vi a(n);
        cin >> a;
        Main(n, a);
    }

    return 0;
}
