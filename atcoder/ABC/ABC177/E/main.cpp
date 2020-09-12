# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define rep2(x,y,w,h) rep (x, w) rep (y, h)
# define reps(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define reps2(x,y,w,h) reps (x, w) reps (y, h)
# define rrep(i,n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i,n) for(int i=((int)(n)); i>0; --i)
# define range_for(i,b,e) for(int i=(b), i##_len=(e); i<i##_len; ++i)
# define step(n) rep(_, n)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define pb push_back
# define eb emplace_back
# define len(x) ((int)(x).size())
# define Find(x,key) ((x).find(key) != (x).end())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
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

struct Prime {
    Prime() : n_max(0) {}
    // O ( N loglog(N) )
    Prime(int n) : n_max(n), table(n+1, true), osak(n+1) {
        iota(osak.begin(), osak.end(), 0);
        osak[0] = 1;
        if(n >= 0) table[0] = false;
        if(n >= 1) table[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if (not table[i]) continue;
            lst.push_back(i);
            for(int k = i + i; k <= n; k += i) {
                table[k] = false;
                osak[k] = i;
            }
        }
    }

    // n <= n_max のとき: O(1)
    // それ超えのとき: O( sqrt(N) )
    bool is(const int n) {
        if (n <= n_max) return table[n];
        if (n <= 4) return n == 2 || n == 3;
        if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
        for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    // O( sqrt(N) )
    map<int, int> factor(int n) {
        if (n == 1) {
            map<int, int> one;
            one[1] = 1;
            return one;
        }
        if (n <= n_max) return impl_factor_fast(n);
        map<int, int> ret;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ret[i]++;
                n /= i;
            }
        }
        if (n != 1) ret[n] = 1;
        return ret;
    }

    // O( log(N) )
    map<int, int> impl_factor_fast(int n) {
        map<int, int> ret;
        while (n != 1) {
            int p = osak[n];
            ret[p]++;
            n /= p;
        }
        return ret;
    }

    // O( len(v) log(v_max) )
    bool to(vector<int> v) {
        unordered_set<int> s;
        for (auto& n : v) {
            while (n != 1) {
                int p = osak[n];
                if (s.find(p) != s.end()) return false;
                else s.insert(p);
                while (n % p == 0) n /= p;
            }
        }
        return true;
    }

    const int n_max;
    vector<bool> table;
    vector<int> osak;
    vector<int> lst;
} PRIME(1e6);

signed main()
{
    Cin(int, N);
    Cinv(int, A, N);
    if (PRIME.to(A)) {
        Print("pairwise coprime");
    }
    else {
        int sum = A[0];
        range_for (i, 1, N) sum = gcd(sum, A[i]);
        if (sum == 1) Print("setwise coprime");
        else Print("not coprime");
    }

    return 0;
}
