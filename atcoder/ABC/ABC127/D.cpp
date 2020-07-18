# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define MSG(x) std::cout << #x << " : " << x << "\n";
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
struct BC
{
    BC(lint _b, lint _c)
        : b(_b)
        , c(_c)
    {
    }
 
    lint b;
    lint c;
 
    bool operator <(const BC& other) const
    {
        return this->c < other.c;
    }
    bool operator >(const BC& other) const
    {
        return this->c > other.c;
    }
};
 
int main()
{
    lint N, M;
    cin >> N >> M;
    vector<lint> A(N);
    rep (i, N)
    {
        cin >> A[i];
    }
    vector<lint> B(M);
    vector<lint> C(M);
    vector<BC> BCs;
    rep (i, M)
    {
        cin >> B[i] >> C[i];
        BCs.push_back(BC(B[i], C[i]));
    }
 
 
    std::sort(ALL(A));
    std::sort(ALL(BCs), std::greater<BC>());
    rep (i, M)
    {
        rep (k, BCs[i].b)
        {
            if (A[k] < BCs[i].c)
            {
                A[k] = BCs[i].c;
            }
            else
            {
                break;
            }
        }
        std::sort(ALL(A));
    }
 
    lint sum = 0;
    rep (i, N)
    {
        sum += A[i];
    }
 
    cout << sum << endl;
 
    
    return 0;
}
