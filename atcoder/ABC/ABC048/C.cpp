# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    optimize_cin();
 
    lint N; cin >> N;
    lint x; cin >> x;
    vector<lint> a(N);
    rep (i, N) { cin >> a[i]; }
 
    lint cnt = 0;
 
    if (a[0] > x)
    {
        cnt += a[0] - x;
        a[0] = x;
    }
    for (lint i = 0; i < N - 1; ++i)
    {
        bool flag = true;
        while (a[i] + a[i+1] > x)
        {
            if (flag)
            {
                cnt += a[i+1] - (x - a[i]);
                a[i+1] = x - a[i];
            }
            else 
            {
                cnt += a[i] - (x - a[i+1]);
                a[i] = x - a[i+1];
            }
            flag = false;
        }
    }
 
    cout << cnt << "\n";
 
    return 0;
}
