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


int main()
{
    lint L, R;
    cin >> L >> R;

    int mL = L % 2019;
    int mR = R % 2019;
    lint minimum = 2019;
    for (lint i = mL; i < mR; ++i)
    {
        for (int k = i+1; k <= mR; ++k)
        {
            if(chmin(minimum, (i*k) % 2019)) 
            {
                break;
            }
        }
    }

    cout << minimum << "\n";

    return 0;
}
