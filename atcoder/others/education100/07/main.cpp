# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define range_for(i, b, e) for(int i=(b), i##_len=(e); i<=i##_len; ++i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define pb push_back
# define len(x) ((int)(x).size())
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
# define LINT_MAX (LONG_LONG_MAX)
# define cauto const auto
using namespace std;
using lint = long long;
template <class Type> inline constexpr bool InRange(const Type& x, const Type& i, const Type& a) { return (i <= x) && (x <= a); }
template<class Integer>bool chmax(Integer &a, const Integer &b) { if (a<b) { a=b; return 1; } return 0; }
template<class Integer>bool chmin(Integer &a, const Integer &b) { if (b<a) { a=b; return 1; } return 0; }
template<class Integer>bool IsOdd(Integer &n) { return n & 1; }
template<class Integer>bool IsEven(Integer &n) { return !(n & 1); }
int ctoi(const char c) { return ('0' <= c && c <= '9') ? (c - '0') : -1; }
string YesNo(bool b) { return b ? "Yes" : "No"; }
string YESNO(bool b) { return b ? "YES" : "NO"; }
string yesno(bool b) { return b ? "yes" : "no"; }

// 整数の桁数を返す ( log(N) )
template <class Integer> Integer GetDigit(Integer n) {
    if (n == 0) return 1;
    Integer d = 0;
    while (n) {
        n /= 10;
        d++;
    }
    return d;
}

// 素数かどうかを返す ( O(sqrt(N)) )
template <class Integer>
constexpr bool IsPrime(const Integer n) noexcept {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
    for (Integer i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

using P = pair<int, int>;
# define X first
# define Y second

int main()
{
    int N; cin >> N;
    vector<P> points(N);
    map<P, int> mp;
    rep (i, N)
    {
        cin >> points[i].X >> points[i].Y;
        mp[points[i]] = 1;
    }
    rep (i, N)
        cerr << "[Debug]" << points[i].X << " " << points[i].Y << "\n";

    map<pair<P, P>, int> visited;
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int k = i+1; k < N; ++k)
        {
            P P1 = points[i];
            P P2 = points[k];
            if (visited[P(P1)])

            int dx = P2.X - P1.X;
            int dy = P2.Y - P1.Y;

            // 候補1
            P suj1 = P(P1.X + dy, P1.Y - dx);
            P suj2 = P(P2.X + dy, P2.Y - dx);
            // 候補2
            P suj3 = P(P1.X - dy, P1.Y + dx);
            P suj4 = P(P2.X - dy, P2.Y + dx);
            if ((mp[suj1] and mp[suj2]) or (mp[suj3] and mp[suj4]))
            {
                int S = dx*dx + dy*dy;
                chmax(ans, S);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
