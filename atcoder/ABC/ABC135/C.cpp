# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define TO_STRING(x) #x
# define debug(x) {cerr<<#x<<": "<<(x)<<"\n";}
# define Nmax (100000)
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;


int main()
{
    lint N;
    cin >> N;
    vector<lint> A(N+1);
    vector<lint> B(N);

    rep (i, N+1)
    {
        cin >> A[i];
    }
    rep (i, N)
    {
        cin >> B[i];
    }

    lint cnt = 0;
    rep (i, N)
    {
        if (A[i] - B[i] == 0)
        {
            cerr << "root A" << endl;
            cnt += A[i];
            A[i] = 0;
            B[i] = 0;
        }
        else if (A[i] - B[i] < 0)
        {
            cerr << "root B" << endl;
            cnt += A[i];
            cerr << cnt << endl;
            B[i] = B[i] - A[i];
            A[i] = 0;
        }
        else // A[i] > B[i]
        {
            cerr << "root C" << endl;
            lint tmp = B[i];
            cnt += tmp;
            A[i] = tmp;
            B[i] = 0;
        }
    }
    rep (i, N)
    {
        if (A[i+1] - B[i] == 0)
        {
            cnt += A[i+1];
            A[i+1] = 0;
        }
        else if (A[i+1] - B[i] < 0)
        {
            cnt += A[i+1];
            A[i+1] = 0;
        }
        else
        {
            cnt += B[i];
            A[i+1] = A[i+1] - B[i];
        }
    }

    cout << cnt << endl;

    return 0;
}
