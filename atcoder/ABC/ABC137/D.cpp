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
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

using Work = pair<lint, lint>;

int main()
{
    lint N, M;
    cin >> N >> M;
    vector<Work> W(N);
    rep (i, N)
    {
        lint A, B;
        cin >> A >> B;
        if (!(A > M))
        {
            W[i] = make_pair(A, B);
        }
    }

    sort(ALL(W));

    vector<vector<lint>> mp(M+1);
    lint tmp = W[0].first;
    vector<lint> vtmp;
    for (lint i = 0; i < SZ(W); ++i)
    {
        if (tmp == W[i].first)
        {
            vtmp.push_back(W[i].second);
        }
        else
        {
            mp[tmp] = vtmp;
            debug(vtmp.size());
            tmp = W[i].first;
            vtmp.clear();
            vtmp.push_back(W[i].second);
        }
    }
    mp[tmp] = vtmp;
    for (lint i = 0; i < mp.size(); ++i)
    {
        debug(SZ(mp[i]));
    }
    vector<lint> now;
    lint ans = 0;
    for (lint day = 1; day <= M; ++day)
    {
        vector<lint> tmp = mp[day];
        now.insert(now.end(), tmp.begin(), tmp.end());
        rep (i, now.size()) {cerr<<now[i]<<endl;}
        sort(RALL(now));
        if (!now.empty())
        {
            ans += now[0];
            now[0] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
