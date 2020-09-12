# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rep2(x, y, w, h) rep (x, w) rep (y, h)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define reps2(x, y, w, h) reps (x, w) reps (y, h)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define pb push_back
# define len(x) ((int)(x).size())
# define Find(x,key) ((x).find(key) != (x).end())
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

// auto mod int
 const int mod = 1000000007;
 struct mint {
   int x; // typedef long long ll;
   mint(int x=0):x((x%mod+mod)%mod){}
   mint operator-() const { return mint(-x);}
   mint& operator+=(const mint a) {
     if ((x += a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator-=(const mint a) {
     if ((x += mod-a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
   mint operator+(const mint a) const { return mint(*this) += a;}
   mint operator-(const mint a) const { return mint(*this) -= a;}
   mint operator*(const mint a) const { return mint(*this) *= a;}
   mint pow(int t) const {
     if (!t) return {1};
     mint a = pow(t>>1);
     a *= a;
     if (t&1) a *= *this;
     return a;
   }
 
   // for prime mod
   mint inv() const { return pow(mod-2);}
   mint& operator/=(const mint a) { return *this *= a.inv();}
   mint operator/(const mint a) const { return mint(*this) /= a;}
   bool operator<(const mint& iValue) const { return this->x < iValue.x; }
 };
 istream& operator>>(istream& is, mint& a) { return is >> a.x;}
 ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

template <class Type>
vector<Type> cumsum(const vector<Type>& a)
{
    int n = a.size();
    vector<Type> sums(n+1);
    sums[0] = 0;
    reps (i, n) sums[i] = sums[i-1] + a[i-1];
    return sums;
}

signed main()
{
    Cin(int, N);
    vector<mint> A(N);
    rep (i, N) {
        Cin(int, a);
        A[i] = a;
    }
    vector<mint> sums = cumsum(A);

    mint ans = 0;
    rep (i, N - 1)
    {
        mint sum = sums[N] - sums[i+1];
        ans += A[i] * sum;
    }

    cout << ans << endl;

    return 0;
}

