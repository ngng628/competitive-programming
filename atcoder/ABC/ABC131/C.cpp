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

lint func(lint A, lint B, lint R)
{
    lint Qa = A % R;
    lint Qb = B % R;

    lint range;
    if (Qa == 0)
    {
        range = B - Qb - A;
    }
    else if(A < R)
    {
        range = 0;
    }
    else
    {
        range = B - Qb - (A - Qa + R);
    }

    return (B - A) - range / R;
}

int main()
{
    lint A, B, C, D;
    cin >> A >> B >> C >> D;

    lint cnt = 0;
    if (B < C)
    {
        if (B < D)
        {
            cout << 0 << "\n";
            return 0;
        }
    }
    cnt += func(A, B, C);
    cnt += func(A, B, D);
    cnt -= func(A, B, C*D);

    cout << cnt << "\n";


    return 0;
}
